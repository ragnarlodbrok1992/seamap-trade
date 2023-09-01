#include "display.h"
#include "vector.h"
#include "utility.h"
#include "color.h"
#include "map_generator.h"

// Static variables
SDL_Window*   WINDOW   = NULL;
SDL_Renderer* RENDERER = NULL;

// Forward declarations

// Engine variables
const char*   TITLE          = "3D Graphics Programming From Scratch.";
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

  // Some tutorial setup
  // row 10 column 20 to color blue
  // This array is row first
  // pixel format = A R G B
  // COLOR_BUFFER[(WINDOW_WIDTH * 10) + 20] = 0xFF0000FF;

  // Setting up cube of points
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
  render_rectangle(20, 20, 100, 100, PURPLE);

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
  printf("MAP_LAYER.WATER: %u", MAP_LAYER.WATER);

  ENGINE_RUNNING = initialize_window();

  // Main engine loop
  setup();

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

