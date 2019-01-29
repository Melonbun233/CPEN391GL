# CPEN391GL
CPEN391 graphics library
Please DON'T try some extreme or strange values... This library is not fully tested...

## Installing
All source files are in src/ directory, and all header files are in /include directory.
## Usage
Simply
```
#include "CPEN391GL.h"
```

## Supported Features
I will improve these later.
### Hardware Accelerated Functions
* Draw a single pixel   
``` 
void write_pixel(int x, int y, int colour) 
```
* Draw a horizontal line   
``` 
void draw_hline(int x1, int y1, int length, int colour) 
```
* Draw a vertical line   
```
void draw_vline(int x1, int y1, int length, int colour) 
```
* Draw a line between any two points   
``` 
void draw_line(int x1, int y1, int x2, int y2, int colour) 
```

Functions directly use special hardware graphic acceleration for faster drawing.
These functions are faster than drawing pixel by pixel.  
Refer to ``` include/HWDraw.h ``` for details.

### Triangle
Drawing triangles with specified attributes.  
Refer to ``` include/Triangle.h ``` for details.  
NOTE: Currently, all three points have to be inside the screen. Border width is not supported neither.

### Rectangle
Drawing rectangles with specified attributes.
Refer to ``` include/Rectangle.h ``` for details.

### Fonts
Displaying texts on screen.
Refer to ``` include/Fonts.h ``` for details.

### Colours
Some colour constants are defined in ``` include/Colours.h ```.  
Those constants should be used when you want to set any colour in this library.
Please refer to ``` include/HWDraw.h: program_palette() ``` if you want to set a special color, or simply change
``` Colours.h ```.



