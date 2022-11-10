#include <l298n.h>

l298n motores(10,8,9,12,13,11);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

motores.write(-205,205);

}
