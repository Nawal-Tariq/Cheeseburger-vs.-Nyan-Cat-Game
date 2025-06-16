#include "Game.h"

int main() {
    srand(time(NULL));  // Seed for random number generation
    Game game;
    game.startGame();
    system("pause");
    return 0;
}
