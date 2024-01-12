#pragma once
#include <unordered_map>
#include "batch.hpp"
class AssetsManagement
{
public:
	AssetsManagement() = default;
	~AssetsManagement() = default;
	
	sf::Font m_font;
	bool LoadFontFile(const std::string& filePath);
	sf::Text SetText(std::string textSentence, int size, sf::Uint32 textStyle, float positionX, float positionY) const;

};