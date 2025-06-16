#pragma once
#ifndef CHEESEBURGER_H
#define CHEESEBURGER_H

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "GameObject.h"
#include "Constants.h"

#define KEY_LEFT 75
#define KEY_RIGHT 77

class Cheeseburger : public GameObject {
private:
    int lives;
    int score;
    int speed;
    bool hasShield;

public:
    Cheeseburger(int startX, int startY);
    void move() override;
    void draw() override;
    void increaseScore(int points);
    void update();
    void handleCollision(GameObject* other);
    void activatePowerUp(std::string type);
    int getLives() const;
    int getScore() const;

    friend void displayScore(Cheeseburger* cheeseburger);
    friend void resetGame(Cheeseburger* cheeseburger);
    friend class Friend;
    friend class Game;
};

#endif // CHEESEBURGER_H
