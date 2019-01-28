#include "CPEN391GLUtils.h"
#include "CPEN391GL.h"
#include "Types.h"

int check_boundary(int x, int y)
{
	if ((short)(x) >= (short)(XRES) || (short)(y) >= (short)(YRES) ||
		(short)(x) < (short)(0) || (short)(y) < (short)(0))
		return FALSE;
	else
		return TRUE;
}