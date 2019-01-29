//This file contains all functions that directly using graphic hardware acceleration

/*
	Graphic register addresses
 */

#ifndef HWDRAW_H_
#define HWDRAW_H_

#define GRAPHICS_COMMAND_REG  			(*(volatile unsigned short int *)(0xFF210000))
#define GRAPHICS_STATUS_REG   			(*(volatile unsigned short int *)(0xFF210000))
#define GRAPHICS_X1_REG   				(*(volatile unsigned short int *)(0xFF210002))
#define GRAPHICS_Y1_REG   				(*(volatile unsigned short int *)(0xFF210004))
#define GRAPHICS_X2_REG   				(*(volatile unsigned short int *)(0xFF210006))
#define GRAPHICS_Y2_REG   				(*(volatile unsigned short int *)(0xFF210008))
#define GRAPHICS_COLOUR_REG   			(*(volatile unsigned short int *)(0xFF21000E))
#define GRAPHICS_BACKGROUND_COLOUR_REG  (*(volatile unsigned short int *)(0xFF210010))

/*
	This macro continuesly checking graphics chip status register until it's idle
	This macro should be called every time you want to set graphic registers
 */
#define WAIT_FOR_GRAPHICS		while((GRAPHICS_STATUS_REG & 0x0001) != 0x0001);

/*
	Constants that corresponding to all commands in the graphic accelerator
 */
#define DRAW_H_LINE					1
#define DRAW_V_LINE					2
#define DRAW_LINE					3
#define	PUT_PIXEL					0xA
#define	GET_PIXEL					0xB
#define	PROGRAM_PALETTE_COLOUR    	0x10
#define CLEAR_SCREEN				0x11

/*******************************************************************************************
* This function writes a single pixel to the x,y coords specified using the specified colour
* Note colour is a byte and represents a palette number (0-255) not a 24 bit RGB value
* You can find the color palette number in the Colors.h or set a color on your own.
********************************************************************************************/
void write_pixel(int x, int y, int colour);

/*********************************************************************************************
* This function read a single pixel from the x,y coords specified and returns its colour
* Note returned colour is a byte and represents a palette number (0-255) not a 24 bit RGB 
* value. You can find the color palette number in the Colors.h or set a color on your own.
*********************************************************************************************/
int read_pixel(int x, int y);

/**********************************************************************************
** subroutine to program a hardware (graphics chip) palette number with an RGB value
** e.g. ProgramPalette(RED, 0x00FF0000) ;
**
************************************************************************************/
void program_palette(int PaletteNumber, int RGB);

/**********************************************************************************
* This function draws a horizontal line from a point (x1, y1) rightwards
* 	- x1, y1, length and colour should not be negative
* 	- If length is 0, nothing will be drawn 
* 	- If length is 1, a point will be drawin at (x1, y1)
************************************************************************************/
void draw_hline(int x1, int y1, int length, int colour);

/**********************************************************************************
* This function draws a vertical line from a point (x1, y1) downwards
* 	- x1, y1, length and colour should not be negative
* 	- If length is 0, nothing will be drawn 
* 	- If length is 1, a point will be drawin at (x1, y1)
************************************************************************************/
void draw_vline(int x1, int y1, int length, int colour);

/**********************************************************************************
* This function draws any line from a point (x1, y1) downwards (x2, y2)
* 	- x1, y1, x2, y2 and colour should not be negative
* 	- If the two points are the same, a point will be drawn
* 	NOTE: Use this function to draw vertical or horizontal line will cost more 
* 	GPU cycles
* 	NOTE: The two points should be both in the screen. Otherwise nothing will be
* 	drawn.
************************************************************************************/
void draw_line(int x1, int y1, int x2, int y2, int colour);

/**
 * Clear the screen with specified colour
 */
void clear_screen(int colour);

#endif

