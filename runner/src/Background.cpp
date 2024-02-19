#include "Background.h"

Background::Background(const std::string_view texturePath)
{
	if (!texture.loadFromFile(texturePath.data()))
	{
		throw std::runtime_error(texturePath.data());
	}
	sprite.setTexture(texture);
	float y = -100;

	for(int i = 0; i < 4; i++)
	{
		sf::Vector2f pos(i * 150.0f, -100.0f);
		starPositions.push_back(pos);
		sprite.setScale(0.5f, 0.5f);
	}
	for (int i = 4; i < 7; i++)
	{
		sf::Vector2f pos(i * 150.0f, -100.0f);
		starPositions.push_back(pos);
		sprite.setScale(0.3f, 0.3f);
	}
}

void Background::Render() 
{
	for (auto& position : starPositions)
	{
		sprite.setPosition(position);
		render.draw(sprite);
	}
}

void Background::Update(float deltatime){
	fallingSpeed = 125;
	for (int i = 0; i < 4; i++)
	{
		 starPositions[i].y += fallingSpeed * deltatime;
		fallingSpeed += 25;
	}
	fallingSpeed = 100;
	for (int i = 4; i < starPositions.size(); i++)
	{
		starPositions[i].y += fallingSpeed * deltatime;
		fallingSpeed -= 15;
	}
}
