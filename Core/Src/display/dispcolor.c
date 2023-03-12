#include <dispcolor.h>
#include <font.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265
static uint16_t _Width, _Height;

#if (DISPCOLOR_type == DISPTYPE_gc9a01a)
#include <gc9a01a.h>
#else
  #error //
#endif


static void SwapInt16Values(int16_t *pValue1, int16_t *pValue2) {
	int16_t TempValue = *pValue1;
	*pValue1 = *pValue2;
	*pValue2 = TempValue;
}

void dispcolorInit(uint8_t Width, uint8_t Height) {
#if (DISPCOLOR_type == DISPTYPE_gc9a01a)
	GC9A01A_Init(Width, Height);
	_Width = GC9A01A_GetWidth();
	_Height = GC9A01A_GetHeight();
#endif

	dispcolorClearScreen();

	bgColor = BLACK;
	digitColor = WHITE;
	selectedText = GREEN;
}

void dispcolorUpdate() {
#if (DISPCOLOR_type == DISPTYPE_gc9a01a)
	GC9A01A_Update();
#endif
}

void dispcolorSetBrightness(uint8_t Value) {
	if (Value > 100)
		Value = 100;

#if (DISPCOLOR_type == DISPTYPE_gc9a01a)
	GC9A01A_SetBL(Value);
#endif
}

void dispcolorDrawPixel(int16_t x, int16_t y, uint16_t color) {
#if (DISPCOLOR_type == DISPTYPE_gc9a01a)
	GC9A01A_DrawPixel(x, y, color);
#endif
}

uint16_t dispcolorGetPixel(int16_t x, int16_t y) {
#if (DISPCOLOR_type == DISPTYPE_gc9a01a)
	return GC9A01A_GetPixel(x, y);
#endif
}

void dispcolorFillRect(int16_t x, int16_t y, int16_t w, int16_t h,
		uint16_t color) {
#if (DISPCOLOR_type == DISPTYPE_gc9a01a)
	GC9A01A_FillRect(x, y, w, h, color);
#endif
}

void dispcolorFillScreen(uint16_t color) {
	dispcolorFillRect(0, 0, _Width, _Height, color);
}

void dispcolorClearScreen(void) {
	dispcolorFillScreen(BLACK);
}

static void DrawLineSlow(int16_t x1, int16_t y1, int16_t x2, int16_t y2,
		uint16_t color) {
	const int16_t deltaX = abs(x2 - x1);
	const int16_t deltaY = abs(y2 - y1);
	const int16_t signX = x1 < x2 ? 1 : -1;
	const int16_t signY = y1 < y2 ? 1 : -1;

	int16_t error = deltaX - deltaY;

	dispcolorDrawPixel(x2, y2, color);

	while (x1 != x2 || y1 != y2) {
		dispcolorDrawPixel(x1, y1, color);
		const int16_t error2 = error * 2;

		if (error2 > -deltaY) {
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX) {
			error += deltaX;
			y1 += signY;
		}
	}
}

void dispcolorDrawLine(int16_t x1, int16_t y1, int16_t x2, int16_t y2,
		uint16_t color) {
	if (x1 == x2) {
		if (y1 > y2)
			dispcolorFillRect(x1, y2, 1, y1 - y2 + 1, color);
		else
			dispcolorFillRect(x1, y1, 1, y2 - y1 + 1, color);
		return;
	}

	if (y1 == y2) {
		if (x1 > x2)
			dispcolorFillRect(x2, y1, x1 - x2 + 1, 1, color);
		else
			dispcolorFillRect(x1, y1, x2 - x1 + 1, 1, color);
		return;
	}

	DrawLineSlow(x1, y1, x2, y2, color);
}

void dispcolorDrawLine2(int16_t x1, int16_t y1, int16_t x2, int16_t y2,
		uint16_t color, uint8_t thick) {
	const int16_t deltaX = abs(x2 - x1);
	const int16_t deltaY = abs(y2 - y1);
	const int16_t signX = x1 < x2 ? 1 : -1;
	const int16_t signY = y1 < y2 ? 1 : -1;

	int16_t error = deltaX - deltaY;

	if (thick > 1)
		dispcolorFillCircle(x2, y2, thick >> 1, color);
	else
		dispcolorDrawPixel(x2, y2, color);

	while (x1 != x2 || y1 != y2) {
		if (thick > 1)
			dispcolorFillCircle(x1, y1, thick >> 1, color);
		else
			dispcolorDrawPixel(x1, y1, color);

		const int16_t error2 = error * 2;
		if (error2 > -deltaY) {
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX) {
			error += deltaX;
			y1 += signY;
		}
	}
}

void DrawPixel(int16_t x, int16_t y, uint16_t color, float intensity) {
	uRGB565 colorRgb;
	uRGB565 oldColorRgb;

	colorRgb.word = color;
	oldColorRgb.word = dispcolorGetPixel(x, y);

	float iintensity = 1 - intensity;
	uint16_t r = oldColorRgb.rgb.r * iintensity + colorRgb.rgb.r * intensity;
	uint16_t g = oldColorRgb.rgb.g * iintensity + colorRgb.rgb.g * intensity;
	uint16_t b = oldColorRgb.rgb.b * iintensity + colorRgb.rgb.b * intensity;

	uRGB565 newColorRgb;
	newColorRgb.rgb.r = r;
	newColorRgb.rgb.g = g;
	newColorRgb.rgb.b = b;
	dispcolorDrawPixel(x, y, newColorRgb.word);
}

// integer part of x
int ipart(float x) {
	return (int) x;
}

// fractional part of x
float fpart(float x) {
	return x - (int) x;
}

float rfpart(float x) {
	return 1 - fpart(x);
}

void swap(int16_t *a, int16_t *b) {
	int16_t temp = *a;
	*a = *b;
	*b = temp;
}

static void DrawLineSlow_Wu(int16_t x1, int16_t y1, int16_t x2, int16_t y2,
		uint16_t color) {
	uint8_t steep = abs(y2 - y1) > abs(x2 - x1) ? 1 : 0;
	if (steep) {
		swap(&x1, &y1);
		swap(&x2, &y2);
	}
	if (x1 > x2) {
		swap(&x1, &x2);
		swap(&y1, &y2);
	}

	float dx = x2 - x1;
	float dy = y2 - y1;
	float gradient = dx == 0 ? 1 : dy / dx;

	// handle first endpoint
	float xend = round(x1);
	float yend = gradient * (xend - x1) + y1;
	float xgap = rfpart(x1 + 0.5);
	int16_t xpxl1 = xend; // this will be used in the main loop
	int16_t ypxl1 = ipart(yend);
	if (steep) {
		DrawPixel(ypxl1, xpxl1, color, rfpart(yend) * xgap);
		DrawPixel(ypxl1 + 1, xpxl1, color, fpart(yend) * xgap);
	} else {
		DrawPixel(xpxl1, ypxl1, color, rfpart(yend) * xgap);
		DrawPixel(xpxl1, ypxl1 + 1, color, fpart(yend) * xgap);
	}

	float intery = yend + gradient; // first y-intersection for the main loop

	// handle second endpoint
	xend = round(x2);
	yend = gradient * (xend - x2) + y2;
	xgap = fpart(x2 + 0.5);
	int16_t xpxl2 = xend; //this will be used in the main loop
	int16_t ypxl2 = ipart(yend);

	if (steep) {
		DrawPixel(ypxl2, xpxl2, color, rfpart(yend) * xgap);
		DrawPixel(ypxl2 + 1, xpxl2, color, fpart(yend) * xgap);
	} else {
		DrawPixel(xpxl2, ypxl2, color, rfpart(yend) * xgap);
		DrawPixel(xpxl2, ypxl2 + 1, color, fpart(yend) * xgap);
	}

	// main loop
	if (steep) {
		for (int16_t x = xpxl1 + 1; x <= xpxl2 - 1; x++) {
			DrawPixel(ipart(intery), x, color, rfpart(intery));
			DrawPixel(ipart(intery) + 1, x, color, fpart(intery));
			intery += gradient;
		}
	} else {
		for (int16_t x = xpxl1 + 1; x <= xpxl2 - 1; x++) {
			DrawPixel(x, ipart(intery), color, rfpart(intery));
			DrawPixel(x, ipart(intery) + 1, color, fpart(intery));
			intery += gradient;
		}
	}
}

void dispcolorDrawLine_Wu(int16_t x1, int16_t y1, int16_t x2, int16_t y2,
		uint16_t color) {
	if (x1 == x2) {
		if (y1 > y2)
			dispcolorFillRect(x1, y2, 1, y1 - y2 + 1, color);
		else
			dispcolorFillRect(x1, y1, 1, y2 - y1 + 1, color);
		return;
	}

	if (y1 == y2) {
		if (x1 > x2)
			dispcolorFillRect(x2, y1, x1 - x2 + 1, 1, color);
		else
			dispcolorFillRect(x1, y1, x2 - x1 + 1, 1, color);
		return;
	}

	DrawLine_Slow_Wu(x1, y1, x2, y2, color);
}

void dispcolorDrawRectangle(int16_t x1, int16_t y1, int16_t x2, int16_t y2,
		uint16_t color) {
	dispcolorDrawLine(x1, y1, x1, y2, color);
	dispcolorDrawLine(x2, y1, x2, y2, color);
	dispcolorDrawLine(x1, y1, x2, y1, color);
	dispcolorDrawLine(x1, y2, x2, y2, color);
}

void dispcolorFillRectangle(int16_t x1, int16_t y1, int16_t x2, int16_t y2,
		uint16_t fillcolor) {
	if (x1 > x2)
		SwapInt16Values(&x1, &x2);
	if (y1 > y2)
		SwapInt16Values(&y1, &y2);

	dispcolorFillRect(x1, y1, x2 - x1, y2 - y1, fillcolor);
}

void dispcolorDrawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
		int16_t x2, int16_t y2, uint16_t color) {
	dispcolorDrawLine(x0, y0, x1, y1, color);
	dispcolorDrawLine(x1, y1, x2, y2, color);
	dispcolorDrawLine(x2, y2, x0, y0, color);
}

void dispcolorDrawTriangle_Wu(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
		int16_t x2, int16_t y2, uint16_t color) {
	dispcolorDrawLine_Wu(x0, y0, x1, y1, color);
	dispcolorDrawLine_Wu(x1, y1, x2, y2, color);
	dispcolorDrawLine_Wu(x2, y2, x0, y0, color);
}

void dispcolorFillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
		int16_t x2, int16_t y2, uint16_t color) {
	int16_t a, b, y, last;

	// Sort coordinates by Y order (y2 >= y1 >= y0)
	if (y0 > y1) {
		SwapInt16Values(&y0, &y1);
		SwapInt16Values(&x0, &x1);
	}
	if (y1 > y2) {
		SwapInt16Values(&y2, &y1);
		SwapInt16Values(&x2, &x1);
	}
	if (y0 > y1) {
		SwapInt16Values(&y0, &y1);
		SwapInt16Values(&x0, &x1);
	}

	if (y0 == y2)	  // Handle awkward all-on-same-line case as its own thing
			{
		a = b = x0;
		if (x1 < a)
			a = x1;
		else if (x1 > b)
			b = x1;
		if (x2 < a)
			a = x2;
		else if (x2 > b)
			b = x2;

		dispcolorFillRect(a, y0, b - a + 1, 1, color);
		return;
	}

	int16_t dx01 = x1 - x0, dy01 = y1 - y0, dx02 = x2 - x0, dy02 = y2 - y0,
			dx12 = x2 - x1, dy12 = y2 - y1;
	int32_t sa = 0, sb = 0;

	// For upper part of triangle, find scanline crossings for segments
	// 0-1 and 0-2.  If y1=y2 (flat-bottomed triangle), the scanline y1
	// is included here (and second loop will be skipped, avoiding a /0
	// error there), otherwise scanline y1 is skipped here and handled
	// in the second loop...which also avoids a /0 error here if y0=y1
	// (flat-topped triangle).
	if (y1 == y2)
		last = y1; // Include y1 scanline
	else
		last = y1 - 1; // Skip it

	for (y = y0; y <= last; y++) {
		a = x0 + sa / dy01;
		b = x0 + sb / dy02;
		sa += dx01;
		sb += dx02;

		if (a > b)
			SwapInt16Values(&a, &b);

		dispcolorFillRect(a, y, b - a + 1, 1, color);
	}

	// For lower part of triangle, find scanline crossings for segments 0-2 and 1-2.  This loop is skipped if y1=y2.
	sa = (int32_t) dx12 * (y - y1);
	sb = (int32_t) dx02 * (y - y0);
	for (; y <= y2; y++) {
		a = x1 + sa / dy12;
		b = x0 + sb / dy02;
		sa += dx12;
		sb += dx02;

		if (a > b)
			SwapInt16Values(&a, &b);

		dispcolorFillRect(a, y, b - a + 1, 1, color);
	}
}

void dispcolorDrawCircle(int16_t x0, int16_t y0, int16_t radius,
		uint16_t color, uint8_t correction) {
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;

	if (correction)
		correction = 1;

	while (y >= 0) {
		dispcolorDrawPixel(x0 + x, y0 + y + correction, color);
		dispcolorDrawPixel(x0 + x, y0 - y, color);
		dispcolorDrawPixel(x0 - x + correction, y0 + y + correction, color);
		dispcolorDrawPixel(x0 - x + correction, y0 - y, color);
		error = 2 * (delta + y) - 1;

		if (delta < 0 && error <= 0) {
			++x;
			delta += 2 * x + 1;
			continue;
		}

		error = 2 * (delta - x) - 1;

		if (delta > 0 && error > 0) {
			--y;
			delta += 1 - 2 * y;
			continue;
		}

		++x;
		delta += 2 * (x - y);
		--y;
	}
}

void dispcolorDrawCircle_Wu(int16_t x0, int16_t y0, int16_t radius,
		uint16_t color) {
	int16_t i = 0;
	int16_t j = radius;
	float last_fade_amount = 0;

	while (i < j) {
		float height = sqrt(fmax(radius * radius - i * i, 0));
		float fade_amount = ceil(height) - height;

		if (fade_amount < last_fade_amount)
			j--;	// Opaqueness reset so drop down a row

		last_fade_amount = fade_amount;

		// We're fading out the current j row, and fading in the next one down.
		DrawPixel(x0 + i, y0 - j, color, 1 - fade_amount);
		DrawPixel(x0 + i, y0 - j + 1, color, fade_amount);

		DrawPixel(x0 + j, y0 - i, color, 1 - fade_amount);
		DrawPixel(x0 + j - 1, y0 - i, color, fade_amount);

		DrawPixel(x0 + j, y0 + i, color, 1 - fade_amount);
		DrawPixel(x0 + j - 1, y0 + i, color, fade_amount);

		DrawPixel(x0 + i, y0 + j, color, 1 - fade_amount);
		DrawPixel(x0 + i, y0 + j - 1, color, fade_amount);

		DrawPixel(x0 - i, y0 + j, color, 1 - fade_amount);
		DrawPixel(x0 - i, y0 + j - 1, color, fade_amount);

		DrawPixel(x0 - j, y0 + i, color, 1 - fade_amount);
		DrawPixel(x0 - j + 1, y0 + i, color, fade_amount);

		DrawPixel(x0 - j, y0 - i, color, 1 - fade_amount);
		DrawPixel(x0 - j + 1, y0 - i, color, fade_amount);

		DrawPixel(x0 - i, y0 - j, color, 1 - fade_amount);
		DrawPixel(x0 - i, y0 - j + 1, color, fade_amount);

		i++;
	}
}

void dispcolorFillCircle(int16_t x0, int16_t y0, int16_t radius,
		uint16_t color) {
	int x = 0;
	int y = radius;
	int delta = 1 - 2 * radius;
	int error = 0;

	while (y >= 0) {
		dispcolorDrawLine(x0 + x, y0 - y, x0 + x, y0 + y, color);
		dispcolorDrawLine(x0 - x, y0 - y, x0 - x, y0 + y, color);
		error = 2 * (delta + y) - 1;

		if (delta < 0 && error <= 0) {
			++x;
			delta += 2 * x + 1;
			continue;
		}

		error = 2 * (delta - x) - 1;

		if (delta > 0 && error > 0) {
			--y;
			delta += 1 - 2 * y;
			continue;
		}

		++x;
		delta += 2 * (x - y);
		--y;
	}
}

void dispcolorFillCircleWu(int16_t x0, int16_t y0, int16_t radius,
		uint16_t color) {
	if (radius > 1)
		dispcolorFillCircle(x0, y0, radius - 1, color);
	dispcolorDrawCircle_Wu(x0, y0, radius, color);
}

void dispcolorDrawArc(int16_t x0, int16_t y0, int16_t radius,
		int16_t startAngle, int16_t endAngle, uint16_t color, uint8_t thick) {
	int16_t xLast = -1, yLast = -1;
	startAngle -= 90;
	endAngle -= 90;

	for (int16_t angle = startAngle; angle <= endAngle; angle += 2) {
		float angleRad = (float) angle * PI / 180;
		int x = cos(angleRad) * radius + x0;
		int y = sin(angleRad) * radius + y0;

		if (xLast == -1 || yLast == -1) {
			xLast = x;
			yLast = y;
			continue;
		}

		if (thick > 1)
			dispcolorDrawLine2(xLast, yLast, x, y, color, thick);
		else
			dispcolorDrawLine(xLast, yLast, x, y, color);

		xLast = x;
		yLast = y;
	}
}

void dispcolorDrawArc_Wu(int16_t x0, int16_t y0, int16_t radius,
		int16_t startAngle, int16_t endAngle, uint16_t color, uint8_t thick) {
	int16_t xLast = -1, yLast = -1;
	startAngle -= 90;
	endAngle -= 90;

	for (int16_t angle = startAngle; angle <= endAngle; angle += 1)	//1)//6)
			{
		float angleRad = (float) angle * PI / 180;
		int x = cos(angleRad) * radius + x0;
		int y = sin(angleRad) * radius + y0;

		if (xLast == -1 || yLast == -1) {
			xLast = x;
			yLast = y;
			continue;
		}

		if (thick > 1)
			dispcolorDrawCircle_Wu(x, y, thick / 2, color);
		else
			dispcolorDrawLine_Wu(xLast, yLast, x, y, color);

		xLast = x;
		yLast = y;
	}
}

static uint8_t dispcolorDrawChar_General(int16_t X, int16_t Y, uint8_t FontID,
		char Char, uint16_t TextColor, uint16_t BgColor,
		uint8_t TransparentBg) {

	uint8_t *pCharTable = font_GetFontStruct(FontID, Char);
	uint8_t CharWidth = font_GetCharWidth(pCharTable);
	uint8_t CharHeight = font_GetCharHeight(pCharTable);
	pCharTable += 2;

	if (FontID == FONTID_6X8M) {
		for (uint8_t row = 0; row < CharHeight; row++) {
			for (uint8_t col = 0; col < CharWidth; col++) {
				if (pCharTable[row] & (1 << (7 - col)))
					dispcolorDrawPixel(X + col, Y + row, TextColor);
				else if (!TransparentBg)
					dispcolorDrawPixel(X + col, Y + row, BgColor);
			}
		}
	} else {
		for (uint8_t row = 0; row < CharHeight; row++) {
			for (uint8_t col = 0; col < CharWidth; col++) {
				if (col < 8) {
					if (pCharTable[row * 2] & (1 << (7 - col)))
						dispcolorDrawPixel(X + col, Y + row, TextColor);
					else if (!TransparentBg)
						dispcolorDrawPixel(X + col, Y + row, BgColor);
				} else {
					if (pCharTable[(row * 2) + 1] & (1 << (15 - col)))
						dispcolorDrawPixel(X + col, Y + row, TextColor);
					else if (!TransparentBg)
						dispcolorDrawPixel(X + col, Y + row, BgColor);
				}
			}
		}
	}

	return CharWidth;
}

uint8_t dispcolorDrawChar(int16_t X, int16_t Y, uint8_t FontID, char Char,
		uint16_t TextColor) {
	return dispcolorDrawChar_General(X, Y, FontID, Char, TextColor, 0, 1);
}

uint8_t dispcolorDrawChar_Bg(int16_t X, int16_t Y, uint8_t FontID,
		char Char, uint16_t TextColor, uint16_t BgColor) {
	return dispcolorDrawChar_General(X, Y, FontID, Char, TextColor, BgColor, 0);
}

static int16_t dispcolorDrawString_General(int16_t X, int16_t Y,
		uint8_t FontID, char *Str, uint16_t TextColor, uint16_t BgColor,
		uint8_t TransparentBg) {
	uint8_t done = 0;
	int16_t Xstart = X;
	uint8_t StrHeight = 8;

	while (!done) {
		switch (*Str) {
		case '\0':
			done = 1;
			break;
		case '\n':
			Y += StrHeight;
			break;
		case '\r':
			X = Xstart;
			break;
		default:
			if (TransparentBg)
				X += dispcolorDrawChar(X, Y, FontID, *Str, TextColor);
			else
				X += dispcolorDrawChar_Bg(X, Y, FontID, *Str, TextColor,
						BgColor);

			StrHeight = font_GetCharHeight(font_GetFontStruct(FontID, *Str));
			break;
		}
		Str++;
	}
	return X;
}

int16_t dispcolorDrawString(int16_t X, int16_t Y, uint8_t FontID, char *Str,
		uint16_t TextColor) {
	return dispcolorDrawString_General(X, Y, FontID, Str, TextColor, 0, 1);
}

int16_t dispcolorDrawString_Bg(int16_t X, int16_t Y, uint8_t FontID, char *Str,
		uint16_t TextColor, uint16_t BgColor) {
	return dispcolorDrawString_General(X, Y, FontID, Str, TextColor, BgColor,
			0);
}

int16_t dispcolorPrintf(int16_t X, int16_t Y, uint8_t FontID,
		uint16_t TextColor, const char *args, ...) {
	char StrBuff[100];

	va_list ap;
	va_start(ap, args);
	vsnprintf(StrBuff, sizeof(StrBuff), args, ap);
	va_end(ap);

	return dispcolorDrawString(X, Y, FontID, StrBuff, TextColor);
}

int16_t dispcolorPrintfBg(int16_t X, int16_t Y, uint8_t FontID,
		uint16_t TextColor, uint16_t BgColor, const char *args, ...) {
	char StrBuff[100];

	va_list ap;
	va_start(ap, args);
	vsnprintf(StrBuff, sizeof(StrBuff), args, ap);
	va_end(ap);

	return dispcolorDrawString_Bg(X, Y, FontID, StrBuff, TextColor,
			BgColor);
}

int16_t dispcolorGetTextWidth(uint8_t FontID, char *Str) {
	uint8_t done = 0;
	int16_t width = 0;

	while (!done) {
		switch (*Str) {
		case '\0':
			done = 1;
			break;
		case '\n':
		case '\r':
			break;
		default:
			width += font_GetCharWidth(font_GetFontStruct(FontID, *Str));
			break;
		}
		Str++;
	}
	return width;
}

int16_t dispcolorGetFormatedTextWidth(uint8_t FontID, char *Str,
		const char *args, ...) {
	char StrBuff[100];

	va_list ap;
	va_start(ap, args);
	vsnprintf(StrBuff, sizeof(StrBuff), args, ap);
	va_end(ap);

	return dispcolorGetTextWidth(FontID, Str);
}
