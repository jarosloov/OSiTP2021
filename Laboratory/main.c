/*
 * Copyright (C) 2015 Kaspar Schleiser <kaspar@schleiser.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       example application for setting a periodic wakeup
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 *
 * @}
 */

#include <stdio.h>
#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"

/* set interval to 1 second */
#define INTERVAL1 (1U * US_PER_SEC * 0.2)
#define INTERVAL2 (2U * US_PER_SEC * 0.2)

int main(void)
{
    gpio_init(GPIO_PIN(PORT_C, 8), GPIO_OUT);
    gpio_init(GPIO_PIN(PORT_C, 9), GPIO_OUT);
    xtimer_ticks32_t last_wakeup1 = xtimer_now();
    xtimer_ticks32_t last_wakeup2 = xtimer_now();

    while(1) {
        xtimer_periodic_wakeup(&last_wakeup1, INTERVAL1);
        gpio_toggle(GPIO_PIN(PORT_C, 9));
		    xtimer_periodic_wakeup(&last_wakeup2, INTERVAL2);
        gpio_toggle(GPIO_PIN(PORT_C, 8));
    }
    return 0;
}

