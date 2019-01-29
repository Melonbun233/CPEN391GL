#include <stdlib.h>
#include "Triangle.h"
#include "Types.h"
#include "Colours.h"
#include "HWDraw.h"
#include "Fill.h"


struct Triangle *trig_create(int x1, int y1, int x2, int y2, int x3, int y3)
{
	struct Triangle *trig = malloc(sizeof(struct Triangle));
	trig->x1 = (uint16_t) x1;
	trig->x2 = (uint16_t) x2;
	trig->x3 = (uint16_t) x3;
	trig->y1 = (uint16_t) y1;
	trig->y2 = (uint16_t) y2;
	trig->y3 = (uint16_t) y3;

	trig->border_colour = BLACK;
	trig->border_width = 1;
	trig->inner_colour = WHITE;
	trig->filled = TRUE;

	return trig;
}

void trig_destroy(struct Triangle *trig)
{
	free(trig);
}

void trig_draw(struct Triangle *trig)
{
	int x1 = trig->x1, x2 = trig->x2, x3 = trig->x3;
	int y1 = trig->y1, y2 = trig->y2, y3 = trig->y3;

	//center point used for filling
	int center_x;
	int center_y;

	draw_line(x1, y1, x2, y2, trig->border_colour);
	draw_line(x2, y2, x3, y3, trig->border_colour);
	draw_line(x3, y3, x1, y1, trig->border_colour);

	if (trig->filled) {
		fill_shape(center_x, center_y, trig->inner_colour, trig->border_colour);
	}
}