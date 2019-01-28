#include <stdlib.h>
#include "Types.h"
#include "Rectangle.h"
#include "Colours.h"
#include "HWDraw.h"

struct Rectangle *rect_create(int x, int y, int width, int height)
{
	struct Rectangle *rect = malloc(sizeof(struct Rectangle));
	rect->x = (uint16_t)x;
	rect->y = (uint16_t)y;
	rect->width = (uint8_t)width;
	rect->height = (uint8_t)height;
	rect->border_colour = BLACK;
	rect->border_width = 1;
	rect->inner_colour = WHITE;
	rect->filled = TRUE;

	return rect;
}

void rect_destroy(struct Rectangle *rect)
{
	free(rect);
}

void rect_draw(struct Rectangle *rect)
{
	int i;

	uint16_t x = rect->x;
	uint16_t y = rect->y;
	uint8_t width = rect->width;
	uint8_t height = rect->height;
	uint8_t border_width = rect->border_width;
	uint8_t border_colour = rect->border_colour;

	for (i = 0; i < border_width; i ++) {
		//top line
		draw_hline(x, y + i, width, border_colour);
		//bottom line
		draw_hline(x, y - i, width, border_colour);
		//left line
		draw_vline(x + i, y, height, border_colour);
		//right line
		draw_vline(x - i, y, height, border_colour);
	}

	//fill the rectangle
	if (rect->filled && (border_width * 2 < width) && (border_width * 2 < height)) {
		//fill the rectangle with many horizontal lines
		for (i = 0; i < height - 2 * border_width; i ++) {
			draw_hline(x + border_width, y + border_width + i, 
				width - 2 * border_width, border_colour);
		}
	}
}