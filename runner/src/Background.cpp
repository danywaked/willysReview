#include "Background.h"

Background::Background()
{
	if (!texture.loadFromFile("assets/FallingStar.png")) {
		return;
	}
	star.sprite.setTexture(texture);
	float x = 100;
	float y = -100;
	for(int i = 0; i < 4; i++)
	{
		stars.push_back(star);
		stars[i].positionY = y;
		stars[i].sprite.setPosition(x,y);       
		x += 350;
		stars[i].sprite.setScale(0.5f, 0.5f);
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
