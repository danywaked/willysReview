#pragma once
#include <unordered_map>
#include "batch.hpp"
class AssetsManagement
{
public:
	AssetsManagement() = default;
	~AssetsManagement() = default;
	
	static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_textures;  //TODO: unique_ptr
	static std::vector<std::string> m_order;
	sf::Font m_font;
	bool LoadFontFile(const std::string& filePath);
	//Need to use LoadFontFile() first before using SetText();
	sf::Text SetText(std::string textSentence, int size, sf::Uint32 textStyle, float positionX, float positionY) const;
	std::shared_ptr<sf::Texture> GetByName(std::string name); //TODO: return (non-owning) raw ptr or const&
	std::shared_ptr<sf::Texture> GetByIndex(int index);
	std::shared_ptr<sf::Texture> LoadTexture(const std::string& name, const std::string& path);
};