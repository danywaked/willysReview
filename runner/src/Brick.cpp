#include "Brick.h"

void Brick::SetUp(sf::Texture* texture)
{
	m_texture = *texture;
	Initialize();
}
	
void Brick::Restart()
{
	m_brickObject.clear();
	Initialize();
}

void Brick::Initialize()
{
	m_brickObject.resize(13);
	float x = 0;
	float y = 100;
	for (auto& brick : m_brickObject)
	{
		brick.sprite.setTexture(m_texture);
		brick.positionX = x;
		brick.positionY = y;
		x += 100;
		brick.sprite.setPosition(brick.positionX, brick.positionY);
		brick.sprite.setColor(sf::Color::Red);
	};
}