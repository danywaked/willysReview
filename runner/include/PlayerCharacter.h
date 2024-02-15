#pragma once

#include <SFML/Graphics.hpp>

static constexpr float speed = 700.0f;
static constexpr float positionY = 650.0f;
class Player
{
	float positionX = 500.0f;
	float minPositionX = 0.0f;
	float maxPositionX = 0.0f;
	sf::Texture texture;
public:
	sf::Sprite sprite;
	Player(std::string_view texturePath);
	const void SetWorldConstraints(float min, float max);
	void Update(float deltatime);
	void Input(float deltatime);
	void WorldConstrain();
	const void Restart();
	bool pressedLeft = false;
	bool pressedRight = false;
};