#ifndef FONTS_H_
#define FONTS_H_

extern const unsigned char Font5x7[95][7];
extern const unsigned short int Font10x14[][14];
extern const unsigned char Font16x27[];
extern const unsigned char Font22x40[];
extern const unsigned char Font38x59[];


//draw a 5x7 character with (x, y) being the most top-left corner of the rectangle
//	fontcolour: the colour of the char, checking Colours.h for details
//	c: the character to draw
//	setbg: whether set the background colour of the character
//	bgcolour: background colour of the character
void print_char_5x7(int x, int y, int fontcolour, int c, int setbg, int bgcolour);

//draw a 10x14 character with (x, y) being the most top-left corner of the rectangle
//	fontcolour: the colour of the char, checking Colours.h for details
//	c: the character to draw
//	setbg: whether set the background colour of the character
//	bgcolour: background colour of the character
void print_char_10x14(int x, int y, int fontcolour, int c, int setbg, int bgcolour);

//draw a 16x27 character with (x, y) being the most top-left corner of the rectangle
//	fontcolour: the colour of the char, checking Colours.h for details
//	c: the character to draw
//	setbg: whether set the background colour of the character
//	bgcolour: background colour of the character
void print_char_16x27(int x, int y, int fontcolour, int c, int setbg, int bgcolour);

//draw a 22x40 character with (x, y) being the most top-left corner of the rectangle
//	fontcolour: the colour of the char, checking Colours.h for details
//	c: the character to draw
//	setbg: whether set the background colour of the character
//	bgcolour: background colour of the character
void print_char_22x40(int x, int y, int fontcolour, int c, int setbg, int bgcolour);

//draw a 38x59 character with (x, y) being the most top-left corner of the rectangle
//	fontcolour: the colour of the char, checking Colours.h for details
//	c: the character to draw
//	setbg: whether set the background colour of the character
//	bgcolour: background colour of the character
void print_char_38x59(int x, int y, int fontcolour, int c, int setbg, int bgcolour);


//print a string with specified font size
//	(x, y): string's start position. This is the most top-left corner
//	fontspace: spacing between each char
//	fontcolour: colour of the char
//	string: char array to be printed
//	length: length of the char array
//	setbg: whether set the background colour
//	bgcolour: colour of the background
//	font size available: 5, 10, 16, 22, 38
void print_string(int x, int y, int fontsize, int fontspace, int fontcolour, 
	char string[], int length, int setbg, int bgcolour);

#endif
