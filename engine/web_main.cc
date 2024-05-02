#include <SDL2/SDL.h>
#include "player.hh"
#include "inputs.hh"

#include "main.hh"

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

// TODO: Declare global (to this file) variables
Player p;
const int WIDTH = 640;
const int HEIGHT = 480;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Rect* rect;
bool quit = false;
InputSingleton* inputs;


SDL_Rect* initRect(Player& p){
  // create a rect
  SDL_Rect* rect = new SDL_Rect();
  rect->x = p.GetX();
  rect->y = p.GetY();
  rect->w = p.GetWidth();
  rect->h = p.GetHeight();

  return rect;
}

void updateRectPos(SDL_Rect* rect, Player& p){
  rect->x = p.GetX();
  rect->y = p.GetY();
}


// TODO: void init to initialize all those global vars
void init(){
  DevMain::Init();

  #ifdef __EMSCRIPTEN__
  std::cout << "found emscripten!" << std::endl;
  #else
  std::cout << "couldn't find emscripten" << std::endl;
  #endif

  p = Player();

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  rect = initRect(p);

  inputs = InputSingleton::GetInstance();
}

// TODO: void mainloop to define the stuff to happen every loop.
void mainloop(){
  DevMain::Update();

  if(quit){
    #ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();
    #endif
  }

  // update stuff
  inputs->Update();
  p.Update();
  updateRectPos(rect, p);

  // Set render color to black
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // draw rect
  SDL_SetRenderDrawColor(renderer, 255, 150, 255, 2);
  SDL_RenderFillRect(renderer, rect);
  SDL_RenderDrawRect(renderer, rect);

  // display on viewer
  SDL_RenderPresent(renderer);
  SDL_Delay(16);
}




int main(int argc, char* argv[])
{
  init();

  // event loop
  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(mainloop, 0, 1);
  #endif

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}