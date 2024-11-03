#include "DefAlien.h"
void DefAlien::Behavior() {
  if(health ==0){
        std::cout<<"alive";
    }
   // else std::cout<<"dead";
}
Aliens* DefAlien::clone() const {
    Aliens* obj = new (std::nothrow) DefAlien(*this);
    return obj;
}
DefAlien::DefAlien(int num,Vector2 coords): Aliens(coords,1){
    this->AllienImage = LoadTexture("Graphics/ufo2.png");
    this->health = 3;

}
  
void DefAlien::Create(){
    DrawTextureV(AllienImage,CurrentPos,WHITE);
  }
