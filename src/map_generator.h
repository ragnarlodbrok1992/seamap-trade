#ifndef _H_MAP_GENERATOR
#define _H_MAP_GENERATOR

#include "color.h"

#include <stdint.h>

#define MAP_X 100
#define MAP_Y 100
#define MAP_UI_BORDER_X 100
#define MAP_UI_BORDER_Y 100

typedef enum MAP_LAYER_e {
  WATER,
  GRASS
} MAP_LAYER;

extern uint8_t* MAP;
extern uint32_t* COLOR_BUFFER;
extern int MAP_HEIGHT;
extern int MAP_WIDTH;

void init_map_size(int screen_width, int screen_height);
void init_map(uint8_t* map);
void generate_map(uint8_t map);
void render_map();

#endif /* _H_MAP_GENERATOR */

