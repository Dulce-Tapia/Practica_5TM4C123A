#include "lib/include.h"

/* EXPERIMENTO 1
   Usando el modulo 0 de PWM con una frecuencia de reloj del sistema de 50,000,000 Hz
   junto con el generador 1  habilitar alguno de los pwm's asociados y obtener un PWM
   cuya frecuencia sea de 10KHz */

int main(void)
{
   
    Configurar_PLL(_50MHZ); //Experimento 1
    Configura_Reg_PWM0(8); //Configuro a 10kHz el pwm Experimento 1
    
    while(1)
    { 
        
    }
}
