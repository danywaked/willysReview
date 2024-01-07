#pragma once

#include "batch.hpp"
#include <vector>
struct BrickParts
{
	sf::Sprite sprite;
	float positionX = 0.0f;
	float positionY = 100.0f;
};

class Brick
{
	sf::Texture brickTexture;
public:
	void SetUp(std::shared_ptr<sf::Texture> texture);
	void Restart();
	void Initialize();
	std::vector<BrickParts> brickVec;
};