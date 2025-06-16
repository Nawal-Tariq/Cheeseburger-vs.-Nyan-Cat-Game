#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include "CheeseBurger.h"
#include "NyanCat.h"
#include "Powerup.h"
#include "Friend.h"

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 25
#define MAX_NYAN_CATS 5
#define MAX_POWER_UPS 3
#define Max_friend 2
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Game {
private:
    Cheeseburger* player;
    NyanCat* nyanCats[MAX_NYAN_CATS];
    Powerup* powerUps[MAX_POWER_UPS];
    Friend* friendObj[Max_friend];
    int gameLevel;
    bool isGameOver;
    bool isPaused;
public:
    Game();
    void draw();
    void update();
    void checkCollisions();
    void levelup();
    void handleUserInput();
    void pauseGame();
    void resumeGame();
    bool getPaused() const;
    bool getGameOver() const;
    void displayMenu();
    void displayScore(Cheeseburger* cheeseburger);
    void resetGame(Cheeseburger* cheeseburger);
    void startGame();
    ~Game();
};

#endif // GAME_H
