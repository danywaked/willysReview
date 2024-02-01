#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
struct Brick
{
	sf::Sprite sprite;
	float positionX = 0.0f;
	float positionY = 100.0f;
};

class Wall
{
	Brick b;
	sf::Texture texture;
public:
	Wall();
	const void Restart();
	std::vector<Brick> brickVec;
};