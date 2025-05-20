#include <stdio.h>
#include <stdint.h>
#include "lcd.h"
#include "gpioconsts.h"
#include <string.h>


int main(void)
{
	GPIO_TypeDef GPIOs[] = ADM2004D_FL_YBS_GPIOS;
	GPIO_TypeDef pins[] = ADM2004D_FL_YBS_PINS;
	LcdCharMap lcdMap[] = ADM2004D_FL_YBS_CHAR_MAP;

	LCD lcd;
	
	newLCD(&lcd, lcdMap, GPIOs, pins);

	char* str = "yello, world!";
	Write_String(&lcd, str, 0, 0);
	return 0;
}