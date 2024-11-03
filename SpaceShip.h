#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>
#include "Laser.h"
class SpaceShip{
    public:
        SpaceShip();
        ~SpaceShip();
        void Fire();
        void SetShip();
        void MoveFront();
        void MoveRight();
        void MoveBack();
        void MoveLeft();
        std::vector<Laser>& GetLaser();
        std::vector<Laser> LaserShots;
        Rectangle getRect();

    private:
        Sound laserSound;
        Vector2 CurrentPos;
        Texture2D shipImage;
        double FiredTime;
};