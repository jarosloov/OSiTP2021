// Подключение библиотек 

#include "xtimer.h" 

#include "timex.h" 

#include "periph/gpio.h" 

  

// Макрос для интервала времени, в течение которого трэд будет спать 

//#define INTERVAL 1000000 

#define INTERVAL_1 (1U * US_PER_SEC * 0.5)  

#define INTERVAL_2 (1U * US_PER_SEC * 1)  

  

  

int main(void) 

{ 

  xtimer_ticks32_t last_wakeup = xtimer_now(); 

  gpio_init(GPIO_PIN(PORT_C, 8), GPIO_OUT); 

  gpio_init(GPIO_PIN(PORT_C, 9), GPIO_OUT); 

  gpio_toggle(GPIO_PIN(PORT_C, 8)); 

  

    while(1) { 

      gpio_toggle(GPIO_PIN(PORT_C, 8)); 

      gpio_toggle(GPIO_PIN(PORT_C, 9)); 

      xtimer_periodic_wakeup(&last_wakeup, INTERVAL_2);  

    } 

    return 0; 

} 

  

/*  

Задание 1. Установите интервал переключения светодиода на 0.5 секунды. 

Задание 2. Сделайте так, чтобы вместо одного светодиода моргал другой. 

Задание 3. Сделайте так, чтобы светодиоды моргали попеременно - один выключился, другой включился. 

*/ 
