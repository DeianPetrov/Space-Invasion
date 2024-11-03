#pragma once
#include "Aliens.h"
#include "Laser.h"
class DefAlien : public Aliens{
 public:
Aliens* clone() const override;
 void Behavior() override;
 DefAlien(int num,Vector2 coords); 
 
void Create() override;

};