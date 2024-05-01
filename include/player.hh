#include <iostream>

#ifndef PLAYER_HH
#define PLAYER_HH

class Player{
public:
  Player();

  void Update();
  void SetMovingLeft(bool movingLeft){moving_left = movingLeft;};
  void SetMovingRight(bool movingRight){moving_right = movingRight;};
  void SetMovingUp(bool movingUp){moving_up = movingUp;};
  void SetMovingDown(bool movingDown){moving_down = movingDown;};

  int GetX(){return x;};
  int GetY(){return y;};
  int GetWidth(){return width;};
  int GetHeight(){return height;}

private:
  int x;
  int y;
  int width;
  int height;

  bool moving_left;
  bool moving_right;
  bool moving_up;
  bool moving_down;

  int speed;
};

#endif