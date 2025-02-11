#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

//Pinos:
const uint pin_22 = 22; //Servo motor
const uint led_azul = 12; //LED azul do RGB

//Protótipos das funções:
void pwm_setup();
int64_t alarm_callback_pwm(alarm_id_t id, void *user_data);


//Variáveis globais:
uint32_t wrap = 19999;
const float divisor = 125.0;
uint16_t grau_0 = 500;
uint16_t grau_90 = 1467;
uint16_t grau_180 = 2399;
volatile uint16_t incremento = 5;
bool rise = true;




int main()
{   pwm_setup();//PWM configurado
    stdio_init_all();

    pwm_set_gpio_level(pin_22,grau_180); //O servo motor vai para 180°
    pwm_set_gpio_level(led_azul,grau_180); //O LED azul possui as mesmas configurações 
    sleep_ms(5000);
    pwm_set_gpio_level(pin_22,grau_90); //O servo motor vai para 90°
    pwm_set_gpio_level(led_azul,grau_90); 
    sleep_ms(5000);
    pwm_set_gpio_level(pin_22,grau_0); //O servo motor vai para 0°
    pwm_set_gpio_level(led_azul,grau_0);
    
    add_alarm_in_ms(5000,alarm_callback_pwm,NULL,false);


    while (true) {
        sleep_ms(1000);
    }
}




void pwm_setup(){

    gpio_set_function(pin_22,GPIO_FUNC_PWM); //Habilita a função de PWM no pino 22
    gpio_set_function(led_azul,GPIO_FUNC_PWM); //Habilita a função de PWM no LED azul

    uint slice = pwm_gpio_to_slice_num(pin_22); //Slice do servo motor
    uint slice_led = pwm_gpio_to_slice_num(led_azul); //Slice do LED azul
    //SERVO MOTOR:
    pwm_set_clkdiv(slice,divisor); //Define o divisor para 125.0
    pwm_set_wrap(slice,wrap); //Define o wrap para 19999 com essa configuração obtenho 50 hz do PWM
    pwm_set_gpio_level(pin_22,grau_180); //Inicializa nessa posição o servo motor (180° que é o máximo)
    pwm_set_enabled(slice,true);// Habilito o PWM
    //LED RGB AZUL:
    pwm_set_clkdiv(slice_led,divisor); //Também possui o divisor de 125.0
    pwm_set_wrap(slice_led,wrap); //Possui o mesmo wrap (19999)
    pwm_set_gpio_level(slice_led,grau_180); //Inicia com nivel máximo
    pwm_set_enabled(slice_led,true); //Ativa o PWM para o LED

    
}
int64_t alarm_callback_pwm(alarm_id_t id, void *user_data){
    if(rise){ //Aumenta o nivel
        pwm_set_gpio_level(pin_22,grau_0+incremento); //Altera o nível do servo motor
        pwm_set_gpio_level(led_azul,grau_0+incremento); //Altera o nível do LED

        if(incremento+grau_0 >= grau_180){//Se chegar no 180 muda de estado
            rise = false; //Faz descer
            incremento=5; //Retorna o valor inicial do incremento
        }
    }
    else{//Abaixa o nivel
        pwm_set_gpio_level(pin_22,grau_180-incremento); //Altera o nível do servo motor
        pwm_set_gpio_level(led_azul,grau_180-incremento); //Altera o nível do LED
        
        if(grau_180-incremento<=grau_0){
            rise = true; //Volta a subir
            incremento=5; //Atualiza o incremento novamente
        }
    }
    incremento+=5; // Incrementa de 5 em 5
    return 11000; //Retorna a função com 11ms
}