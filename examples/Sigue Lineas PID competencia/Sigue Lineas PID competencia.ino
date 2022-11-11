//Funciona con la pista bien calibrada al 100% de velocidad en los motores

int P = 0;
int P_ant = 0;

int e1,e2,e3,e4,e5,e6;

int I = 0;
int D = 0;

int U = 0;

//Motor 3000rpm
// int kp = 0.0009;
// int ki = 0.0001;
// int kd = 12;


 int kp = 0.0002;
 int ki = 0.0008;
 int kd = 10;


// Motor 10000rpm
//int kp = 0.00016;
//int ki = 0.015;//0.002;
//int kd = 4;//4;

int v_base = 120;
int veladelante = 250;
int velatras = 250;

int pwmd = 6;
int md1 = 7;
int md2 = 4;

int pwmi = 5;
int mi1 = 13;
int mi2 = 3;



// void derecha()
// {
//   analogWrite(pwmi, v_base-abs(U));
//   digitalWrite(mi, LOW);
//   analogWrite(pwmd,255;
//   digitalWrite(md, HIGH);
// }

// void izquierda()
// {
//   analogWrite(pwmd, v_base-U);
//   digitalWrite(md, LOW);
//   analogWrite(pwmi,255);
//   digitalWrite(mi, HIGH);
// }

void motores( int izq, int der)
{
  //Motor izquierdo
  if (izq >= 0)
  {
    digitalWrite(mi1,HIGH);
    digitalWrite(mi2,LOW);
  }
  else
  {
    digitalWrite(mi1,LOW);
    digitalWrite(mi2,HIGH);
    izq = (-1)*(izq);
  }
  analogWrite(pwmi,izq);

  //Motor derecho
  if (der >= 0)
  {
    digitalWrite(md1,HIGH);
    digitalWrite(md2,LOW);
  }
  else
  {
    digitalWrite(md1,LOW);
    digitalWrite(md2,HIGH);
    der = (-1)*der;
  }

  
  analogWrite(pwmd,der);

}

// void avanzar()
// {
  // analogWrite(pwmi, 255);
  // digitalWrite(mi1,HIGH);
  // digitalWrite(mi2,LOW);

  // analogWrite(pwmd, 150);
  // digitalWrite(md1,HIGH);
  // digitalWrite(md2,LOW);
// }

// void retroceder()
// {
  // analogWrite(pwmi, 255);
  // digitalWrite(mi1,LOW);
  // digitalWrite(mi2,HIGH);

  // analogWrite(pwmd, 150);
  // digitalWrite(md1,LOW);
  // digitalWrite(md2,HIGH);

// }

// void frenoI()
// {
//   analogWrite(pwmi,0);
//   digitalWrite(mi, HIGH);
//   analogWrite(pwmd,255);
//   digitalWrite(md, LOW);
// }

// void frenoD()
// {
//   analogWrite(pwmi,255);
//   digitalWrite(mi, LOW);
//   analogWrite(pwmd,0);
//   digitalWrite(md, HIGH);
// }

 void frenos(){
  
  if(P <= -5000)
  {
    motores(-velatras, veladelante);
  }
  
  if (P >= 5000)
  {
    motores(veladelante, -velatras);
    
  }
  
}

void setup() {
  // put your setup code here, to run once:
  //attachInterrupt(digitalPinToInterrupt(2),derecha,LOW);
  //attachInterrupt(digitalPinToInterrupt(3),izquierda,LOW);
  
  DDRB = 0b00000000;
  DDRC = 0b00000000;  
  pinMode(mi1,OUTPUT);
  pinMode(mi2,OUTPUT);
  pinMode(md1,OUTPUT);
  pinMode(md2,OUTPUT);
  
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);

  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pinMode(16,INPUT);
  pinMode(17,INPUT);
  pinMode(18,INPUT);
  pinMode(19,INPUT);

  Serial.begin(9600);

  while(!digitalRead(2))
  {
    
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  frenos();

  P = (-1)*( bitRead(PINC,4)*(-5000) + bitRead(PINC,3)*(-4000) + bitRead(PINC,2)*(-3000) + bitRead(PINC,1)*(-2000) + bitRead(PINC,0)*(-1000) + bitRead(PINB,4)*(5000) + bitRead(PINB,3)*(4000) + bitRead(PINB,2)*(3000) + bitRead(PINB,1)*(2000) + bitRead(PINB,0)*(1000));

   //if ( P == 0 && P_ant != 0)
   //{
    //P = P_ant; 
  //}

  I =e1 + e2 + e3 + e4 + e5 + e6;

  if ((P * I) < 0) {
    I = 0;
  }

  D = P - P_ant;

  e6 = e5;
  e5 = e4;
  e4 = e3;
  e2 = e1;
  e1 = P;

  P_ant = P;

  U = (kp * P) + (ki * I) + (kd * D);
  // Serial.println(P);
  // analogWrite(pwmi, v_base - U);
  // digitalWrite(mi, LOW);
  // analogWrite(pwmd, (v_base + U));
  // digitalWrite(md, LOW);


  if(U < -v_base)
  {
    U = -v_base;
  }
  else if (U > v_base)
  {
    U = v_base;
  }

  // if ( U < 0)
  //  {
  //    motores(veladelante, v_base-U);
  //  }
  //  else
  //  {
  //    motores(v_base+U , veladelante);
  //  }


  //motores(v_base-U,v_base+U);


  // if (P < 0)
  // {
  //   motores(v_base+U,-velatras);
  // }
  //  else if ( P == 0)
  //  {

  //    motores(v_base,v_base);
    
  //  }
  // else if (P > 0)
  // {
  //   motores(-velatras,v_base-U);
  // }

    if (P < 0)
  {
    motores(-velatras+U,veladelante-U);
    
  }
   else if ( P == 0)
   {

     motores(v_base,v_base);
    
   }
  else if (P > 0)
  {
    
    motores(veladelante-U,-velatras+U);
    
  }

  Serial.println(P);

}