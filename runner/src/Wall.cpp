#include "Wall.h"

Wall::Wall(std::string_view texturePath)
{
if (!texture.loadFromFile(texturePath.data()))
	{
		throw std::runtime_error(texturePath.data());
	}
	sf::Sprite s;
	s.setTexture(texture);
	s.setColor(sf::Color::Red);

	float x = 0;
	float y = 100;
	for (int i = 0; i < 13; ++i) {
		//use the Brick constructor! Don't two-step initialize...
		//brickVec.emplace_back(x, y);
		brickVec.push_back(s);
		x += 100;
		brickVec[i].setPosition(x,y);
	};
}

const size_t Wall::WallSize() const noexcept
{
	return brickVec.size();
}

bool Wall::WallEmpty()
{
	return brickVec.empty();
}
	
 void Wall::Restart()
{
	brickVec.clear();
	float x = 0;
	float y = 100;
	float x = 0;
	float y = 100;
	sf::Sprite s;
	for (int i = 0; i < 13; ++i) {
	
		brickVec.push_back(s);
		x += 100;
		brickVec[i].setPosition(x, y);
	};
}

 void Wall::Render()
 {
	 for (int i = 0; i < brickVec.size(); i++)
	 {
		 render.draw(brickVec[i]);
	 }
 }
