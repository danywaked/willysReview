#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

static float fallingSpeed = 125;

class Background
{
	sf::RenderWindow render;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	std::vector<sf::Vector2f> starPositions;
	Background(const std::string_view texturePath);
	void Render();
	void Update(float deltatime);
};