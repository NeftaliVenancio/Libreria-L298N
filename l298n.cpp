/*
  7 segmentos.h - Library for display of seven segments
  Created by Neftali Venancio, October 22, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "dis7seg.h"

l298n::l298n(int ena, int in11, int in2, int in3, int in4, int enb);
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
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else
  {
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    izq = (-1)*(izq);
  }
  analogWrite(ena,izq);

  //Motor derecho
  if (der >= 0)
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else
  {
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    der = (-1)*der;
  }

  
  analogWrite(enb,der);

}
