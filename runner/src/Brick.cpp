#include "Brick.h"

void Brick::SetUp(sf::Texture* texture){
	brickTexture = *texture;
	Initialize();
}
	
void Brick::Restart(){
	brickVec.clear();
	Initialize();
}

void Brick::Initialize(){
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