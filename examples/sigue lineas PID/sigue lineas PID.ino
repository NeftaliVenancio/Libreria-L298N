#include <l298n.h>

  l298n motores(10,8,9,12,13,11);

int s1 = 4;
int s2 = 5;
int s3 = 6;
int s4 = 7;

//Variables PID
int P = 0.18;
int I = 0.001;
int D = 4;

int kp = 5;
int ki = 0;
int kd = 0;

int p_ant = 0;
int u = 0;

int v_base = 200; //0 - 255
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

  P = digitalRead(s4)*(-200) + digitalRead(s3)*(-100) + digitalRead(s2)*(100) + digitalRead(s1)*(200);
  I = I + P;
  D = P - p_ant;
  p_ant = P;

  u = (kp*P) + (ki*I) + (kd*D);

  veli = v_base + u;
  veld = v_base - u;

  if(veli >= v_base)
  {
    veli =  v_base;
  }
  else if(veli < -v_base)
  {
    veli =  -v_base;
  }

  if(veld >= v_base)
  {
    veld =  v_base;
  }
  else if(veld < -v_base)
  {
    veld =  -v_base;
  }

  motores.write(veli, veld);

}