#include <l298n.h>

  l298n motores(10,8,9,12,13,11);

int s1 = 4;
int s2 = 5;
int s3 = 6;
int s4 = 7;

void setup() {
  // put your setup code here, to run once:

  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  motores.write(255,255);

  if(digitalRead(s1) || digitalRead(s2))
    {
      motores.write(255,-255);
    }
  else if(digitalRead(s3) || digitalRead(s4))
    {
      motores.write(-255,255);
    }


}
