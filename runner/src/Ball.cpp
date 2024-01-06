#include "Ball.h"

float Length(const sf::Vector2f& rhs)
{
	return std::sqrtf(rhs.x * rhs.x + rhs.y * rhs.y);
};

sf::Vector2f Normalized(const sf::Vector2f& rhs) {
	float length = 1.0f / Length(rhs);
	float x = rhs.x * length;
	float y = rhs.y * length;
	return sf::Vector2f{ x, y };
}

Ball::Ball()
{
	speed = 200.0f;
	hasCollided = false;
	positionX = 500.0f;
	positionY = 400.0f;
	m_direction.x = positionX;
	m_direction.y = positionY;
};

void Ball::SetUp(sf::Texture* texture, int rectWidth, int rectHeight, int rectLeft, int rectTop)
{
	m_ballSprite.setTexture(*texture);
	m_ballSprite.setPosition(positionX, positionY);
	m_ballSprite.setScale(1.0f, 1.0f);
	worldBounds.width = rectWidth;
	worldBounds.height = rectHeight;
	worldBounds.left = rectLeft;
	worldBounds.top = rectTop;
};

void Ball::BallUpdate(float deltatime)
{
	WorldConstraining(positionX, positionY);
	m_direction = Normalized(m_direction);
	positionX += m_direction.x * speed * deltatime;
	positionY += m_direction.y * speed * deltatime;
	m_ballSprite.setPosition(positionX, positionY);
};

void Ball::WorldConstraining(float posX, float posY)
{
	if (posX < (float)worldBounds.left)
	{
		m_direction.x = -m_direction.x;
	}
	if (posX >= (float)worldBounds.width - 50)
	{
		m_direction.x = -m_direction.x;
	}
	if (posY < (float)worldBounds.top)
	{
		m_direction.y = -m_direction.y;
	}
}

void Ball::Restart()
{
	positionX = 500.0f;
	positionY = 400.0f;
	m_direction.x = positionX;
	m_direction.y = positionY;
	speed = 200.0f;
}