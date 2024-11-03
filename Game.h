#pragma once
#include <raylib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "SpaceShip.h"
#include "Collection.h"
class Game{
    public:
        Game();
        void init();
        void Create();
        void Update();
        void ControlHandler();
        void callBehaviour();
        void SaveResult(const size_t scorePoints);
        void LoadResult(const std::string& s);
        ~Game();
        
    private:
        size_t highestScorePoints;
        size_t scorePoints; 
        SpaceShip ship;
        collection aliens;
};