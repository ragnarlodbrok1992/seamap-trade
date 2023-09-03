#include "draw.h"

void draw_line_with_thickness(uint8_t* map, vec2_t start, vec2_t end, uint32_t color, int thickness);


void draw_line(uint8_t* map, vec2_t start, vec2_t end, uint32_t color) {
  draw_line_with_thickness(map, start, end, color, DEFAULT_THICKNESS);
}

void draw_line_with_thickness(uint8_t* map, vec2_t start, vec2_t end, uint32_t color, int thickness) {
  // TODO: implement line drawing algorithm
  // from this source: https://www.geeksforgeeks.org/mid-point-line-generation-algorithm/
  (void) map;
  (void) start;
  (void) end;
  (void) color;
  (void) thickness;

}

