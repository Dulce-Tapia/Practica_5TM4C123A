#include "lib/include.h"

extern void Configura_Reg_PWM0(uint16_t freq)
{
    //Experimento 1 
    //Habilitar el reloj de modulo PWM0 pag 354
    SYSCTL->RCGCPWM |= (1<<0); 
    //Habilitar el reloj de GPIO Puerto B pag 340 pin 5 (PWM3)
    SYSCTL->RCGCGPIO |= (1<<1); 
    //Habilitar el divisor del reloj PWM pag 254 Nota *No es necesario 
    SYSCTL -> RCC &= ~(1<<20); 
    // Habilitar función alternativa  Control de registros ya sea por GPIO o Otros Pag 672
    GPIOB_AHB->AFSEL |= (1<<5);  //PB5
    //Combinado con la tabla Pag 1351 y el registro PCTL le digo que es pwm Pag 689
    // 4 indica que es PWM 
    GPIOB_AHB->PCTL |= (GPIOB_AHB->PCTL&0xFF0FFFFF) | 0x00400000; 
    // Salida de PWM 
    GPIOB_AHB->DIR |= (1<<5);
    // para decirle si es digital o no Pag 682
    GPIOB_AHB->DEN |= (1<<5); 
    //Bloqueo y desbloqueo pag 1266, pag 1233 generadores de PWM 
    PWM0->_1_CTL = (0<<0);   
    //Pag 1248  PWM3 trabaja con comparador B que es el utilizado en el pin B5
    PWM0->_1_GENB = 0x0000080C; // pag 1285
    //cuentas=fclk/fpwm  para 1khz cuentas = (50,000,000/10000)
    PWM0->_1_LOAD = (int)(50000000/freq); 
    PWM0->_1_CMPB = 1500; //Ciclo de trabajo Nota *Regla de 3
    // Se activa el generador 1
    PWM0->_1_CTL = (1<<0);
    // habilitar el PWM3 trabaja con comparador B que es el utilizado en el pin B5
    //pag 1248
    PWM0->ENABLE = (1<<3); 
}
