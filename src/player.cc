#include "player.hh"

Player::Player(){
  std::cout << "Hello, Player!" << std::endl;

  x = 10;
  y = 10;
  width = 50;
  height = 25;
  speed = 10;

  inputs = InputSingleton::GetInstance();

  moving_up = false;
  moving_down = false;
  moving_left = false;
  moving_right = false;
}

void Player::Update(){
  if (inputs->s_down){
    y += speed;
  }
  if (inputs->w_down){
    y -= speed;
  }
  if (inputs->a_down){
    x -= speed;
  }
  if (inputs->d_down){
    x += speed;
  }
}