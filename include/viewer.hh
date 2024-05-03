#ifndef VIEWER_HH
#define VIEWER_HH

#include <SDL2/SDL.h>

class Viewer{
public:
  static Viewer* GetInstance();

private:
  Viewer();
  ~Viewer();

  static Viewer* instance;
};

#endif