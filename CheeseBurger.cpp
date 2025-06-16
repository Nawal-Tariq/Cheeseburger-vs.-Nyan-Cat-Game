#include "CheeseBurger.h"

Cheeseburger::Cheeseburger(int startX, int startY)
    : GameObject(startX, startY, 1, 1, "B"),
    lives(3), score(0), speed(5), hasShield(false) {}

void Cheeseburger::move() {
    if (_kbhit()) {
        char direction = _getch();
        switch (direction) {
        case KEY_LEFT:
            x = clamp(x - 1, 0, SCREEN_WIDTH - 1);
            break;
        case KEY_RIGHT:
            x = clamp(x + 1, 0, SCREEN_WIDTH - 1);
            break;
        }
    }
}

void Cheeseburger::draw() {
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 14); // Yellow for Cheeseburger
    std::cout << symbol;
    SetConsoleTextAttribute(hConsole, 7);  // Reset color to normal
}

void Cheeseburger::increaseScore(int points) {
    score += points;
}

void Cheeseburger::update() {
    hasShield = false;
    speed += 1;
    score *= 1;
}

void Cheeseburger::handleCollision(GameObject* other) {
    if (hasShield) {
        std::cout << "Collision avoided with shield!" << std::endl;
    }
    else {
        lives--;
        std::cout << "Hit! Lives left: " << lives << std::endl;
        if (lives <= 0) {
            std::cout << "Game Over!" << std::endl;
        }
    }
}

void Cheeseburger::activatePowerUp(std::string type) {
    if (type == "Shield") {
        hasShield = true;
        std::cout << "Power-Up Activated: Shield" << std::endl;
    }
    else if (type == "SpeedBoost") {
        speed += 2;
        std::cout << "Speed Boost Activated! Cheeseburger speed increased temporarily" << std::endl;
    }
    else if (type == "ScoreMultiplier") {
        increaseScore(15);
        std::cout << "Score Multiplier Activated! Points doubled temporarily" << std::endl;
    }
}
