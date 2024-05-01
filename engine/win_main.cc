#include <SDL2/SDL.h>
#include "player.hh"
#include "inputs.hh"


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

int main(int argc, char* argv[])
{

  // start a singleton
  InputSingleton* inputs = InputSingleton::GetInstance();

  Player p = Player();
  const int WIDTH = 640;
  const int HEIGHT = 480;
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  SDL_Rect* rect = initRect(p);

  // event loop
  while (1){
    // update stuff
    inputs->Update();
    if (inputs->quit){
      exit(0);
    }
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

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}