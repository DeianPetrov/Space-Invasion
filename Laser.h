#pragma once
#include <raylib.h>
#include <iostream>
class Laser{
  public:
  Laser( int speed,Vector2 coords);
  void IncreaseSpeed();
  void Create();//draw
  void Update();
  bool getState() const;
  void AlienUpdate();
  bool StateFlag;
  Rectangle getRect();
  private:
    int speed;
    Vector2 LaserPos;
  
};