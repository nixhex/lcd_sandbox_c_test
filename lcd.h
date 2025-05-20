#ifndef INC_LCD_H_
#define INC_LCD_H_
#include <stdint.h>
#include <stdio.h>
#include "gpioconsts.h"

#define BIT(x, n) (x >> n & 0b1)
#define STATE(s) (s == 1 ? "GPIO_PIN_SET" : "GPIO_PIN_RESET")
#define LCD_MAP_CHAR(ascii, code) { (ascii), (code) }
#define LCD_MAP_SIZE (sizeof(lcd_map) / sizeof(LcdCharMap))
#define RS_BIT 9
#define RW_BIT 8
#define NUM_ROWS 4
#define NUM_COLS 20

// ST7066U, KS0066, or any HD44780-compatible controller DDE
#define DDRAM_ROW1_START 0x00
#define DDRAM_ROW1_END   0x13
#define DDRAM_ROW2_START 0x40
#define DDRAM_ROW2_END   0x53
#define DDRAM_ROW3_START 0x14
#define DDRAM_ROW3_END   0x27
#define DDRAM_ROW4_START 0x54
#define DDRAM_ROW4_END   0x67

// value of the array of structs making up the ascii-to-LCD character map
#define ADM2004D_FL_YBS_CHAR_MAP {\
LCD_MAP_CHAR('A', 0x41), LCD_MAP_CHAR('a', 0x61),\
LCD_MAP_CHAR('B', 0x42), LCD_MAP_CHAR('b', 0x62),\
LCD_MAP_CHAR('C', 0x43), LCD_MAP_CHAR('c', 0x63),\
LCD_MAP_CHAR('D', 0x44), LCD_MAP_CHAR('d', 0x64),\
LCD_MAP_CHAR('E', 0x45), LCD_MAP_CHAR('e', 0x65),\
LCD_MAP_CHAR('F', 0x46), LCD_MAP_CHAR('f', 0x66),\
LCD_MAP_CHAR('G', 0x47), LCD_MAP_CHAR('g', 0x67),\
LCD_MAP_CHAR('H', 0x48), LCD_MAP_CHAR('h', 0x68),\
LCD_MAP_CHAR('I', 0x49), LCD_MAP_CHAR('i', 0x69),\
LCD_MAP_CHAR('J', 0x4A), LCD_MAP_CHAR('j', 0x6A),\
LCD_MAP_CHAR('K', 0x4B), LCD_MAP_CHAR('k', 0x6B),\
LCD_MAP_CHAR('L', 0x4C), LCD_MAP_CHAR('l', 0x6C),\
LCD_MAP_CHAR('M', 0x4D), LCD_MAP_CHAR('m', 0x6D),\
LCD_MAP_CHAR('N', 0x4E), LCD_MAP_CHAR('n', 0x6E),\
LCD_MAP_CHAR('O', 0x4F), LCD_MAP_CHAR('o', 0x6F),\
LCD_MAP_CHAR('P', 0x50), LCD_MAP_CHAR('p', 0x70),\
LCD_MAP_CHAR('Q', 0x51), LCD_MAP_CHAR('q', 0x71),\
LCD_MAP_CHAR('R', 0x52), LCD_MAP_CHAR('r', 0x72),\
LCD_MAP_CHAR('S', 0x53), LCD_MAP_CHAR('s', 0x73),\
LCD_MAP_CHAR('T', 0x54), LCD_MAP_CHAR('t', 0x74),\
LCD_MAP_CHAR('U', 0x55), LCD_MAP_CHAR('u', 0x75),\
LCD_MAP_CHAR('V', 0x56), LCD_MAP_CHAR('v', 0x76),\
LCD_MAP_CHAR('W', 0x57), LCD_MAP_CHAR('w', 0x77),\
LCD_MAP_CHAR('X', 0x58), LCD_MAP_CHAR('x', 0x78),\
LCD_MAP_CHAR('Y', 0x59), LCD_MAP_CHAR('y', 0x79),\
LCD_MAP_CHAR('Z', 0x5A), LCD_MAP_CHAR('z', 0x7A),\
LCD_MAP_CHAR('0', 0x30),\
LCD_MAP_CHAR('1', 0x31),\
LCD_MAP_CHAR('2', 0x32),\
LCD_MAP_CHAR('3', 0x33),\
LCD_MAP_CHAR('4', 0x34),\
LCD_MAP_CHAR('5', 0x35),\
LCD_MAP_CHAR('6', 0x36),\
LCD_MAP_CHAR('7', 0x37),\
LCD_MAP_CHAR('8', 0x38),\
LCD_MAP_CHAR('9', 0x39),\
LCD_MAP_CHAR(' ', 0x20),\
LCD_MAP_CHAR('!', 0x21),\
LCD_MAP_CHAR('\"', 0x22),\
LCD_MAP_CHAR('#', 0x23),\
LCD_MAP_CHAR('$', 0x24),\
LCD_MAP_CHAR('%', 0x25),\
LCD_MAP_CHAR('&', 0x26),\
LCD_MAP_CHAR('\'', 0x27),\
LCD_MAP_CHAR('(', 0x28),\
LCD_MAP_CHAR(')', 0x29),\
LCD_MAP_CHAR('*', 0x2A),\
LCD_MAP_CHAR('+', 0x2B),\
LCD_MAP_CHAR(',', 0x2C),\
LCD_MAP_CHAR('-', 0x2D),\
LCD_MAP_CHAR('.', 0x2E),\
LCD_MAP_CHAR('/', 0x2F),\
LCD_MAP_CHAR(':', 0x3A),\
LCD_MAP_CHAR(';', 0x3B),\
LCD_MAP_CHAR('<', 0x3C),\
LCD_MAP_CHAR('=', 0x3D),\
LCD_MAP_CHAR('>', 0x3E),\
LCD_MAP_CHAR('?', 0x3F),\
LCD_MAP_CHAR('@', 0x40),\
LCD_MAP_CHAR('[', 0x5B),\
LCD_MAP_CHAR(']', 0x5D),\
LCD_MAP_CHAR('^', 0x5E),\
LCD_MAP_CHAR('_', 0x5F),\
LCD_MAP_CHAR('`', 0x60),\
LCD_MAP_CHAR('{', 0x7B),\
LCD_MAP_CHAR('|', 0x7C),\
LCD_MAP_CHAR('}', 0x7D),\
}\

#define ADM2004D_FL_YBS_GPIOS {\
LCD_RS_GPIO_Port,\
LCD_RW_GPIO_Port,\
LCD_DB7_GPIO_Port,\
LCD_DB6_GPIO_Port,\
LCD_DB5_GPIO_Port,\
LCD_DB4_GPIO_Port,\
LCD_DB3_GPIO_Port,\
LCD_DB2_GPIO_Port,\
LCD_DB1_GPIO_Port,\
LCD_DB0_GPIO_Port\
}\

#define ADM2004D_FL_YBS_PINS {\
LCD_RS_Pin,\
LCD_RW_Pin,\
LCD_DB7_Pin,\
LCD_DB6_Pin,\
LCD_DB5_Pin,\
LCD_DB4_Pin,\
LCD_DB3_Pin,\
LCD_DB2_Pin,\
LCD_DB1_Pin,\
LCD_DB0_Pin\
}\

#define NUM_CMD_BITS 10
#define MAX_GPIO_LEN 20
#define MAX_PIN_LEN 2

typedef struct {
    char ascii;        // Input char
    uint8_t lcd_code;  // Corresponding LCD character code
} LcdCharMap;

typedef char* GPIO_TypeDef;

typedef struct {
    LcdCharMap *charMap;
    GPIO_TypeDef *GPIOs;
    GPIO_TypeDef *pins;
} LCD;

void newLCD(LCD *lcd, LcdCharMap charMap[], GPIO_TypeDef GPIOS[], GPIO_TypeDef pins[]);
void Send_CMD(LCD* lcd, uint16_t cmd);
void printBinary(uint16_t cmd);
void Write_Char_DDRAM(LCD* lcd, char ch);
void Write_String(LCD* lcd, char* str, uint8_t row, uint8_t col);
void Move_Cursor(int row, int col);
//void Set_Control(uint8_t control);

uint8_t GetLcdCode(char ch);

#endif