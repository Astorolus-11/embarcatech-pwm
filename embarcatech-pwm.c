#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

//Pinos:
const uint pin_22 = 22; //Servo motor
const uint led_azul = 12; //LED azul

//Protótipos das funções:
void pwm_setup();

//Variáveis globais:
uint32_t wrap = 9803;
const float divisor = 255.0;



int main()
{   pwm_setup();
    stdio_init_all();

    while (true) {
        
    }
}
void pwm_setup(){

    gpio_set_function(pin_22,GPIO_FUNC_PWM); //Habilita a função de PWM no pino 22
   // gpio_set_function(led_azul,GPIO_FUNC_PWM); //Habilita a função de PWM no LED azul
    uint slice = pwm_gpio_to_slice_num(pin_22);
    pwm_set_clkdiv(slice,divisor); //Define o divisor para 255.0
    pwm_set_wrap(slice,wrap); //Define o wrap para 9803, com essa configuração obtenho 50 hz do PWM
    pwm_set_enabled(slice,true);// Habilito o PWM

    
}