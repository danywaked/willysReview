#include "Wall.h"

bool Wall::AxisAlignedBoundingBox(sf::Sprite& box1, sf::Sprite& box2)
{
	bool collisionX = box1.getPosition().x + box1.getTexture()->getSize().x >= box2.getPosition().x &&
		box2.getPosition().x + box2.getTexture()->getSize().x >= box1.getPosition().x;

	bool collisionY = box1.getPosition().y + box1.getTexture()->getSize().y >= box2.getPosition().y &&
		box2.getPosition().y + box2.getTexture()->getSize().y >= box1.getPosition().y;
	return collisionX && collisionY;
}

Wall::Wall(std::string_view texturePath)
{
if (!texture.loadFromFile(texturePath.data()))
	{
		throw std::runtime_error(texturePath.data());
	}
	sf::Sprite s;
	s.setTexture(texture);
	s.setColor(sf::Color::Red);

	float x = 0;
	float y = 100;
	for (int i = 0; i < 13; ++i) {
		//use the Brick constructor! Don't two-step initialize...
		//brickVec.emplace_back(x, y);
		brickVec.push_back(s);
		x += 100;
		brickVec[i].setPosition(x,y);
	};
}

const size_t Wall::WallSize() const noexcept
{
	return brickVec.size();
}

bool Wall::CheckCollisionWithBall(sf::Sprite& ballSprite)
{
	/*for (int i = 0; i < brickVec.size(); i++)
	{
		return AxisAlignedBoundingBox(brickVec[i], ballSprite);
	}
	return false;*/
	return false;
}

void Wall::EraseBrick()
{
	for (int i = 0; i < brickVec.size(); i++)
	{
		brickVec.erase(brickVec.begin() + i);

	}
}

bool Wall::WallEmpty()
{
	return brickVec.empty();
}
	
 void Wall::Restart()
{
	brickVec.clear();
	float x = 0;
	float y = 100;
	sf::Sprite s;
	for (int i = 0; i < 13; ++i) {
	
		brickVec.push_back(s);
		x += 100;
		brickVec[i].setPosition(x, y);
	};
}

 void Wall::Render()
 {
	 for (int i = 0; i < brickVec.size(); i++)
	 {
		 render.draw(brickVec[i]);
	 }
 }
