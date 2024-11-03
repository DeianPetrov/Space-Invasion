#include "Collection.h"
void collection::AddAliens(){
   
    for(int row = 0; row < 5; row++) {
        for(int column = 0; column < 11; column++) {
            int random = rand() % 3;
            float x = 75 + column * 55;
            float y = 110 + row * 55;
     
		    aliens[AliensCount++] = AlienFactory(random,{x,y});
        }
    }

}

void collection::free(){
   for(size_t i = 0 ;i<AliensCount;i++){
    delete aliens[i];
   }
   delete[] aliens;
}

size_t collection:: getSize() const{
    return size;
}

void collection::copyFrom(const collection& other)
{
	aliens = new Aliens*[other.size];
	AliensCount = other.AliensCount;
	size = other.size;

	for (size_t i = 0; i < AliensCount; i++)
	{
		Aliens* cloned =  other.aliens[i]->clone();
		if (cloned)
			aliens[i] = cloned;
	}
}

void collection::moveFrom(collection&& other)
{
	AliensCount = other.AliensCount;
	size = other.size;

	aliens = other.aliens;
	other.aliens = nullptr;

	other.AliensCount = other.size = 0;
}

void collection::resize()
{
	Aliens** newCollection = new Aliens * [size *= 2];
	for (size_t i = 0; i < AliensCount; i++)
		newCollection[i] = aliens[i]; // !!не правим клониране
	delete[] aliens;
	aliens = newCollection;
}


collection::collection()
{
	size = 64;
	AliensCount = 0;
	aliens = new Aliens * [size];
}

collection::collection(const collection& other)
{
	copyFrom(other);
}

collection& collection::operator=(const collection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

collection::~collection()
{
	free();
}

collection::collection(collection&& other) noexcept
{
	moveFrom(std::move(other));
}

collection& collection::operator=(collection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void collection::DRAW(){
	for( size_t i = 0 ; i<AliensCount;i++){
		if(aliens[i]!=nullptr){
		aliens[i]->Create();
		}else {
           
        }
	}
}

void collection::MoveDownAliens(int distance) {
    for (size_t i = 0; i < AliensCount; i++) {
        aliens[i]->CurrentPos.x += distance*aliensDirection; 
    }
}


void collection::MoveAliens() {
	bool changeDirection = false;
	for (size_t i = 0; i < AliensCount; i++) {
		if (aliens[i]->CurrentPos.x + CONSTANTS::myImageWidth > GetScreenWidth() - 40) {
			aliensDirection = -1;
			changeDirection = true;
		}
		if (aliens[i]->CurrentPos.x < 20) {
			aliensDirection = 1;
			changeDirection = true;
		}
		aliens[i]->Update(aliensDirection);
	}
	if(changeDirection) {
    	MoveDownAliens(4);
	}
}

void collection::CallBehaviour(){
	for(size_t i=0;i<AliensCount;i++){
		if(aliens[i]!=nullptr){
		aliens[i]->Behavior();
	}
	}
}

bool collection::isEmpty() const
{	
	for (size_t i = 0; i < AliensCount; i++) {
    	if(aliens[i]!=nullptr){
			return false;
		}	
	}
	return true;
}

int collection::GetTypeFromID(size_t id) const
{
    return aliens[id]->GetType();
}

size_t collection::checkForCollision(SpaceShip& sp)//collide the lasers from the ship with the aliens
 {
	size_t totalPoints = 0; 
    for (size_t i = 0; i < AliensCount; i++) {
        aliens[i]->colideWithShip(sp.LaserShots); // Check for collision
        if (aliens[i]->isDestroyed()==true) {
			//std::cout<<" SEcod ";
            totalPoints += aliens[i]->GiveScoreOnKill(); 
            delete aliens[i];  
            aliens[i] = nullptr;  
        }
    }
    return totalPoints; 
}
