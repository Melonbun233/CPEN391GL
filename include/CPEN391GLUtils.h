//This file contains all CPEN391 GL utility functions

#ifndef CPEN391GL_UTILS_H
#define CPEN391GL_UTILS_H


//check if the point (x, y) can be displayed (within the boundary)
int check_boundary(int x, int y);

//Fill a shape with fill colour
//The point (x, y) should be a pixel in the shape
void fill_shape(int x, int y, int fill_colour, int border_colour);


#endif