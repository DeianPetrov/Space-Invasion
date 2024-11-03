#include "NeutralAlien.h"

 void NeutralAlien::Behavior(){
    if(health ==0){
        std::cout<<"alive";
    }
    //else std::cout<<"dead";
 }
 NeutralAlien::NeutralAlien(int num,Vector2 coords):Aliens(coords,num){
  this->AllienImage = LoadTexture("Graphics/ufo3.png");
  this->health = 1;

 }
 //NeutralAlien::~NeutralAlien();
 Aliens* NeutralAlien::clone() const {
    Aliens* obj = new (std::nothrow) NeutralAlien(*this);
    return obj;
 }

 
  void NeutralAlien::Create(){
    DrawTextureV(AllienImage,CurrentPos,WHITE);

  }

