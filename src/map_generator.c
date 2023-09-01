#include "map_generator.h"
#include "display.h"

void init_map_size(int screen_width, int screen_height) {
  // Leaving 100 pixel border for now
  MAP_WIDTH  = screen_width - MAP_UI_BORDER_X;
  MAP_HEIGHT = screen_height - MAP_UI_BORDER_Y;
}

void init_map(uint8_t* map) {
  MAP_LAYER water = WATER;
  for (int x = 0; x < MAP_WIDTH; x++) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
      map[y * MAP_WIDTH + x] = water;
    }
  }
}

void generate_map(uint8_t map) {
  // TODO: implement map generation!

}

void render_map() {
  // All is moved 100 pixels
  // TODO: map will not change throught the game, so render it once and then maybe
  // blit it like texture or something?
  for (int x = MAP_X; x < MAP_WIDTH; x++) {
    for (int y = MAP_Y; y < MAP_HEIGHT; y++) {
      int y_temp = y - MAP_Y;
      int x_temp = x - MAP_X;

      switch (MAP[y_temp * MAP_WIDTH + x_temp]) {
        case WATER:
            draw_pixel(MAP_X + x_temp, MAP_Y + y_temp, BLUE);
          break;
        case GRASS:
            draw_pixel(MAP_X + x_temp, MAP_Y + y_temp, GRASS);
          break;
        default:
          break;
      }
    }
  }
}

