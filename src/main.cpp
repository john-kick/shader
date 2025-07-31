#include "Figures/Sphere.h"
#include "Scene.h"
#include <SDL2/SDL.h>
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void loop() {}

bool initSDL(SDL_Window *&window, SDL_Renderer *&renderer) {
  int initStatus = SDL_Init(SDL_INIT_VIDEO);
  if (initStatus < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << '\n';
    return false;
  }

  SDL_Window *window = SDL_CreateWindow("Shader", SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
  if (!window) {
    std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError()
              << '\n';
    SDL_Quit();
    return false;
  }

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError()
              << '\n';
    SDL_DestroyWindow(window);
    SDL_Quit();
    return false;
  }
}

int main() {
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;
  if (!initSDL(window, renderer)) {
    return 1;
  }

  Scene scene;
  auto sphere = std::make_unique<Sphere>();
  sphere->x = 400;
  sphere->y = 300;
  sphere->radius = 50.0f;
  scene.addFigure(std::move(sphere));

  bool running = true;
  while (running) {
    loop();
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}

#include "Scene.h"