
//Libreria para control de motores
#include <l298n.h>

//Constructor del objeto "motores"
l298n motores(10,8,9,12,13,11);

//Variables para declarar donde esta conectado cada sensro
//    Izquierda                                   Derecha
//      -----------------------------------------------
//     |                                               |
//     |      s4      s3               s2      s1      |
//     |                                               |
//      -----------------------------------------------

int s1 = 4;
int s2 = 5;
int s3 = 6;
int s4 = 7;


//Velocidad base para el desplazamiento del robot
int vel_base = 90;


void setup() {
  // put your setup code here, to run once:

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:



  if(digitalRead(s1) || digitalRead(s2))
    {
      motores.write(vel_base,-vel_base);
    }
  else if(digitalRead(s3) || digitalRead(s4))
    {
      motores.write(-vel_base,vel_base);
    }
    else
    {
        motores.write(vel_base,vel_base);
    }


}
