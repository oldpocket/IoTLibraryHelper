#include <Arduino.h>

#define PIN_SCE   D4 //pin GPIO12 ON ESP , pin SCE ON LCD
#define PIN_RESET D3 //pin GPI02 on ESP , pin RST on LCD
#define PIN_DC    D5 //pin GPIO14 on ESP , pin DC on LCD
#define PIN_SDIN  D6 //pin GPIO4 on ESP , pin SDIN on LCD
#define PIN_SCLK  D7 //pin GPIO5 on ESP  , pin SLCK on LCD
#define PIN_BL    D8

#define TRIGGER 10
#define ECHO     9

//The DC pin tells the LCD if we are sending a command or data
#define LCD_COMMAND 0 
#define LCD_DATA    1

//You may find a different size screen, but this one is 84 by 48 pixels
#define LCD_X     84
#define LCD_Y     48

//There are two memory banks in the LCD, data/RAM and commands. This 
//function sets the DC pin high or low depending, and then sends
//the data byte
void LCDWrite(byte data_or_command, byte data);

void gotoXY(int x, int y);

//This takes a large array of bits and sends them to the LCD
void LCDBitmap(char my_array[]);

//This function takes in a character, looks it up in the font table/array
//And writes it to the screen
//Each character is 8 bits tall and 5 bits wide. We pad one blank column of
//pixels on each side of the character for readability.
void LCDCharacter(char character);


//Given a string of characters, one by one is passed to the LCD
void LCDString(char *characters);

//Clears the LCD by writing zeros to the entire screen
void LCDClear(void);

void drawRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);
void fillRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);

//This sends the magical commands to the PCD8544
void LCDInit(void);