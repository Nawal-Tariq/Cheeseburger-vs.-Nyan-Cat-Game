#include "Powerup.h"

Powerup::Powerup(int X, int Y, std::string T)
    : GameObject(X, Y, 1, 1, "G"), type(T), isActive(true) {}

void Powerup::draw() {
    if (!isActive) return;
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << (type == "Shield" ? "s" : (type == "Speed" ? "S" : "/"));
    SetConsoleTextAttribute(hConsole, 7);
}

void Powerup::move() {
    y++;
    if (y > SCREEN_HEIGHT) {
        resetPosition();
    }
}

bool Powerup::collide(GameObject* object) {
    return isActive && (getX() == object->getX() && getY() == object->getY());
}

void Powerup::activate(Cheeseburger& cheeseburger) const {
    cheeseburger.activatePowerUp(type);
}

void Powerup::resetPosition() {
    y = 0;
    x = rand() % SCREEN_WIDTH;
}

void Powerup::deactivate() { isActive = false; }
