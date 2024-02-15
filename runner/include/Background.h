#pragma once
#include <SFML/Graphics.hpp>
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
	Background(std::string_view texturePath);
	void Update(float deltatime);
};