//This file is used for rectangle drawing for CPEN391GL
//Rectangles here are drawn using line hardware acceleration

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Types.h"

//rectangle structure
//You should not create a rectangle using the struct directly,
//use rect_create() instead
struct Rectangle
{
	//top-left corner of the rectangle, shouldn't be negative
	uint16_t x;
	uint16_t y;

	//width and length of the rectangle, shouldn't be negative
	uint16_t width;
	uint16_t height;

	//Rectangle's border colour
	//Default colour is BLACK
	uint8_t border_colour;

	//Width of the border
	//Default border width is 0
	uint16_t border_width;

	//Rectangle's inner colour
	//Default colour is WHITE
	uint8_t inner_colour;

	//Whether inner color is applied
	//Default value is TRUE
	uint8_t filled;
};

//rectangle constructor
//(x, y) is the top-left corner of this rectangle
//default rectangle is :
//	BLACK border with width 1
//	Filled with WHITE
struct Rectangle *rect_create(int x, int y, int width, int height);

//Destroy the rectangle
//This function should be manually called to release memory
void rect_destroy(struct Rectangle *rect);

//Draw the rectangle on screen based on its attributes
void rect_draw(struct Rectangle *rect);

#endif
