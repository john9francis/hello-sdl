#include <SDL2/SDL.h>
#include "player.hh"
#include "inputs.hh"

#include "main.hh"

DevMain devMain;
InputSingleton* inputs;


int main(int argc, char* argv[])
{
  devMain = DevMain();
  devMain.Init();

  // start a singleton
  inputs = InputSingleton::GetInstance();

  // event loop
  while (1){
    // update stuff
    devMain.Update();
    
    inputs->Update();
    if (inputs->quit){
      exit(0);
    }
  }
  return 0;
}