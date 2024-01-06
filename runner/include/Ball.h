#pragma once
#include "batch.hpp"

class Ball 
{
	float positionX;
	float positionY;
public:
	Ball();
	void SetUp(sf::Texture* texture, int rectWidth, int rectHeight, int rectLeft, int rectTop);
	void BallUpdate(float deltatime);
	float Length(const sf::Vector2f& rhs);
	void WorldConstraining(float posX, float posY);
	void Restart();
	sf::IntRect worldBounds;
	sf::Vector2f Normalized(const sf::Vector2f& rhs);
	sf::Sprite m_ballSprite;
	sf::Vector2f m_direction;
	bool hasCollided;
	float m_speed;

};