#include "Background.h"

Background::Background(std::string_view texturePath)
{
	if (!texture.loadFromFile(texturePath.data()))
	{
		throw std::runtime_error(texturePath.data());
	}
	star.sprite.setTexture(texture);
	float x = MARGIN_X;
	float y = -100;
	for(int i = 0; i < 4; i++)
	{
	/*	stars.push_back(star);
		stars[i].positionY = y;
		stars[i].sprite.setPosition(x,y);       
		x += 350;
		stars[i].sprite.setScale(0.5f, 0.5f);*/
		x += 350;
		
		//stars.emplace_back(x, y, (i < 4) ? 0.5f : 0.3f);
		
		//	stars.push_back(Star(x, y, 0.5f));
		
	}
	y = -300;
	x = 250;

	for (int i = 4; i < 7; i++)
	{
		stars.push_back(star);
		stars[i].positionY = y;
		stars[i].sprite.setPosition(x, y);
		x += 350;
		stars[i].sprite.setScale(0.3f, 0.3f);
	}
}

void Background::Update(float deltatime){
	fallingSpeed = 125;
	for (int i = 0; i < 4; i++)
	{
		 stars[i].sprite.setPosition(stars[i].sprite.getPosition().x, stars[i].positionY += fallingSpeed * deltatime);
		fallingSpeed += 25;
	}
	fallingSpeed = 100;
	for (int i = 4; i < stars.size(); i++)
	{
		stars[i].sprite.setPosition(stars[i].sprite.getPosition().x, stars[i].positionY += fallingSpeed * deltatime);
		fallingSpeed -= 15;
	}
}
