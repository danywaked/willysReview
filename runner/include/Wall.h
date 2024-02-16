#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

	//static float positionX = 0.0f;
	//static float positionY = 100.0f;
//
//struct Brick
//{
//	//TODO: remove position. sprite already has position
//	//TODO: add ctor, the brick can't create itself 
//	sf::Sprite sprite;
//};

bool AxisAlignedBoundingBox(sf::Sprite& box1, sf::Sprite& box2)
{
	bool collisionX = box1.getPosition().x + box1.getTexture()->getSize().x >= box2.getPosition().x &&
		box2.getPosition().x + box2.getTexture()->getSize().x >= box1.getPosition().x;

	bool collisionY = box1.getPosition().y + box1.getTexture()->getSize().y >= box2.getPosition().y &&
		box2.getPosition().y + box2.getTexture()->getSize().y >= box1.getPosition().y;
	return collisionX && collisionY;
}

class Wall
{	
	sf::RenderWindow render;
	sf::Texture texture;
	std::vector<sf::Sprite> brickVec;
public:
	Wall(std::string_view texturePath);
	const size_t WallSize() const noexcept;

	void CheckPlayerCollision();

	bool WallEmpty();
	void Restart();
	void Render();
};