#pragma once

#include "batch.hpp"
#include <vector>
struct BrickParts
{
	sf::Sprite sprite;
	sf::Color color;
	float positionX;
	float positionY;
};

class Brick
{
public:
	void SetUp(sf::Texture* texture);
	void Restart();
	std::vector<BrickParts> m_brickObject;
private:
	sf::Texture m_texture;

};