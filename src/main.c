#include "display.h"
#include "vector.h"
#include "utility.h"
#include "color.h"
#include "map_generator.h"

// Static variables
SDL_Window*   WINDOW   = NULL;
SDL_Renderer* RENDERER = NULL;
uint8_t* MAP           = NULL;
int MAP_WIDTH          = -1;
int MAP_HEIGHT         = -1;

// Forward declarations

// Engine variables
const char*   TITLE          = "SeaMap-Trade.";
bool          ENGINE_RUNNING = false;

// Camera stuff
vec3_t CAMERA_POSITION = { .x = 0.0f, .y = 0.0f, .z = -5.0f};

// Projection variables
float FOV_FACTOR = 640;

// Global buffers
uint32_t* COLOR_BUFFER            = NULL; 
SDL_Texture* COLOR_BUFFER_TEXTURE = NULL;

void setup(void) {
  // Allocating required bytes for COLOR_BUFFER
  COLOR_BUFFER = (uint32_t*) malloc(sizeof(uint32_t) * WINDOW_WIDTH * WINDOW_HEIGHT);

  COLOR_BUFFER_TEXTURE = SDL_CreateTexture(
      RENDERER,
      SDL_PIXELFORMAT_ARGB8888,
      SDL_TEXTUREACCESS_STREAMING,
      WINDOW_WIDTH,
      WINDOW_HEIGHT
  );

  // Setting up map
  MAP = (uint8_t*) malloc(sizeof(uint8_t) * MAP_WIDTH * MAP_HEIGHT);
}

void process_input(void) {
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type) {
    case SDL_QUIT:
      ENGINE_RUNNING = false;
      break;
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE) ENGINE_RUNNING = false;
      break;
  }
}

void update(void) {
  // TODO:
}

void render(void) {
  // Projection?
  // TEST
  // render_rectangle(20, 20, 100, 100, MAGENTA);
  render_map();

  // Final render of the collor buffer
  render_color_buffer();
  clear_color_buffer(0xFF000000);

  // Last render call
  SDL_RenderPresent(RENDERER);
}


int main(int argc, char* argv[])
{
  // Remove warning about unused variables
  // TODO: parse config file here in the future
  (void)argc;
  (void)argv;

  // DEBUG
  // MAP_LAYER water = WATER;
  // printf("MAP_LAYER.WATER: %u\n", water);

  ENGINE_RUNNING = initialize_window();

  // Initializing map
  init_map_size(WINDOW_WIDTH, WINDOW_HEIGHT);
  setup();

  // Main engine loop
  while (ENGINE_RUNNING) {
    process_input();
    update();
    render();
  }

  teardown();

  // Last message - so everything went well
  printf("Goodbye.\n");
  return 0;
}

