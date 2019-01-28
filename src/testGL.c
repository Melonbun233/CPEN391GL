#include "CPEN391GL.h"
#include <stdio.h>

int main(void)
{
	printf("Starting...\n");
	int i;

	//test rectangle
	struct Rectangle *rect = rect_create(0, 0, 30, 10);
	for (i = 0; i < 800; i += 10) {
		rect->x = i;
		rect->y = i;
		rect->width = 3 * i;
		rect->height = i;
		rect->border_width = i/50;
		rect->border_colour = i/5;
		rect->inner_colour = i/10;
		rect_draw(rect);
	}
//
//    //top-left corner
//    draw_hline(0, 0, 20, WHITE);
//    draw_vline(0, 0, 20, WHITE);
//    draw_line(0, 0, 20, 20, WHITE);
//
//    //top-right corner
//    draw_hline(780, 0, 20, WHITE);
//    draw_vline(799, 0, 20, WHITE);
//    draw_line(799, 0, 780, 20, WHITE);
//
//    // //bottom-left corner
//    draw_hline(0, 479, 20, WHITE);
//    draw_vline(0, 460, 20, WHITE);
//    draw_line(0, 479, 20, 460, WHITE);
//
//    // //bottom-right corner
//    draw_hline(780, 479, 20, WHITE);
//    draw_vline(799, 460, 20, WHITE);
//    draw_line(799, 479, 780, 460, WHITE);
//
//    // //middle
//    draw_hline(1, 241, 798, WHITE);
//    draw_hline(1, 239, 798, WHITE);
//    draw_line(0, 240, 800, 240, WHITE);
//    draw_vline(401, 1, 478, WHITE);
//    draw_vline(399, 1, 478, WHITE);
//    draw_line(400, 0, 400, 480, WHITE);
//
//    draw_line(0, 0, 0, 0, RED);
//    draw_line(0, 479, 0, 479, RED);
//    draw_hline(799, 0, 1, RED);
//    draw_vline(799, 479, 1, RED);
//
//    for (i = 0; i < 800; i ++) {
//    	draw_line(400, 240, i, 0, i/10);
//    	draw_line(i, 479, 400, 240, i/10);
//    }
//
//    for (i = 0; i < 480; i ++) {
//    	draw_line(400, 240, 0, i, i/10);
//    	draw_line(799, i, 400, 240, i/10);
//    }
//    draw_line(400, 240, 799, 479, i/10);
//
//    char text1[] = "Hello";
//    char text2[] = "World!";
//    //some texts
//    print_string(50, 50, 10, 4, WHITE, text1, 5, 0, BLACK);
//    print_string(100, 100, 5, 3, WHITE, text2, 6, 1, BLACK);
//
//    print_string(500, 100, 16, 3, WHITE, text1, 5, 0, BLACK);
//    print_string(600, 100, 16, 3, WHITE, text2, 6, 1, BLACK);
//
//    print_string(100, 300, 22, 3, WHITE, text1, 5, 1, BLACK);
//    print_string(200, 400, 22, 3, WHITE, text2, 6, 0, BLACK);
//
//    print_string(500, 300, 38, 3, WHITE, text1, 5, 0, BLACK);
//    print_string(550, 400, 38, 3, WHITE, text2, 6, 1, BLACK);

    printf("Done...\n");
    return 0 ;
}

