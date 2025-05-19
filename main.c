#include <stdio.h>
#include <stdint.h>
#include "lcd.h"
#include <string.h>


int main(void)
{
	char* GPIOs[] = {
		  "LCD_RS_GPIO_Port",
		  "LCD_RW_GPIO_Port",
		  "LCD_DB7_GPIO_Port",
		  "LCD_DB6_GPIO_Port",
		  "LCD_DB5_GPIO_Port",
		  "LCD_DB4_GPIO_Port",
		  "LCD_DB3_GPIO_Port",
		  "LCD_DB2_GPIO_Port",
		  "LCD_DB1_GPIO_Port",
		  "LCD_DB0_GPIO_Port"
	};

	char* pins[] = {
		  "LCD_RS_Pin",
		  "LCD_RW_Pin",
		  "LCD_DB7_Pin",
		  "LCD_DB6_Pin",
		  "LCD_DB5_Pin",
		  "LCD_DB4_Pin",
		  "LCD_DB3_Pin",
		  "LCD_DB2_Pin",
		  "LCD_DB1_Pin",
		  "LCD_DB0_Pin"
	};

	char* str = "hello!";
	//printf("sending string \"%s\"\n", str);
	Write_String(GPIOs, pins, str);

	return 0;
}