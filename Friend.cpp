#include "Friend.h"

Friend::Friend(int x, int y, std::string name, int supportlevel)
    : GameObject(x, y, 2, 2, "F"), name(name), supportLevel(supportlevel), isActive(true), target_x(x) {}

void Friend::draw() {
    if (!isActive) return;
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3); // Cyan for Friend
    std::cout << symbol;
    if (supportLevel == 1) {
        std::cout << "F";
    }
    else if (supportLevel == 2) {
        std::cout << "FF";
    }
    else if (supportLevel >= 3) {
        std::cout << "FFF";
    }
    SetConsoleTextAttribute(hConsole, 7);  // Reset color to normal
}

void Friend::move() {
    y++;
    if (y > SCREEN_HEIGHT) {
        resetPosition();
    }
}

void Friend::resetPosition() {
    y = 0;
    x = rand() % SCREEN_WIDTH;
}

void Friend::setTargetX(int newTarget) { target_x = clamp(newTarget, 0, SCREEN_WIDTH - 3); }

bool Friend::collide(GameObject* other) {
    return isActive && (abs(getX() - other->getX()) <= 1 && getY() == other->getY());
}

void Friend::offerHelp(Cheeseburger& burger) const {
    if (!isActive) return;
    std::cout << "\t\t\t\t\t\n" << name << " offers level " << supportLevel << " support!\n";
    if (supportLevel == 1) {
        burger.lives += 1;  // Increment lives by 1 if supportLevel is 1
        std::cout << "\t\t\t\t\tYou gained 1 life!";
    }
    else if (supportLevel == 2) {
        burger.lives += 2;  // Increment lives by 2 if supportLevel is 2
        std::cout << "You gained 2 lives!";
    }
    else if (supportLevel >= 3) {
        burger.lives += 3;  // Increment lives by 3 for higher support levels
        std::cout << "\t\t\t\t\tYou gained 3 lives!";
    }
}

void Friend::increasesupportlevel(int increment) {
    supportLevel += increment;
}

void Friend::setActive(bool active) { isActive = active; }
