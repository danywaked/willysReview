#pragma once

#include "batch.hpp"
#include <vector>
struct BrickParts
{
	sf::Sprite sprite;
	float positionX;
	float positionY;
};

class Brick
{
public:
	void SetUp(sf::Texture* texture);
	void Restart();
	void Initialize();
	std::vector<BrickParts> m_brickObject;
private:
	sf::Texture m_texture;

};