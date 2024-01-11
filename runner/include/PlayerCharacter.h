#pragma once

#include "batch.hpp"

static constexpr float speed = 700.0f;
static constexpr float positionY = 650.0f;
class Player
{
	float positionX = 500.0f;
	float minPositionX = 0.0f;
	float maxPositionX = 0.0f;
	sf::Texture texture;
public:
	Player();
	void SetWorldConstraints(float min, float max);
	void Update(float deltatime);
	void Input(float deltatime);
	void WorldConstrain();
	void Restart();
	sf::Sprite sprite;
	bool pressedLeft = false;
	bool pressedRight = false;
};