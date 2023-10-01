#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class GameWindow { 
private:
    sf::Texture aTexture;
    sf::Texture fxTexture;

    sf::Sprite aSprite;
    sf::Sprite fxSprite;

    sf::RenderWindow window; //= sf::RenderWindow { { WINDOW_WIDTH, WINDOW_HEIGHT }, "UV_Master" };

    int timeIterator = 0;

    bool roundOver = false;
    

public:
    GameWindow();
};