#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "player.h"

class GameWindow { 
private:
    sf::Texture aTexture;
    sf::Texture fxTexture;

    sf::Sprite aSprite;
    sf::Sprite fxSprite;

    sf::RenderWindow window; //= sf::RenderWindow { { WINDOW_WIDTH, WINDOW_HEIGHT }, "UV_Master" };

    Player player;

    int timeIterator = 0;

    bool roundOver = false;
    

public:
    GameWindow();
    void runGame();
};