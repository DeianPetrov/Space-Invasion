#include "SpaceShip.h"
#include <vector>
#include "Laser.h"
SpaceShip::SpaceShip(){
  shipImage = LoadTexture("Graphics/Ship.png");
  CurrentPos.x= (GetScreenWidth() - shipImage.width) / 2;
  CurrentPos.y =(GetScreenHeight() - shipImage.height) / 1.5;
  FiredTime = 0.0;
  laserSound = LoadSound("sounds/lasershot.ogg");
}
void SpaceShip::MoveBack(){
    if((CurrentPos.y +10)<650){
        CurrentPos.y+=10;
    }
    else return;
}
void SpaceShip::MoveFront(){
    if((CurrentPos.y +10)>400){
        CurrentPos.y-=10;
    }
    else return;
}
void SpaceShip::MoveLeft(){
    if((CurrentPos.x -10)>0){
        CurrentPos.x-=10;
    }
    else return;
}
void SpaceShip::MoveRight(){
    if((CurrentPos.x +10)<700){
        CurrentPos.x+=10;
    }
    else return;
}
void SpaceShip::SetShip(){
  DrawTextureV(shipImage,CurrentPos,WHITE);
}
void SpaceShip::Fire(){
    if(GetTime() - FiredTime >=0.35){
        LaserShots.push_back(Laser(-6,{(CurrentPos.x -4) ,CurrentPos.y}));
        FiredTime = GetTime();
        PlaySound(laserSound);
    } 

}
Rectangle SpaceShip::getRect()
{
    Rectangle rect;
    rect.x = CurrentPos.x;
    rect.y = CurrentPos.y;
    //rect.width =;
    rect.width = shipImage.width;
    rect.height = shipImage.height;
    return rect;
}
SpaceShip::~SpaceShip(){
    UnloadTexture(shipImage);
    UnloadSound(laserSound);
}
std::vector<Laser>& SpaceShip::GetLaser(){
    return this->LaserShots;
} 