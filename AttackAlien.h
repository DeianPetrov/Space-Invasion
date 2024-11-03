#pragma once
#include "Aliens.h"
#include "Laser.h"
#include <vector>
#include <iostream>
#include <SpaceShip.h>
class AttackAlien : public Aliens{
public:
 Aliens* clone() const override;
 void Create() override;
 void Behavior() override;
 AttackAlien(int num, Vector2 coords);
 void DrawAlienLaser();
 bool CollideWithShip() const;
private:
 std::vector<Laser> alienLasers;
 constexpr static float alienLaserShootInterval = 0.35;
 float timeLastAlienFired;
 double FiredTime;
};