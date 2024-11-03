#pragma once
#include <raylib.h>
#include <iostream>
#include <Laser.h>
#include <CONSTANTS.H>
#include <vector>
class Aliens{
  public:
  Aliens(Vector2 coords,int type);
  virtual void Behavior()=0;
  virtual void Update(int movement);
  virtual void Create() = 0;
  const int GetType() const;
  Rectangle GetRect() const;
  const Vector2 GetCoords() const; 
  virtual Aliens* clone() const=0;
  virtual ~Aliens();
  size_t GiveScoreOnKill() const;
  bool isDestroyed() const;
  void colideWithShip( std::vector<Laser>& laser) ;

  private:
  int type;
  protected:
  Texture2D AllienImage;
  int health=1;
  public:
  Vector2 CurrentPos;   
};