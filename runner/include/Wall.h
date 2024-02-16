#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

	//static float positionX = 0.0f;
	//static float positionY = 100.0f;
//
//struct Brick
//{
//	//TODO: remove position. sprite already has position
//	//TODO: add ctor, the brick can't create itself 
//	sf::Sprite sprite;
//};

class Wall
{	
	sf::RenderWindow render;
	sf::Texture texture;
	std::vector<sf::Sprite> brickVec;
public:
	Wall(std::string_view texturePath);
	const size_t WallSize() const noexcept;
	bool WallEmpty();
	void Restart();
	void Render();
};