#include <raylib.h>
#include "AttackAlien.h"
#include "Game.h"
#include "CONSTANTS.h"
int main(){

    InitAudioDevice();
    InitWindow(CONSTANTS::myscreenWidth,CONSTANTS::myscreenHeight,"Space Incursion");

    Texture2D background = LoadTexture("Graphics/background(1).png");
    SetTargetFPS(60);

    Game g;
    
    while(WindowShouldClose()==false){
         
        g.ControlHandler();
        g.Update();
       
        BeginDrawing();
        DrawTextureRec(background,CONSTANTS::myframe,CONSTANTS::myBackgroundPos,WHITE);

        ClearBackground(GRAY);

        g.Create();
          
        EndDrawing();

    }
    CloseWindow();
    return 0;
}