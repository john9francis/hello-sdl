#include "player.hh"

Player::Player(){
  std::cout << "Hello, Player!" << std::endl;

  x = 10;
  y = 10;
  width = 50;
  height = 25;
  speed = 10;

  moving_up = false;
  moving_down = false;
  moving_left = false;
  moving_right = false;
}

void Player::Update(){
  if (moving_down){
    y += speed;
  }
  if (moving_up){
    y -= speed;
  }
  if (moving_left){
    x -= speed;
  }
  if (moving_right){
    x += speed;
  }
}