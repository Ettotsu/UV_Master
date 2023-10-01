#pragma once

class Player {
private:
    int score = 0;
    int lives = 3;

public:
    int getScore();
    void incrementScore();
    void removeLife();
    bool isGameOver();
};