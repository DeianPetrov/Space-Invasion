#include "Game.h"


Game::Game(){
    init();
}
void Game::init(){
    aliens.AddAliens();
    LoadResult("highScore.txt");
    //aliens.DRAW();

}
void Game::Create(){//draw
        scorePoints=0;
        ship.SetShip();
        for(auto& l : ship.LaserShots){
            l.Create();
        }
        aliens.DRAW();
        aliens.CallBehaviour();
        aliens.MoveAliens();
}
void Game::ControlHandler(){
    if(IsKeyDown(KEY_A)){
        ship.MoveLeft();
    }
     if(IsKeyDown(KEY_W)){
        ship.MoveFront();
    }
     if(IsKeyDown(KEY_S)){
        ship.MoveBack();
    }
     if(IsKeyDown(KEY_D)){
        ship.MoveRight();
    }
     if(IsKeyDown(KEY_SPACE)){
        ship.Fire();
        
    }
}
void Game::Update(){
    for(auto& l : ship.LaserShots){
            l.Update();
    }
    aliens.CallBehaviour();
    aliens.checkForCollision(ship);//-----> doesnt work for now
  
    aliens.MoveAliens();
}
void Game::SaveResult(const size_t scorePoints){
    std::ofstream ofs;
    ofs.open("highScore.txt");
    if(!ofs.is_open()){
        std::cerr<<"cant open the file";
        return ;
    }
    if(scorePoints> highestScorePoints){
        ofs << scorePoints;
    }
    ofs.close();
}
void Game::LoadResult(const std::string& filename){
    std::ifstream ifs(filename);
    if(!ifs.is_open()){
        std::cerr<<"cant open the file";
        return;
    }
    if(ifs.tellg()==0){
        highestScorePoints = 0 ;
        
    }else{
        ifs>> highestScorePoints;
    }
    ifs.close();
}

Game::~Game(){

}
