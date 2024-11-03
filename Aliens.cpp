#include "Aliens.h"

Aliens::Aliens(Vector2 coords,int type):type(type), CurrentPos(coords){
}
const int Aliens::GetType() const{
  return type;
}
const Vector2  Aliens::GetCoords() const{
  return CurrentPos;
}

void Aliens::Update(int movement){
  CurrentPos.x += movement;
}
Rectangle Aliens::GetRect() const
{
    return {CurrentPos.x, CurrentPos.y,
    float(AllienImage.width),
    float(AllienImage.height)
    };
}
Aliens::~Aliens(){
 UnloadTexture(AllienImage);
}
size_t Aliens:: GiveScoreOnKill() const{
  if(isDestroyed()){
    switch(type){
      case 1: 
      UnloadTexture(AllienImage);
      return 300;
      
      case 2: UnloadTexture(AllienImage);
      return 200;
      case 3: UnloadTexture(AllienImage);
      return 100;
      default: 
      return 0;

    }
  }else return 0;
}
bool Aliens::isDestroyed() const{
  if(health>0) return false; 
  else return true;
}

void Aliens::colideWithShip( std::vector<Laser>&laser) 
{
  for(int i = 0 ;i<laser.size();i++){
   // Rectangle alienRect = { this->CurrentPos.x, this->CurrentPos.y, CurrentPos.x + CONSTANTS::myImageWidth,
     //CurrentPos.y + CONSTANTS::myscreenHeight}; // Adjust width and height as needed
   // if(laser[i].getRect().x==this->CurrentPos.x&& laser[i].getRect().y==this->CurrentPos.y){
   //    this->health--;
   // }
   //if( CheckCollisionRecs(laser[i].getRect(),alienRect)){
  //  this->health --;
   // laser.erase(laser.begin()+i);
  //  i--;
   }

  

}
