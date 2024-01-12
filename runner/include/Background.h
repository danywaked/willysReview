#pragma once
#include "batch.hpp"
#include <vector>

static float fallingSpeed = 125;
struct Star
{
	sf::Sprite sprite;
	float positionY = 0;
};

class Background
{
	sf::Texture texture;
	Star star;
public:
	std::vector<Star> stars;
	Background();
	void Update(float deltatime);
};