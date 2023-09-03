#ifndef _H_DRAW
#define _H_DRAW

#include "vector.h"

#include <stdint.h>

#define DEFAULT_THICKNESS 5

void draw_line(uint8_t* map, vec2_t start, vec2_t end, uint32_t color);
void draw_line_thickness(uint8_t* map, vec2_t start, vec2_t end, uint32_t color, int thickness);

#endif /* _H_DRAW */


