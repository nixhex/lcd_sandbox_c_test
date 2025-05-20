#include "lcd.h"
#define MIN(x, y) (x > y ? y : x)
#define MAX(x, y) (x > y ? x : y)

const LcdCharMap lcd_map[] = ADM2004D_FL_YBS_CHAR_MAP;

void newLCD(LCD* lcd, LcdCharMap charMap[], GPIO_TypeDef GPIOs[], GPIO_TypeDef pins[])
{
	lcd->charMap = charMap;
	lcd->GPIOs = GPIOs;
	lcd->pins = pins;
}

void Send_CMD(LCD* lcd, uint16_t cmd)
{
	for (int n = 0; n < NUM_CMD_BITS; n++)
	{
		printf("HAL_GPIO_WritePin(%s, %s, %s);\n", lcd->GPIOs[n], lcd->pins[n], STATE(BIT(cmd, NUM_CMD_BITS - 1 - n)));
	}
}

void printBinary(uint16_t cmd)
{
	printf("0b");
	for (int n = 0; n < NUM_CMD_BITS; n++)
	{
		printf("%d", BIT(cmd, NUM_CMD_BITS - n - 1));
	}
	printf("\n");
}

void Write_Char_DDRAM(LCD *lcd, char ch)
{
	uint16_t command = GetLcdCode(ch);
	// generate command
	// upper two bits: control RS=1, RW=0
	command |= 1 << RS_BIT; // Set RS bit
	command &= ~(1 << RW_BIT); // Clear RW bit
	printf("Sending character %c:\n", ch);
	printf("=====================\n");
	Send_CMD(lcd, command); // since lcd is already a pointer, don't dereference or else you're sending a LCD**
	printf("\n");
}

uint8_t GetLcdCode(char ch)
{
	for (size_t i = 0; i < LCD_MAP_SIZE; i++) {
		if (lcd_map[i].ascii == ch)
			return lcd_map[i].lcd_code;
	}
	return 0x20; // Fallback to space if not found
}

void Write_String(LCD* lcd, char* str, uint8_t row, uint8_t col)
{
	uint32_t len = MIN(strlen(str), NUM_COLS);
	printf("Printing string first %d characters of %s\n", len, str);
	for (int n = 0; n < len; n++)
	{
		//Move_Cursor(startRow, startRow + n);
		Write_Char_DDRAM(lcd, str[n]); // since lcd is already a pointer, don't dereference or else you're sending a LCD**
	}
}

void Move_Cursor(int row, int col)
{
	printf("Cursor moving to row %d column %d\n", row, col);
}