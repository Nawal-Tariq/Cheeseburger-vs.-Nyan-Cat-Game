#include "NyanCat.h"

NyanCat::NyanCat(int x, int y, int level)
    : GameObject(x, y, 1, 1, "N"), level(level), isVisible(true) {
    fallSpeed = 1.0f + level * 0.5f;
}

void NyanCat::move() {
    y += static_cast<int>(fallSpeed);
    if (y > SCREEN_HEIGHT) {
        resetPosition();
    }
}

void NyanCat::draw() {
    if (isVisible) {
        COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 5); // Magenta for NyanCat
        std::cout << symbol;
        SetConsoleTextAttribute(hConsole, 7);  // Reset color to normal
    }
}

void NyanCat::resetPosition() {
    y = 0;
    x = rand() % SCREEN_WIDTH;
    isVisible = (rand() % 100) > (level * 10);
}
