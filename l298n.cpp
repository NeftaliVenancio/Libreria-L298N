
/*
  Driver_L298N.h - Libreria para el control de motores usando el driver L298N
  Creada por Neftali Venancio, Noviembre 9, 2022.
  Released into the public domain.
*/

#include "Arduino.h"
#include "l298n.h"

l298n::l298n(int enb, int in4, int in3, int in2, int in1, int ena)
{
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  

  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;
  _ena = ena;
  _enb = enb;

}


void l298n::write(int izq, int der)
{

//Motor izquierdo
  if (izq >= 0)
  {
    digitalWrite(_in1,HIGH);
    digitalWrite(_in2,LOW);
  }
  else
  {
    digitalWrite(_in1,LOW);
    digitalWrite(_in2,HIGH);
    izq = (-1)*(izq);
  }
  analogWrite(_ena,izq);

  //Motor derecho
  if (der >= 0)
  {
    digitalWrite(_in3,HIGH);
    digitalWrite(_in4,LOW);
  }
  else
  {
    digitalWrite(_in3,LOW);
    digitalWrite(_in4,HIGH);
    der = (-1)*der;
  }

  
  analogWrite(_enb,der);

}
