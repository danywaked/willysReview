#include "Ball.h"
#include <stdexcept>


float Length(const sf::Vector2f& rhs){
	return std::sqrtf(rhs.x * rhs.x + rhs.y * rhs.y);
};

sf::Vector2f Normalized(const sf::Vector2f& rhs) {
	float length = 1.0f / Length(rhs);
	float x = rhs.x * length;
	float y = rhs.y * length;
	return sf::Vector2f{ x, y };
}

Ball::Ball(std::string_view texturePath)
{
	if (!texture.loadFromFile(texturePath.data()))
	{
		throw std::runtime_error(texturePath.data());
	}
	ballSprite.setTexture(texture);
	ballSprite.setPosition(positionX, positionY);
}

const void Ball::SetUp(int rectWidth, int rectHeight, int rectLeft, int rectTop)
{
	worldBounds.width = rectWidth;
	worldBounds.height = rectHeight;
	worldBounds.left = rectLeft;
	worldBounds.top = rectTop;
}

void Ball::BallUpdate(float deltatime){
	WorldConstraining(positionX, positionY);
	direction = Normalized(direction);
	positionX += direction.x * speed * deltatime;
	positionY += direction.y * speed * deltatime;
	ballSprite.setPosition(positionX, positionY);
};

void Ball::WorldConstraining(float posX, float posY){
	if (posX < (float)worldBounds.left)
	{
		direction.x = -direction.x;
	}
	if (posX >= (float)worldBounds.width - 50)
	{
		direction.x = -direction.x;
	}
	if (posY < (float)worldBounds.top)
	{
		direction.y = -direction.y;
	}
}

const void Ball::Restart(){
	positionX = 500.0f;
	positionY = 400.0f;
	direction.x = positionX;
	direction.y = positionY;
	speed = 200.0f;
}