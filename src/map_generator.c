#include "map_generator.h"
#include "display.h"
#include "rand.h"

#include <stdio.h>
#include <stdint.h>

void init_map_size(int screen_width, int screen_height) {
  // Leaving 100 pixel border for now
  MAP_WIDTH  = screen_width - 2 * MAP_UI_BORDER_X; // Times two because we cut both sides...
  MAP_HEIGHT = screen_height - 2 * MAP_UI_BORDER_Y;
}

void init_map(uint8_t* map) {
  MAP_LAYER water = WATER;
  for (int x = 0; x < MAP_WIDTH; x++) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
      map[y * MAP_WIDTH + x] = water;
    }
  }
}

void generate_map(uint8_t* map) {
  // TODO: implement map generation!
  // For now map will be inland sea - so first generate a strip of land around of
  // random thickness.
  (void) map;

  // TODO: implement this for linux
  uint64_t rand_int = get_rand_uint64t();
  rand_int = MAP_LANDSTRIP_MIN + rand_int % MAP_LANDSTRIP_MAX;
  
  MAP_LAYER grass = GRASS;
  // printf("Landstrip thickness: %llu\n", rand_int);
  // Fill landstrip with grass TODO: maybe get some above/grass height there?
  
  // TODO: move this rect map filling to a one function
  // 1. Top rect
  for (int x = 0; x < MAP_WIDTH; x++) {
    for (int y = 0; y < rand_int; y++) {
      set_map_terrain(x, y, grass);
    }
  }

  // 2. Bottom rect
  for (int x = 0; x < MAP_WIDTH; x++) {
    for (int y = MAP_HEIGHT - (int) rand_int; y < MAP_HEIGHT; y++) {
      set_map_terrain(x, y, grass);
    }
  }

  // 3. Left rest-of-the-strip
  for (int x = 0; x < rand_int; x++) {
    for (int y = (int) rand_int; y < MAP_HEIGHT - (int) rand_int; y++) {
      set_map_terrain(x, y, grass);
    }
  }

  // 4. Right rest-of-the-strip
  for (int x = MAP_WIDTH - (int) rand_int; x < MAP_WIDTH; x++) {
    for (int y = (int) rand_int; y < MAP_HEIGHT - (int) rand_int; y++) {
      set_map_terrain(x, y, grass);
    }
  }

}

void render_map() {
  // All is moved 100 pixels
  // TODO: map will not change throught the game, so render it once and then maybe
  // blit it like texture or something?
  for (int x = MAP_X; x < MAP_X + MAP_WIDTH; x++) {
    for (int y = MAP_Y; y < MAP_Y + MAP_HEIGHT; y++) {
      int y_temp = y - MAP_Y;
      int x_temp = x - MAP_X;

      switch (MAP[y_temp * MAP_WIDTH + x_temp]) {
        case WATER:
            draw_pixel(MAP_X + x_temp, MAP_Y + y_temp, BLUE);
          break;
        case GRASS:
            draw_pixel(MAP_X + x_temp, MAP_Y + y_temp, GREEN);
          break;
        default:
          break;
      }
    }
  }
}

