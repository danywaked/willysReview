#pragma once

#include "batch.hpp"
#include <vector>
struct BrickParts
{
	sf::Sprite sprite;
	float positionX;
	float positionY;
};

class Brick
{
	sf::Texture brickTexture;
public:
	void SetUp(sf::Texture* texture);
	void Restart();
	void Initialize();
	std::vector<BrickParts> brickVec;
};