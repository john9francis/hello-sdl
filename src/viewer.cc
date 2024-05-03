#include "viewer.hh"

Viewer* Viewer::instance = nullptr;

Viewer* Viewer::GetInstance(){
  if (!instance){
    instance = new Viewer();
  }
  return instance;
}

Viewer::Viewer(){
  const int WIDTH = 640;
  const int HEIGHT = 480;
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Viewer::~Viewer(){

}