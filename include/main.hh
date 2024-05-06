#ifndef DEV_MAIN_HH
#define DEV_MAIN_HH

#include "viewer.hh"
#include "player.hh"

class DevMain {
public:
  int Init();
  int Update();

  Viewer* viewer;
  Player* player;
};


#endif