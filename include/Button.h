/**
 * CPEN391 GL Button Feature
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Rectangle.h"
#include "Types.h"

// A button is constructed by some attributes (touching area), a shape (rectangle),
// and some texts.
struct Button {

	//The top-left corner of the touching area.
	//Default value is the same as the shape's top-left corner.
	uint16_t touch_x, touch_y;

	//With the top-left corner, these attributes define a 
	//rectangle area representing touching area for the button.
	//Default value is set the same as shape's width and height.
	uint16_t touch_width, touch_height;

	//The shape of this button.
	//Only support rectangle shape.
	struct Rectangle *shape;

	//Displaying the text on the button.
	//The text is centered.
	char text[];
	
	//Length of the text.
	uint16_t text_length;
};

#endif

