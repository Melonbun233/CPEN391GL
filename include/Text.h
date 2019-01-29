//A wrapper around text drawing
#ifndef TEXT_H_
#define TEXT_H_

#include "Fonts.h"
#include "Types.h"


//A structure for text drawing
struct Text {
	//The top-left point the this text string.
	//Basically the string will start from this point.
	uint16_t x, y;

	//A null-terminated string
	char *content;

	//Spacing between each character
	uint16_t font_space;

	//Font size of the string.
	//Only 5, 10, 16, 22, 38 are supported. If the value is not one
	//of these, size 10 will be used.
	uint8_t font_size;

	//Colour of the font
	uint8_t font_colour;
};

/**
 * Create a text structure.
 * @param  x           
 * x coord of the top-left corner. The text will display from this point
 * towards right.
 * 
 * @param  y           
 * y coord of the top-left corner. The text will display from this point
 * towards right.
 * 
 * @param  content    
 * A null-termintated string contains the all characters of the text. 
 * Should follow ASCII table, non-printable characters will not be displayed.
 * 
 * @param  font_size   
 * Font size you want to use. Only support 5, 10, 16, 22, 38. If font_size is 
 * unsupported, a default value of 10 will be used.
 * 
 * @param  font_space  
 * Spacing between each character.
 * 
 * @return             
 * A pointer of the text structure for drawing.
 */
struct Text *text_create(int x, int y, char content[], int font_size, int font_space, int font_colour);

/**
 * You MUST use this function if you want to change text's content
 * because the content is copied in the text structure.
 *
 * content MUST be a null terminated string.
 *
 * return
 * 0 if setting unsuccessful. May caused by not enough memory
 * 1 if setting successful.
 */
int text_set_content(struct Text *text, char content[]);

/**
 * Destroy the text structure to free mem space.
 * @param text 
 * Destroyed text structure.
 */
void text_destroy(struct Text *text);

/**
 * Draw the text on screen.
 * @param text 
 * The text structure you want to draw.
 */
void text_draw(struct Text *text);




#endif 

