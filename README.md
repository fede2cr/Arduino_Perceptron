# Arduino_Perceptron
Un perceptrón programado para aprendiaje mecánico en Arduino, adaptado para
Adafruit Playground y su sensor de luz en modo de sensor de color, para
ser utilizado en talleres educativos en Greencore Solutions.

Por como trabaja el sensor de color se tuvo que modificar para que solo lea
un color cuando se le indique presionando los botones.

Uso:

1. Cuando inicia presenta una luz blanca para indicar que se encuentra listo
2. Se coloca un objeto encima del sensor de luz, y se preciona cualquiera de
   los botones
3. El Playground lee los colores, y trata de adivinar si conoce el color. Color
   verde para "Match", y color rojo para "No Match".
4. En este momento le indicamos al Playgroud si su adivinanza fue correcta.
   En esta versión de le indica usando los botones izquierdo para correcto, y
   derecho para incorrecto.
5. El Playground se encuentra listo para leer más colores cuando presionemos
   los botones

TODO:
- Utilizar la inclinación para indicar valores a entrenar en lugar de los 
  botones

MIT License

Original work Copyright (c) 2016 Tomas de-Camino-Beck
Modified work Copyright 2016 Greencore Solutions SLR

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
