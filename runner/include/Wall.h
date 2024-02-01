#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
struct Brick
{
	//TODO: remove position. sprite already has position
	//TODO: add ctor, the brick can't create itself 
	sf::Sprite sprite;
	float positionX = 0.0f;
	float positionY = 100.0f;
};

class Wall
{	
	sf::Texture texture;
	
public:
	Wall();
	void Restart();
	std::vector<Brick> brickVec; //TODO: make this private, give wall the interface the rest of th eapplication needs instead
	
};