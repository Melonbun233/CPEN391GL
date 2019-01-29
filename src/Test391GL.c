#include "CPEN391GL.h"
#include <stdio.h>

#define SWITCHES    (volatile unsigned int *)(0xFF200000)

#define HLINE_MASK 			1
#define	VLINE_MASK 			2
#define ALINE_MASK			4
#define RECTANGLE_MASK 		8
#define TRIANGLE_MASK 		16
#define TEXT_MASK			32
#define FILL_MASK			512

void test_hline(void)
{
	int i;
	for (i = 0; i < 480; i ++){
		draw_hline(0, i, 800, i/10);
	}
	printf("hline test done\n");
}

void test_vline(void)
{
	int i;
	for(i = 0; i < 800; i ++){
		draw_vline(i, 0, 480, i/10);
	}
	printf("vline test done\n");
}

void test_aline(void)
{
	int i;

	for (i = 0; i < 800; i ++) {
	    draw_line(400, 240, i, 0, i/10);
	    draw_line(i, 479, 400, 240, i/10);
	}

	for (i = 0; i < 480; i ++) {
	    draw_line(400, 240, 0, i, i/10);
	    draw_line(799, i, 400, 240, i/10);
	}
	draw_line(400, 240, 799, 479, i/10);

	printf("aline test done\n");
}

void test_rect(void)
{
	int i, switches;
	struct Rectangle *rect = rect_create(0, 0, 10, 10);
	for(i = 0; i < 800; i += 10) {
		switches = *SWITCHES;
		rect->x = i;
		rect->y = i;
		rect->width = i;
		rect->height = i/3;
		rect->border_colour = i;
		rect->border_width = i%3 + 1;
		rect->inner_colour = i/2;
		rect->filled = (switches & FILL_MASK) ? TRUE : FALSE;
		rect_draw(rect);
	}
	rect_destroy(rect);
	printf("rectangle test done\n");
}

void test_trig(void)
{
	int i, switches;
	struct Triangle *trig = trig_create(0, 0, 0, 0, 0, 0);
	for(i = 0; i < 300; i += 10) {
		switches = *SWITCHES;
		trig->x1 = (50 + i);
		trig->y1 = (50 + 2 * i);
		trig->x2 = (30 + 1.2 * i);
		trig->y2 = (30 + i);
		trig->x3 = (70 + 1.5 * i);
		trig->y3 = (10 + i);
		trig->border_colour = i/5;
		trig->inner_colour = i/10;
		trig->filled = (switches & FILL_MASK) ? TRUE : FALSE;
		trig_draw(trig);
	}
	trig_destroy(trig);
	printf("triangle test done\n");
}

void test_text(void)
{
	char content[] = "Hello World!";
	struct Text *text = text_create(50, 50, content, 10, 4, RED);

	text_draw(text);

	text->x = 100;
	text->y = 100;
	text->font_size = 5;
	text->font_colour = YELLOW;
	text_draw(text);

	text->x = 100;
	text->y = 450;
	text->font_size = 10;
	text->font_colour = BLACK;
	text_draw(text);

	text->x = 500;
	text->y = 100;
	text->font_size = 16;
	text->font_colour = CYAN;
	text_draw(text);

	text->x = 100;
	text->y = 300;
	text->font_size = 22;
	text->font_colour = LIGHT_SALMON;
	text_draw(text);

	text->x = 500;
	text->y = 300;
	text->font_size = 38;
	text->font_colour = POWDER_BLUE;
	text_draw(text);

	text_destroy(text);
	printf("text test done\n");
}

int main(void)
{
	int old_switches = 0;
	int new_switches;
	clear_screen(WHITE);

	while (1) {
		new_switches = *SWITCHES;

		//start test after any switch changes
		if (old_switches != new_switches) {
			clear_screen(WHITE);

			if (new_switches & HLINE_MASK)
				test_hline();
			if (new_switches & VLINE_MASK)
				test_vline();
			if (new_switches & ALINE_MASK)
				test_aline();
			if (new_switches & RECTANGLE_MASK)
				test_rect();
			if (new_switches & TRIANGLE_MASK)
				test_trig();
			if (new_switches & TEXT_MASK)
				test_text();

			old_switches = new_switches;
			printf("ready for next setting\n");
		}
	}

    return 0;
}

