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

int kp = 0;
int ki = 0;
int kd = 0;

int p_ant = 0;
int u = 0;

int v_base = 100; //0 - 255

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

  P = digitalRead(s4)*(-2) + digitalRead(s3)*(-1) + digitalRead(s2)*(1) + digitalRead(s1)*(2);
  I = I + P;
  D = P - p_ant;
  p_ant = P;

  u = (kp*P) + (ki*I) + (kd*D);

  motores.write(v_base - u, v_base + u);

}