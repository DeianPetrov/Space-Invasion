#pragma once
#include "Aliens.h"
#include "Laser.h"
class NeutralAlien : public Aliens{
 public:
 Aliens* clone() const override;
 void Create() override;
 void Behavior() override;
 NeutralAlien(int num,Vector2 coords);
};