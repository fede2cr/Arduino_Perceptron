// Código original para Arduino UNO por Tomas de camino Beck
// Modificado por Alvaro Figueroa para Adafruit Playground
// Released under MIT License
// Copyright (c) 2016 Tomas de-Camino-Beck

#include "Perceptron.h"
#include "Adafruit_CircuitPlayground.h"

uint8_t clear, red, green, blue ;
bool training = false;

//we will use one perceptron with 3 inputs (Red, green, blue)
perceptron colorPerceptron(4);//fourth is for bias

void setup() {

  CircuitPlayground.begin();
  Serial.begin(115200);

  randomSeed(A6);
  colorPerceptron.randomize();//weight initialization

  // Flash inicial en color blanco para indicar que se encuentra listo
  CircuitPlayground.clearPixels();
  for (int i=0; i<10; ++i) {
    CircuitPlayground.strip.setPixelColor(i, 255, 255, 255);
  }
  CircuitPlayground.strip.show();
  delay(500);
  CircuitPlayground.clearPixels();


}

void loop() {
  float guess;
  
  // Lee si se presionan los botones
  bool left_first = CircuitPlayground.leftButton();
  bool right_first = CircuitPlayground.rightButton();
  delay(20);
  bool left_second = CircuitPlayground.leftButton();
  bool right_second = CircuitPlayground.rightButton();


  // Cualquiera de los dos botones activa la lectura
  if ((left_first && !left_second) || (right_first && !right_second))  {

    if (!training) {
      CircuitPlayground.senseColor(red, green, blue);
      Serial.print("Color: red=");
      Serial.print(red, DEC);
      Serial.print(" green=");
      Serial.print(green, DEC);
      Serial.print(" blue=");
      Serial.println(blue, DEC);
      colorPerceptron.inputs[0] = red;
      colorPerceptron.inputs[1] = green;
      colorPerceptron.inputs[2] = blue;

      guess = colorPerceptron.feedForward();
   
      if (guess == 1) {
        Serial.println("Match");
        for (int i=0; i<10; ++i) {
          CircuitPlayground.strip.setPixelColor(i, 0, 255, 0);
        }
        CircuitPlayground.strip.show();
        delay(2000);
        CircuitPlayground.clearPixels();
      } else {
        Serial.println("No Match");
        for (int i=0; i<10; ++i) {
          CircuitPlayground.strip.setPixelColor(i, 255, 0, 0);
        }
        CircuitPlayground.strip.show();
        delay(2000);
        CircuitPlayground.clearPixels();
      }  
      Serial.println("Activando modo entrenamiento");
      training = true;
      } else {
        if (left_first && !left_second) {
          colorPerceptron.train(1, guess);
          Serial.println("Se entrena a correcto");
          for (int i=0; i<5; ++i) {
            CircuitPlayground.strip.setPixelColor(i, 0, 255, 0);
          }
          CircuitPlayground.strip.show();
          delay(1000);
          CircuitPlayground.clearPixels();
        }
        if (right_first && !right_second) {
          colorPerceptron.train(-1, guess);
          Serial.println("Se entrena a fallo");
          for (int i=5; i<10; ++i) {
            CircuitPlayground.strip.setPixelColor(i, 255, 0, 0);
          }
          CircuitPlayground.strip.show();
          delay(1000);
          CircuitPlayground.clearPixels();
        }
        training = false;
        Serial.println("Desactivando entrenamiento");
    }
    
  } 
}
