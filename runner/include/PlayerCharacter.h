#pragma once

#include "batch.hpp"

static constexpr float speed = 700.0f;
static constexpr float positionY = 650.0f;
class Player
{
	float positionX = 500.0f;
	float minPositionX = 0.0f;
	float maxPositionX = 0.0f;
	sf::Texture playerTexture;
public:
	Player();
	void SetUp(float min, float max);
	void PlayerUpdate(float deltatime);
	void ProcessingInput(float deltatime);
	void WorldConstrainingOnPositionX();
	void Restart();
	sf::Sprite playerSprite;
	bool pressedLeft = false;
	bool pressedRight = false;
};