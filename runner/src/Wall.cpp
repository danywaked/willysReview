#include "Wall.h"

Wall::Wall()
{
	if (!brickTexture.loadFromFile("assets/WhiteHitBrick.png")) {
		return;
	}
}

void Wall::SetUp(){
	Initialize();
}
	
void Wall::Restart(){
	brickVec.clear();
	Initialize();
}

void Wall::Initialize(){
	brickVec.resize(13);
	float x = 0;
	float y = 100;
	for (auto& brick : brickVec)
	{
		brick.sprite.setTexture(brickTexture);
		brick.positionX = x;
		brick.positionY = y;
		x += 100;
		brick.sprite.setPosition(brick.positionX, brick.positionY);
		brick.sprite.setColor(sf::Color::Red);
	};
}