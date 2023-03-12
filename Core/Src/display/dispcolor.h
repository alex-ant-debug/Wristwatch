#ifndef _DISPCOLOR_H
#define _DISPCOLOR_H

#include <stdint.h>


#define DISPTYPE_gc9a01a        3

#define DISPCOLOR_type         DISPTYPE_gc9a01a

typedef struct
{
	uint16_t r:5;
	uint16_t g:6;
	uint16_t b:5;
} sRGB565;

typedef struct
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} sRGB888;

typedef union
{
	sRGB565 rgb;
	uint16_t word;
} uRGB565;


#define RGB565(r, g, b)         (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))


#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

uint16_t bgColor;
uint16_t digitColor;
uint16_t selectedText;

void dispcolorInit(uint8_t Width, uint8_t Height);
void dispcolorUpdate();
void dispcolorClearScreen(void);
void dispcolorSetBrightness(uint8_t Value);
void dispcolorFillScreen(uint16_t color);
void dispcolorDrawPixel(int16_t X, int16_t Y, uint16_t color);
void dispcolorDrawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void dispcolorDrawLine2(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color, uint8_t thick);
void dispcolorDrawLine_Wu(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void dispcolorDrawRectangle(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void dispcolorFillRectangle(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t fillcolor);
void dispcolorDrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void dispcolorDrawTriangle_Wu(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void dispcolorFillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void dispcolorDrawCircle(int16_t x0, int16_t y0, int16_t radius, uint16_t color, uint8_t correction);
void dispcolorDrawCircle_Wu(int16_t x0, int16_t y0, int16_t radius, uint16_t color);
void dispcolorFillCircle(int16_t x0, int16_t y0, int16_t radius, uint16_t color);
void dispcolorFillCircleWu(int16_t x0, int16_t y0, int16_t radius, uint16_t color);
void dispcolorDrawArc(int16_t x0, int16_t y0, int16_t radius, int16_t startAngle, int16_t endAngle, uint16_t color, uint8_t correction);
int16_t dispcolorDrawString(int16_t X, int16_t Y, uint8_t FontID, char *Str, uint16_t TextColor);
int16_t dispcolorDrawString_Bg(int16_t X, int16_t Y, uint8_t FontID, char *Str, uint16_t TextColor, uint16_t BgColor);
int16_t dispcolorPrintf(int16_t X, int16_t Y, uint8_t FontID, uint16_t TextColor, const char *args, ...);
int16_t dispcolorPrintfBg(int16_t X, int16_t Y, uint8_t FontID, uint16_t TextColor, uint16_t BgColor, const char *args, ...);

#endif
