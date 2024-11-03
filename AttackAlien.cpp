#include "AttackAlien.h"

Aliens* AttackAlien::clone() const {
    Aliens* obj = new (std::nothrow) AttackAlien(*this);
    return obj;
}
void AttackAlien::Behavior(){
    int currentTime = GetTime();
    if (currentTime - timeLastAlienFired >= alienLaserShootInterval) {
        alienLasers.push_back(Laser(4, {CurrentPos.x - 30 + AllienImage.width / 2, CurrentPos.y + AllienImage.height}));
        timeLastAlienFired = currentTime;  
    }
    DrawAlienLaser();
    for (auto& laser : alienLasers) {
        laser.Update();
    }
}
void AttackAlien::DrawAlienLaser(){
    for (auto& laser : alienLasers) {
        if(laser.getState()){
            laser.Create();
        }  // Assuming `Create` draws the laser on the screen
    } 
}

 
AttackAlien::AttackAlien(int type,Vector2 coords) : Aliens(coords,1),timeLastAlienFired(GetTime()){
    this->AllienImage = LoadTexture("Graphics/ufo1.png");
    this->health = 1; 
    if (AllienImage.id == 0) {
        std::cerr << "Failed to load texture 'Graphics/ufo1.png'" << std::endl;
    }

}
void AttackAlien::Create(){
    DrawTextureV(AllienImage,CurrentPos,WHITE);
}
