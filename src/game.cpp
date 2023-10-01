#include <ios>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ostream>

#include "SFML/System/Vector2.hpp"
#include "game.h"
#include "player.h"

#define WINDOW_WIDTH  1280
#define WINDOW_HEIGHT  720
#define LETTER_MAX_WITDH 1252
#define LETTER_MAX_HEIGHT 697

#define MAX_RAND 1000


GameWindow::GameWindow()
    : window { { WINDOW_WIDTH, WINDOW_HEIGHT }, "UV_Master" } {
    window.setVerticalSyncEnabled(true);
    Player player;

    if (!aTexture.loadFromFile("a.png")) {
        std::cout << "Erreur A" << std::endl;
    }
    if (!fxTexture.loadFromFile("fx.png")) {
        std::cout << "Erreur B" << std::endl;
    }

    aSprite.setTexture(aTexture);
    fxSprite.setTexture(fxTexture);

    aSprite.setPosition(sf::Vector2f(rand() % LETTER_MAX_WITDH, rand() % LETTER_MAX_HEIGHT));
    fxSprite.setPosition(sf::Vector2f(rand() % LETTER_MAX_WITDH, rand() % LETTER_MAX_HEIGHT));


    while (window.isOpen()) {

        if (!roundOver) {
            for (timeIterator; timeIterator <= 120; timeIterator++) {

                window.clear();
        
                for (auto event = sf::Event{}; window.pollEvent(event);) {

                    // All the events:

                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
            
                    if (event.type == sf::Event::MouseButtonPressed) {
                        auto mousePos = sf::Mouse::getPosition(window); // Mouse position relative to the window
                        auto translatedPos = window.mapPixelToCoords(mousePos); // Mouse position translated into wrld

                        if (aSprite.getGlobalBounds().contains(translatedPos)) {
                            player.incrementScore();
                                roundOver = true;
                                std::cout << "Score : " << player.getScore() << std::endl;
                        }
                        else if (fxSprite.getGlobalBounds().contains(translatedPos)) {
                            player.removeLife();
                            roundOver = true;
                            std::cout << "-1 vie" << std::endl;
                        }
                        if (roundOver) {
                            timeIterator = 121;
                        }
                        if (player.isGameOver()) {
                            window.close();
                        }
                    }
                }

                window.draw(aSprite);
                window.draw(fxSprite);

                //std::cout << timeIterator << std::endl;

                window.display();

            } // End of iterator
        }

        roundOver = false;
                
        aSprite.setPosition(sf::Vector2f(rand() % LETTER_MAX_WITDH, rand() % LETTER_MAX_HEIGHT));
        fxSprite.setPosition(sf::Vector2f(rand() % LETTER_MAX_WITDH, rand() % LETTER_MAX_HEIGHT));

        timeIterator = 0;
        
        window.display();
    }
}