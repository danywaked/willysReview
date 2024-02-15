#include "Wall.h"

Wall::Wall(std::string_view texturePath)
{
if (!texture.loadFromFile(texturePath.data()))
	{
		throw std::runtime_error(texturePath.data());
	}
	Brick b;
	b.sprite.setTexture(texture);
	b.sprite.setColor(sf::Color::Red);

	float x = 0;
	float y = 100;
	for (int i = 0; i < 13; ++i) {
		//use the Brick constructor! Don't two-step initialize...
		//brickVec.emplace_back(x, y);
		brickVec.push_back(b);
		brickVec[i].positionX = x;
		brickVec[i].positionY = y;
		x += 100;
		brickVec[i].sprite.setPosition(brickVec[i].positionX, brickVec[i].positionY);
	};
}
	
const void Wall::Restart(){
	brickVec.clear();
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