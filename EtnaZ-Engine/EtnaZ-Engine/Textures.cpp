#include "Textures.h"

Textures* Textures::TextureManager = nullptr;

Textures::Textures() {
    loadAllTexture();
}

Textures* Textures::getTexturesManager() {
    if (TextureManager == nullptr) {
        TextureManager = new Textures();
    }
    return TextureManager;
}

void Textures::loadTexture(texturesIndices _index, const char* fileName) {
    sf::Texture texture = sf::Texture();
    auto toto = texture.loadFromFile(fileName);

    auto index = (int)_index;
    if (index >= tabTextures.size())
    {
        tabTextures.resize(index + 1);
    }

    tabTextures[index] = texture;
}

void Textures::loadFont(fontsIndices _index, const char* fileName) {
    sf::Font font(fileName);

    auto index = (int)_index;
    if (index >= tabFonts.size())
    {
        tabFonts.resize(index + 1);
    }

    tabFonts[index] = font;
}

sf::Texture& Textures::getTexture(texturesIndices index) {
    return tabTextures[(int)index];
}

sf::Font& Textures::getFont(fontsIndices index) {
    return tabFonts[(int)index];
}

void Textures::loadAllTexture()
{

    loadTexture(Textures::texturesIndices::sushi_s, "assets/sushi_s.png");
    loadTexture(Textures::texturesIndices::knife, "assets/knife.png");
    loadTexture(Textures::texturesIndices::plate_w, "assets/plate_w.png");


}
