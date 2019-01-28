/*
 * Fonts.c
 *
 *  Created on: Jan 22, 2019
 *      Author: Henry Zeng
 */
#include "Fonts.h"
#include "CPEN391GL.h"
#include "CPEN391GLUtils.h"

//check if the character is printable
static int check_printable(int c)
{
	if(((short)(c) >= (short)(' ')) && ((short)(c) <= (short)('~')))
		return 1;
	else
		return 0;
}

void print_string(int x, int y, int fontsize, int fontspace, int fontcolour, 
	char string[], int length, int setbg, int bgcolour) {

	register int index;
	for (index = 0; index < length; index ++) {
		switch (fontsize) {
			case 5 :
				print_char_5x7(x + 5 * index + fontspace * index, y,
					fontcolour, string[index], setbg, bgcolour);
				break;
			case 10:
				print_char_10x14(x + 10 * index + fontspace * index, y,
					fontcolour, string[index], setbg, bgcolour);
				break;
			case 16:
				print_char_16x27(x + 16 * index + fontspace * index, y,
					fontcolour, string[index], setbg, bgcolour);
				break;
			case 22:
				print_char_22x40(x + 22 * index + fontspace * index, y,
					fontcolour, string[index], setbg, bgcolour);
				break;
			case 38:
				print_char_38x59(x + 38 * index + fontspace * index, y,
					fontcolour, string[index], setbg, bgcolour);
		}
	}
}

void print_char_5x7(int x, int y, int fontcolour, int c, int setbg, int bgcolour)
{
	register int row, column;
	register int pixels;
	register int mask;

	if (check_printable(c)) {
		c = c - 0x20;

		//since 5x7 fonts, we only have 7 rows
		for (row = 0; (char)(row) < (char)(7); row ++) {
			pixels = Font5x7[c][row];
			mask = 16;
			for (column = 0; (char)(column) < (char)(5); column ++) {

				//draw the pixel if it's within the boundary
				if ((pixels & mask) && check_boundary(x + column, y + row)) {
					write_pixel(x + column, y + row, fontcolour);
				}

				//whether set char's background colour
				else if (setbg){
					write_pixel(x + column, y + row, bgcolour);
				}

				mask = mask >> 1;
			}
		}
	}

}

void print_char_10x14(int x, int y, int fontcolour, int c, int setbg, int bgcolour)
{
	register int row, column;
	register int pixels;
	register int mask;

	if(check_printable(c)) {
		c = c - 0x20;
		//10x14 font has 14 rows for each char
		for(row = 0; row < 14; row ++) {
			pixels = Font10x14[c][row];
			mask = 512;
			//10x14 font has 10 columns for each char
			for(column = 0; column < 10; column ++) {

				//checking if the pixel is within the boundary
				if ((pixels & mask) && check_boundary(x + column, y + row)){
					write_pixel(x + column, y + row, fontcolour);
				}

				else if (setbg) {
					write_pixel(x + column, y + row, bgcolour);
				}
				mask = mask >> 1;
			}
		}
	}
}


void print_char_16x27(int x, int y, int fontcolour, int c, int setbg, int bgcolour)
{
	register int row, column;
	register int pixels;
	register int mask;
	register int start_index;

	if(check_printable(c)) {
		c = c - 0x20;
		//each row has two data for pixels
		start_index = c * 27 * 2;
		//27 rows
		for(row = 0; row < 27; row ++) {
			//draw first 8 pixels of this row
			pixels = Font16x27[start_index + row * 2];
			mask = 128;
			for (column = 0; column < 8; column ++) {

				//checking if the pixel is within the boundary
				if ((pixels & mask) && check_boundary(x + column, y + row)){
					write_pixel(x + column, y + row, fontcolour);
				}

				else if (setbg) {
					write_pixel(x + column, y + row, bgcolour);
				}
				mask = mask >> 1;
			}
			//draw last 8 pixels of this row
			pixels = Font16x27[start_index + row * 2 + 1];
			mask = 128;
			for (column = 0; column < 8; column ++) {

				//checking if the pixel is within the boundary
				if ((pixels & mask) && check_boundary(x + column + 8, y + row)){
					write_pixel(x + column + 8, y + row, fontcolour);
				}

				else if (setbg) {
					write_pixel(x + column + 8, y + row, bgcolour);
				}
				mask = mask >> 1;
			}
		}
	}
}

void print_char_22x40(int x, int y, int fontcolour, int c, int setbg, int bgcolour)
{
	register int row, column;
	register int pixels;
	register int mask;
	register int start_index;
	if (check_printable(c)) {
		c = c - 0x20;
		//each row has three data
		start_index = c * 40 * 3;
		for (row = 0; row < 40; row ++) {
			//draw the first data
			pixels = Font22x40[start_index + row * 3];
			mask = 128;
			for (column = 0; column < 8; column ++) {

				//checking if the pixel is within the boundary
				if ((pixels & mask) && check_boundary(x + column, y + row)){
					write_pixel(x + column, y + row, fontcolour);
				}

				else if (setbg) {
					write_pixel(x + column, y + row, bgcolour);
				}
				mask = mask >> 1;
			}
			//draw the second data
			pixels = Font22x40[start_index + row * 3 + 1];
			mask = 128;
			for (column = 0; column < 8; column ++) {

				//checking if the pixel is within the boundary
				if ((pixels & mask) && check_boundary(x + column + 8, y + row)){
					write_pixel(x + column + 8, y + row, fontcolour);
				}

				else if (setbg) {
					write_pixel(x + column + 8, y + row, bgcolour);
				}
				mask = mask >> 1;
			}
			//draw the third data
			pixels = Font22x40[start_index + row * 3 + 2];
			mask = 128;
			for (column = 0; column < 8; column ++) {

				//checking if the pixel is within the boundary
				if ((pixels & mask) && check_boundary(x + column + 16, y + row)){
					write_pixel(x + column + 16, y + row, fontcolour);
				}

				else if (setbg) {
					write_pixel(x + column + 16, y + row, bgcolour);
				}
				mask = mask >> 1;
			}
		}
	}
}

void print_char_38x59(int x, int y, int fontcolour, int c, int setbg, int bgcolour)
{
	register int row, column;
	register int pixels;
	register int mask;
	register int start_index;
	if (check_printable(c)) {
		c = c - 0x20;
		//each row has four data
		start_index = c * 59 * 4;
		for (row = 0; row < 59; row ++) {
			//draw the first data
			pixels = Font38x59[start_index + row * 4];
			mask = 128;
			for (column = 0; column < 8; column ++) {

				//checking if the pixel is within the boundary
				if ((pixels & mask) && check_boundary(x + column, y + row)){
					write_pixel(x + column, y + row, fontcolour);
				}

				else if (setbg) {
					write_pixel(x + column, y + row, bgcolour);
				}
				mask = mask >> 1;
			}
			//draw the second data
			pixels = Font38x59[start_index + row * 4 + 1];
			mask = 128;
			for (column = 0; column < 8; column ++) {

				//checking if the pixel is within the boundary
				if ((pixels & mask) && check_boundary(x + column + 8, y + row)){
					write_pixel(x + column + 8, y + row, fontcolour);
				}

				else if (setbg) {
					write_pixel(x + column + 8, y + row, bgcolour);
				}
				mask = mask >> 1;
			}
			//draw the third data
			pixels = Font38x59[start_index + row * 4 + 2];
			mask = 128;
			for (column = 0; column < 8; column ++) {

				//checking if the pixel is within the boundary
				if ((pixels & mask) && check_boundary(x + column + 16, y + row)){
					write_pixel(x + column + 16, y + row, fontcolour);
				}

				else if (setbg) {
					write_pixel(x + column + 16, y + row, bgcolour);
				}
				mask = mask >> 1;
			}
			//draw the fourth data
			pixels = Font38x59[start_index + row * 4 + 3];
			mask = 128;
			for (column = 0; column < 8; column ++) {

				//checking if the pixel is within the boundary
				if ((pixels & mask) && check_boundary(x + column + 24, y + row)){
					write_pixel(x + column + 24, y + row, fontcolour);
				}

				else if (setbg) {
					write_pixel(x + column + 24, y + row, bgcolour);
				}
				mask = mask >> 1;
			}
		}
	}
}
