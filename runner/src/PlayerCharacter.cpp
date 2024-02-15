#include "PlayerCharacter.h"

Player::Player(std::string_view texturePath)
{
	if (!texture.loadFromFile(texturePath.data()))
	{
		throw std::runtime_error(texturePath.data());
	}
	positionX = 500.0f;
	sprite.setTexture(texture);
	sprite.setPosition(positionX, positionY);
}

const void Player::SetWorldConstraints(float min, float max) {
	minPositionX = min;
	maxPositionX = max;
};

void Player::Update(float deltatime){
	Input(deltatime);
	sprite.setPosition(positionX, positionY);
	WorldConstrain();
};

void Player::Input(float deltatime){
	if(pressedLeft)
	{
		positionX += -speed * deltatime;
	}
	if(pressedRight)
	{
		positionX += speed * deltatime;
	}
};

void Player::WorldConstrain(){
	if(positionX < minPositionX)
	{
		positionX = 0.0f;
	}
	if(positionX >= maxPositionX - sprite.getLocalBounds().width)
	{
		positionX = maxPositionX - sprite.getLocalBounds().width;
	}
};

const void Player::Restart(){
	positionX = 500.0f;
}