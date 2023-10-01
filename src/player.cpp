#include "player.h"

int Player::getScore() {
    return score;
}

void Player::incrementScore() {
    score += 100;
}

void Player::removeLife() {
    lives -= 1;
}

bool Player::isGameOver() {
    if (lives == 0) {
        return true;
    }
    else {
        return false;
    }
}