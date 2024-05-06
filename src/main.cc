// entrypoint for writing your own logic

#include "main.hh"
#include <iostream>

int DevMain::Init() {
  // put your initialization logic here
  std::cout << "Initialized" << std::endl;

  player = new Player();
  viewer = new Viewer();
  return 0;
}

int DevMain::Update() {
  // put your update logic here
  std::cout << "Updating" << std::endl;

  player->Update();

  viewer->OpenRender();
  player->Render(viewer->GetRenderer());
  viewer->CloseRender();
  return 0;
}