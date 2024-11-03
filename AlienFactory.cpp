#include <raylib.h>
#include "Aliens.h"
#include "AttackAlien.h"
#include "DefAlien.h"
#include "NeutralAlien.h"
Aliens* AlienFactory(int type,Vector2 coord){
   switch(type){
    case 1:
      return new AttackAlien(1,coord);
    case 2:
      return new NeutralAlien(2,coord);
    case 0:
    return new DefAlien(0,coord);
   }
   return nullptr;
}