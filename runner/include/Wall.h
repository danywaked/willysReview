#pragma once

#include "batch.hpp"
#include <vector>
struct BrickParts
{
	sf::Sprite sprite;
	float positionX = 0.0f;
	float positionY = 100.0f;
};

class Wall
{
	sf::Texture brickTexture;
public:
	Wall();
	void SetUp();
	void Restart();
	void Initialize();
	std::vector<BrickParts> brickVec;
};