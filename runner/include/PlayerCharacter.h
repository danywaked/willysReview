#pragma once

#include "batch.hpp"

class PlayerCharacter
{
	const float defualtMovmentSpeed;
	const float positionY;
	float positionX;
	float minPositionX;
	float maxPositionX;
public:
	PlayerCharacter();
	void SetUp(sf::Texture* texture, float min, float max);
	void PlayerUpdate(float deltatime);
	void ProcessingInput(float deltatime);
	void WorldConstrainingOnPositionX();
	void Restart();
	sf::Sprite m_playerSprite;
	bool pressedLeft;
	bool pressedRight;
};