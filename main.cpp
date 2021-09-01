#include "mbed.h"

#define ENABLE_LCD_DEMO

#ifdef ENABLE_LCD_DEMO
#include "lcd_api.h"
#endif

DigitalOut led1(LED1);

int main()
{
    int i = 0;

    printf("Start program ...\r\n");
#ifdef ENABLE_LCD_DEMO
    printf("Enable LCD program ...\r\n");
    lcd_init();
#endif

    while (true) {
        printf("blinking: %d\r\n", i++);
        led1 = !led1;
        ThisThread::sleep_for(500);
#ifdef ENABLE_LCD_DEMO
        lcd_printNumber(i);
#endif
    }
}
