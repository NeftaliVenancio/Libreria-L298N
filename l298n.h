
/*
  Driver_L298N.h - Libreria para el control de motores usando el driver L298N
  Creada por Neftali Venancio, Noviembre 9, 2022.
  Released into the public domain.
*/


/////////////////////////////////////////////////////////////////
/////
/////   
/////
////////////////////////////////////////////////////////////////

#ifndef l298n_h
#define l298n_h

#include "Arduino.h"
 

class l298n
{
        public:
                l298n(int enb, int in4, int in3, int in2, int in1, int ena);

                void write( int izq, int der);
                void fordward(int vel);
                void backward(int vel);
                void read(int m);

        private:
                
                int _ena;
                int _in1;
                int _in2;
                int _in3;
                int _in4;
                int _enb;
};
#endif