// entrypoint for writing your own logic

#include "main.hh"
#include <iostream>

int DevMain::Init() {
  // put your initialization logic here
  std::cout << "Initialized" << std::endl;
  return 0;
}

int DevMain::Update() {
  // put your update logic here
  std::cout << "Updating" << std::endl;
  return 0;
}