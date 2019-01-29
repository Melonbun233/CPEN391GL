//This file is used for triangle drawing for CPEN391GL

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Types.h"

//triangle structure
//You should not create a triangle using the struct directly,
// use triangle_create() instead

struct Triangle
{
	//three points coordinates
	uint16_t x1, x2, x3;
	uint16_t y1, y2, y3;

	//triangle's border color
	//default colour is BLACK
	uint8_t border_colour;

	
	/**
	 * CURRENTLY NOT SUPPORTED
	 */
	//default border width is 1
	uint16_t border_width;

	//triangle's inner colour
	//default colour is WHITE
	uint8_t inner_colour;

	//whether inner colour is applied
	uint8_t filled;
};


//Triangle constructor
//default triangle is:
//	BLACK border with width 1
//	Filled with WHITE colour
struct Triangle *trig_create(int x1, int y1, int x2, int y2, int x3, int y3);

//Destroy the triangle
//This function should be manually called to release memory
void trig_destroy(struct Triangle *trig);

//Draw the triangle on screen based on its attributes
void trig_draw(struct Triangle *trig);

#endif

