#include <l298n.h>

  l298n motores(10,8,9,12,13,11);

int s1 = 4;
int s2 = 5;
int s3 = 6;
int s4 = 7;

//Variables PID
int P = 0;
int I = 0;
int D = 0;

int kp = 0.001;
int ki = 0.008;
int kd = 10;

int p_ant = 0;
int u = 0;

int v_base = 120; //0 - 255
int velatras = 255;
int veladelante = 255;

int veli = 0;
int veld = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

}

void loop() 
{
  // put your main code here, to run repeatedly:

  P = digitalRead(s4)*(-2000) + digitalRead(s3)*(-1000) + digitalRead(s2)*(1000) + digitalRead(s1)*(2000);
  I = I + P;
  D = P - p_ant;
  p_ant = P;

  u = (kp*P) + (ki*I) + (kd*D);

  

   if(u < -v_base)
  {
    u = -v_base;
  }
  else if (u > v_base)
  {
    u = v_base;
  }

   if (P < 0)
  {
    motores.write(-velatras+u,veladelante-u);
    
  }
   else if ( P == 0)
   {

     motores.write(v_base,v_base);
    
   }
  else if (P > 0)
  {
    
    motores.write(veladelante-u,-velatras+u);
    
  }

}