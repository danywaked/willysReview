#include "AssetsManagment.h"

std::unordered_map < std::string, sf::Text*> m_text;

bool AssetsManagement::LoadFontFile(const std::string& filePath){
    if(m_font.loadFromFile(filePath))
    {
        return true;
    }
    return false;
}

sf::Text AssetsManagement::SetText(std::string textSentence, int size, sf::Uint32 textStyle, float positionX, float positionY) const{
    sf::Text text;
    text.setFont(m_font);
    text.setCharacterSize(size);
    text.setStyle(textStyle);
    text.setPosition(positionX, positionY);
    text.setString(textSentence);
    return text;
}