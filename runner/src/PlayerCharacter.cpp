#include "PlayerCharacter.h"

Player::Player()
{
	if (!texture.loadFromFile("assets/player.png")) {
		return;
	}
	positionX = 500.0f;
	sprite.setTexture(texture);
	sprite.setPosition(positionX, positionY);
}

void Player::SetWorldConstraints(float min, float max) {
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
	if(positionX >= maxPositionX - 150.0f)
	{
		positionX = maxPositionX - 150.0f;
	}
};

void Player::Restart(){
	positionX = 500.0f;
}