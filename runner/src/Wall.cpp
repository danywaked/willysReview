#include "Wall.h"

Wall::Wall()
{
	if (!texture.loadFromFile("assets/WhiteHitBrick.png")) {
		return;
	}
	b.sprite.setTexture(texture);
	b.sprite.setColor(sf::Color::Red);

	float x = 0;
	float y = 100;
	for (int i = 0; i < 13; ++i) {
		brickVec.push_back(b);
		brickVec[i].positionX = x;
		brickVec[i].positionY = y;
		x += 100;
		brickVec[i].sprite.setPosition(brickVec[i].positionX, brickVec[i].positionY);
	};
}
	
void Wall::Restart(){
	brickVec.clear();
	float x = 0;
	float y = 100;
	for (int i = 0; i < 13; ++i) {
		brickVec.push_back(b);

		//brick.sprite.setTexture(brickTexture);
		brickVec[i].positionX = x;
		brickVec[i].positionY = y;
		x += 100;
		brickVec[i].sprite.setPosition(brickVec[i].positionX, brickVec[i].positionY);
	};
}