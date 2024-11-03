#include "Laser.h"
#include "Aliens.h"

Laser::Laser(int speed,Vector2 coords){
    this->speed = speed;
    this->LaserPos.x = coords.x;
    
    this->LaserPos.y = coords.y;
    this->StateFlag = true;
}

void Laser::Create(){
    if(StateFlag){
        DrawRectangle(LaserPos.x+30,LaserPos.y,4, 15,{ 254, 76 ,38,255});
    }
}

void Laser::IncreaseSpeed(){
    this->speed*= 0.25;
}

Rectangle Laser::getRect(){
    Rectangle rect;
    rect.x = LaserPos.x;
    rect.y = LaserPos.y;
    rect.width = 4;
    rect.height = 15;
    return rect;
}

void Laser::Update(){
  LaserPos.y += speed;
  if(StateFlag){
    if(LaserPos.y > GetScreenHeight() ||LaserPos.y<0){
        this->StateFlag = false;
    }
  }
}

void Laser::AlienUpdate(){
  LaserPos.y -= speed;
  if(StateFlag){
    if(LaserPos.y > GetScreenHeight() ||LaserPos.y<0){
        this->StateFlag = false;
    }
  }
}

bool Laser::getState() const{
  return StateFlag;
}
