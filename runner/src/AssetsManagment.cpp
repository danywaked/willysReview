#include "AssetsManagment.h"
std::vector<std::string> AssetsManagement::m_order;
std::unordered_map<std::string, std::shared_ptr<sf::Texture>> AssetsManagement::m_textures;
bool AssetsManagement::LoadFontFile(const std::string& filePath){
    if(!m_font.loadFromFile(filePath))
    {
        printf("Font failed to load from file path");
        return false;
    }
    return true;
}

sf::Text AssetsManagement::SetText(std::string textSentence, int size, sf::Uint32 textStyle, float positionX, float positionY) const{
    sf::Text text;
    //Have m_font as defualt font.
    text.setFont(m_font);
    text.setCharacterSize(size);
    text.setStyle(textStyle);
    text.setPosition(positionX, positionY);
    text.setString(textSentence);
    return text;
}

int AssetsManagement::GetLength(){
    int size = static_cast<int>(m_textures.size());
	return size;
}

std::shared_ptr<sf::Texture> AssetsManagement::GetByName(std::string name){
    auto it = m_textures.find(name);
    if (it != m_textures.end()) {
        return it->second;
    }
    return nullptr;
}

std::shared_ptr<sf::Texture> AssetsManagement::GetByIndex(int index){
    // Stay DRY and reuse get by name, but get string name from vector with index
    return GetByName(m_order.at(index));
}

//sf::Texture* AssetsManagement::LoadTexture(std::string name, std::string path)
//{
//    // Haven't loaded it yet, time to create it
//    sf::Texture* texture = new sf::Texture();
//    if (!texture->loadFromFile(path))
//    {
//        return nullptr;
//    }
//    m_textures[name] = texture;
//    // Push to vector the order in which items were loaded into map, for accessing via index.
//    m_order.push_back(name);
//    return m_textures[name];
//} 
//Assign a Texture a Name (for accessing via get) and path (to load from)
std::shared_ptr<sf::Texture>  AssetsManagement::LoadTexture(const std::string& name, const std::string& path) {
    auto texture = std::make_shared<sf::Texture>();
    if (texture->loadFromFile(path)) {
        auto insertionResult = m_textures.emplace(name, texture);
        if (insertionResult.second) {
            m_order.push_back(name);
            return insertionResult.first->second;
        }
    }
    return nullptr;
}