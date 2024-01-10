#include "ParallaxBackground.h"

void parallaxBackground::SetUp(std::shared_ptr<sf::Texture> texture){
	if (!texture) {
		return;
	}
	m_texture = *texture;
	m_fallingStarYellow.resize(4);
	m_fallingStarRed.resize(3);
	float x = 100;
	float y = -100;
	for(int i = 0; i < m_fallingStarYellow.size(); i++)
	{
		m_fallingStarYellow[i].sprite.setTexture(m_texture);
		m_fallingStarYellow[i].color = sf::Color::Yellow;
		m_fallingStarYellow[i].positionX = x;
		m_fallingStarYellow[i].positionY = y;
		x += 350;
		m_fallingStarYellow[i].sprite.setPosition(m_fallingStarYellow[i].positionX, m_fallingStarYellow[i].positionY);
		m_fallingStarYellow[i].sprite.setScale(0.5f, 0.5f);
		m_fallingStarYellow[i].sprite.setColor(m_fallingStarYellow[i].color); //TODO: why hold
	}
	y = -300;
	x = 250;
	for (int i = 0; i < m_fallingStarRed.size(); i++)
	{
		m_fallingStarRed[i].sprite.setTexture(m_texture);
		m_fallingStarRed[i].color = sf::Color::Red;
		m_fallingStarRed[i].positionX = x;
		m_fallingStarRed[i].positionY = y;
		x += 350;
		m_fallingStarRed[i].sprite.setPosition(m_fallingStarRed[i].positionX, m_fallingStarRed[i].positionY);
		m_fallingStarRed[i].sprite.setScale(0.3f, 0.3f);
		m_fallingStarRed[i].sprite.setColor(m_fallingStarRed[i].color);
	}
}

void parallaxBackground::Update(float deltatime){
	float fallingSpeed = 125;
	for (int i = 0; i < m_fallingStarYellow.size(); i++)
	{
		m_fallingStarYellow[i].sprite.setPosition(m_fallingStarYellow[i].positionX, m_fallingStarYellow[i].positionY += fallingSpeed * deltatime);
		fallingSpeed += 25;
	}
	fallingSpeed = 100;
	for (int i = 0; i < m_fallingStarRed.size(); i++)
	{
		m_fallingStarRed[i].sprite.setPosition(m_fallingStarRed[i].positionX, m_fallingStarRed[i].positionY += fallingSpeed * deltatime);
		fallingSpeed -= 15;
	}
}