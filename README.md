# Driver L298N

Libreria para control bidireccional de motores usando el driver l298n

///Funciones
Constructor: - l298n(int ena, int in11, int in2, int in3, int in4, int enb);
    donde   in1, in2, in3, in4: corresponde a los pines para control de dirección en el modulo
                Motor izquierdo - in1 e in2
                Motor Derecho - in3 e in4
            
            ena/enb: corresponde a los pines para control de velocidad para cada motor
                ena - Control de velocidad para motor izquierdo
                enb - Control de velocidad para motor derecho
    
Funciones:
            wirte(): Funcion que escribe la dirección y velocidad de giro de ambos motores
                    write(izq,der);

                    izq/der < 0 - Retroceder a la velocidad indicada.        
                    izq/der > 0 - Avanzar a la velocidad indicada.