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



class Wall
{	
	sf::RenderWindow render;
	sf::Texture texture;
	std::vector<sf::Sprite> brickVec;

	bool AxisAlignedBoundingBox(sf::Sprite& box1, sf::Sprite& box2);
public:
	Wall(const std::string_view texturePath);

	const size_t WallSize() const noexcept;
	bool CheckCollisionWithBall(sf::Sprite& ballSprite);
	void EraseBrick();
	bool WallEmpty();
	void Restart();
	void Render();
};