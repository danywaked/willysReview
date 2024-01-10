#include "PlayerCharacter.h"

void PlayerCharacter::SetUp(std::shared_ptr<sf::Texture> texture, float min, float max){
	//Thinking is easier to read if I set variables in a SetUp class
	minPositionX = min;
	maxPositionX = max;
	positionX = 500.0f;
	if (!texture) {
		return;
	}
	playerSprite.setTexture(*texture);
	playerSprite.setPosition(positionX, positionY);
	playerSprite.setScale(1.0f, 0.5f);
};

void PlayerCharacter::PlayerUpdate(float deltatime){
	ProcessingInput(deltatime);
	playerSprite.setPosition(positionX, positionY);
	WorldConstrainingOnPositionX();
};

void PlayerCharacter::ProcessingInput(float deltatime){
	if(pressedLeft)
	{
		positionX += -speed * deltatime;
	}
	if(pressedRight)
	{
		positionX += speed * deltatime;
	}
};

void PlayerCharacter::WorldConstrainingOnPositionX(){
	if(positionX < minPositionX)
	{
		positionX = 0.0f;
	}
	if(positionX >= maxPositionX - 150.0f)
	{
		positionX = maxPositionX - 150.0f;
	}
};

void PlayerCharacter::Restart(){
	positionX = 500.0f;
}