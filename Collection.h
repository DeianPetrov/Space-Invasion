#pragma once
#include <raylib.h>
#include "Aliens.h"
#include <Spaceship.h>
#include <vector>
#include <iostream>
#include "AlienFactory.h"
#include "CONSTANTS.h"
class collection{
  private:
  Aliens** aliens; 
  size_t size;
  size_t AliensCount;
  int aliensDirection=-1;
  void free();
  void copyFrom(const collection& other);
  void moveFrom(collection&& other);
  // i wont use move semantics
  public:
  collection();
  size_t getSize() const;
  void AddAliens();
  collection(const collection& other);
  collection(collection&&other) noexcept;
  collection& operator=(collection&& other) noexcept;
  collection& operator=(const collection& other);
  ~collection();

 void SetDirection();
 bool isEmpty() const; 
 int GetTypeFromID(size_t id)const;
 void CallBehaviour();
 void resize();
 void DRAW();
 void MoveAliens();
 void MoveDownAliens(int distance);
 void DrawAttackLasers();
 size_t checkForCollision(SpaceShip& sp);
};