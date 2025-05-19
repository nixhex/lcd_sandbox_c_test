#include "lcd.h"

const LcdCharMap lcd_map[] = LCD2004_CHAR_MAP;

void Send_CMD(char** GPIOs, char** pins, uint16_t cmd)
{
	for (int n = 0; n < NUM_CMD_BITS; n++)
	{
		printf("HAL_GPIO_WritePin(%s, %s, %s);\n", GPIOs[n], pins[n], STATE(BIT(cmd, NUM_CMD_BITS - 1 - n)));
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

void Write_Char_DDRAM(char** GPIOs, char** pins, uint8_t ch)
{
	uint16_t command = GetLcdCode(ch);
	// generate command
	// upper two bits: control RS=1, RW=0
	command |= 0b000000001000000000; // set bit 9 (RS)
	command &= 0b111111111011111111; // clear bit 8 (RW)
	printf("Sending character %c:\n", ch);
	printf("=====================\n");
	Send_CMD(GPIOs, pins, command);
	printf("\n");
	//printf("done sending %c\n", ch);
	//printf("=====================\n");

}

uint8_t GetLcdCode(char ch)
{
	for (size_t i = 0; i < LCD_MAP_SIZE; i++) {
		if (lcd_map[i].ascii == ch)
			return lcd_map[i].lcd_code;
	}
	return 0x20; // Fallback to space if not found
}

void Write_String(char** GPIOs, char** pins, char* str)
{
	uint32_t len = strlen(str);
	printf("Printing string %s\n", str);
	for (int n = 0; n < len; n++)
	{
		/* 
		move cursor code
		*/
		Write_Char_DDRAM(GPIOs, pins, str[n]);
	}
}