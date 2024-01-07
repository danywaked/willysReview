#pragma once
#include "batch.hpp"
	
float Length(const sf::Vector2f& rhs);
sf::Vector2f Normalized(const sf::Vector2f& rhs);

class Ball 
{
	float positionX = 500.0f;
	float positionY = 400.0f;
public:
	void SetUp(std::shared_ptr<sf::Texture>  texture, int rectWidth, int rectHeight, int rectLeft, int rectTop);
	void BallUpdate(float deltatime);
	void WorldConstraining(float posX, float posY);
	void Restart();
	sf::IntRect worldBounds;
	sf::Sprite ballSprite;
	sf::Vector2f direction{positionX,positionY};
	float speed = 200.0f;

};