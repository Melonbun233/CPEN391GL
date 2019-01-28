#include "HWDraw.h"
#include "CPEN391GL.h"

void write_pixel(int x, int y, int colour)
{
    if (x < 0 || y < 0 || colour < 0 || x >= XRES || y >= YRES)
        return;
	WAIT_FOR_GRAPHICS;

	GRAPHICS_X1_REG = x;
	GRAPHICS_Y1_REG = y;
	GRAPHICS_COLOUR_REG = colour;
	GRAPHICS_COMMAND_REG = PUT_PIXEL; 
}

int read_pixel(int x, int y)
{
    if (x < 0 || y < 0 || x >= XRES || y >= YRES)
        return -1;
	WAIT_FOR_GRAPHICS;

	GRAPHICS_X1_REG = x;
	GRAPHICS_Y1_REG = y;
	GRAPHICS_COMMAND_REG = GET_PIXEL;

	WAIT_FOR_GRAPHICS;
	return (int)(GRAPHICS_COLOUR_REG);
}

void program_palette(int index, int RGB)
{
	WAIT_FOR_GRAPHICS;

	GRAPHICS_COLOUR_REG = index;
	GRAPHICS_X1_REG = RGB >> 16;
	GRAPHICS_Y1_REG = RGB;
	GRAPHICS_COMMAND_REG = PROGRAM_PALETTE_COLOUR;
}

void draw_hline(int x1, int y1, int length, int colour)
{
	if (length == 0 || x1 < 0 || y1 < 0 || colour < 0)
        return;

    int x2 = x1 + length - 1;

    WAIT_FOR_GRAPHICS;
    GRAPHICS_X1_REG = x1;
    GRAPHICS_X2_REG = x2;
    GRAPHICS_Y1_REG = y1;
    GRAPHICS_Y2_REG = y1;
    GRAPHICS_COLOUR_REG = colour;
    GRAPHICS_COMMAND_REG = DRAW_H_LINE;
}

void draw_vline(int x1, int y1, int length, int colour)
{
	if (length == 0 || x1 < 0 || y1 < 0 || colour < 0 || length < 0)
        return;

    int y2 = y1 + length - 1;   //two same points result in a single point in hw

    WAIT_FOR_GRAPHICS;
    GRAPHICS_X1_REG = x1;
    GRAPHICS_X2_REG = x1;
    GRAPHICS_Y1_REG = y1;
    GRAPHICS_Y2_REG = y2;
    GRAPHICS_COLOUR_REG = colour;
    GRAPHICS_COMMAND_REG = DRAW_V_LINE;
}

void draw_line(int x1, int y1, int x2, int y2, int colour)
{
    if (x1 < 0 || x2 < 0 || y1 < 0 || y2 <0 || colour < 0)
        return;

    WAIT_FOR_GRAPHICS;

    GRAPHICS_X1_REG = x1;
    GRAPHICS_X2_REG = x2;
    GRAPHICS_Y1_REG = y1;
    GRAPHICS_Y2_REG = y2;
    GRAPHICS_COLOUR_REG = colour;
    GRAPHICS_COMMAND_REG = DRAW_LINE;
}
