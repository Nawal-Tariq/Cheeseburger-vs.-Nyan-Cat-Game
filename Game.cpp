#include "Game.h"

Game::Game() : isGameOver(false), gameLevel(1), isPaused(false) {
    player = new Cheeseburger(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 1);

    // Create Nyan Cats
    for (int i = 0; i < MAX_NYAN_CATS; ++i) {
        nyanCats[i] = new NyanCat(rand() % SCREEN_WIDTH, rand() % 10, rand() % 5);
    }

    // Create Powerups
    for (int i = 0; i < MAX_POWER_UPS; ++i) {
        powerUps[i] = new Powerup(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, rand() % 3 == 0 ? "Shield" : (rand() % 3 == 1 ? "Speed" : "Score"));
    }

    // Initialize Friends
    for (int i = 0; i < Max_friend; ++i) {
        friendObj[i] = new Friend(rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT, "wishi", rand() % 3 + 1);
    }
}

void Game::draw() {
    system("cls");
    // Draw game objects
    player->draw();

    for (int i = 0; i < MAX_NYAN_CATS; ++i) {
        nyanCats[i]->draw();
    }

    for (int i = 0; i < MAX_POWER_UPS; ++i) {
        powerUps[i]->draw();
    }

    for (int i = 0; i < Max_friend; ++i) {
        friendObj[i]->draw();
    }
    // Display Score
    displayScore(player);
}

void Game::update() {
    if (isGameOver) return;

    player->update();
    player->move();
    for (int i = 0; i < MAX_NYAN_CATS; ++i) {
        nyanCats[i]->move();
    }

    for (int i = 0; i < MAX_POWER_UPS; ++i) {
        powerUps[i]->move();
    }

    for (int i = 0; i < Max_friend; ++i) {
        friendObj[i]->move();
    }

    checkCollisions();
}

void Game::checkCollisions() {
    for (int i = 0; i < MAX_NYAN_CATS; ++i) {
        if (player->checkCollision(*nyanCats[i])) {
            if (player->getScore() > 0) {
                player->handleCollision(nyanCats[i]);
                nyanCats[i]->resetPosition();
            }
        }
    }

    for (int i = 0; i < MAX_POWER_UPS; ++i) {
        if (powerUps[i]->collide(player)) {
            player->increaseScore(5);
            powerUps[i]->activate(*player);
            powerUps[i]->deactivate();
        }
    }
    for (int i = 0; i < Max_friend; ++i) {
        if (friendObj[i]->collide(player)) {
            player->increaseScore(10);
            friendObj[i]->setActive(true);
            friendObj[i]->offerHelp(*player);
        }
    }
}

void Game::levelup() {
    if (player->getScore() > 100 && player->getScore() < 200) {
        gameLevel++;
    }
    else if (player->getScore() >= 200 && player->getScore() < 300) {
        gameLevel++;
    }
}

void Game::handleUserInput() {
    if (_kbhit()) {
        char ch = _getch();
        if (ch == 27) { // ESC key to pause the game
            pauseGame();
        }
        if (_getch()) { // any key to resume
            resumeGame();
        }
    }
}

void Game::pauseGame() {
    isPaused = true;
}

void Game::resumeGame() {
    isPaused = false;
}

bool Game::getPaused() const {
    return isPaused;
}

bool Game::getGameOver() const {
    return isGameOver;
}

void Game::displayMenu() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    std::cout << "\n\n\n\n\n";
    std::cout << "\t\t\t\t\t*\n";
    std::cout << "\t\t\t\t\t****     Cheeseburger vs. Nyan Cat     ****\n";
    std::cout << "\t\t\t\t\t*\n";

    // Set text color to yellow for the menu options
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "\t\t\t\t\t1. Start Game\n";
    std::cout << "\t\t\t\t\t2. Display Score\n";
    std::cout << "\t\t\t\t\t3. Replay game\n";
    std::cout << "\t\t\t\t\t4. Game Instructions and rules\n";
    std::cout << "\t\t\t\t\t5. Team members\n";
    std::cout << "\t\t\t\t\t6. Exit\n";

    // Set text color to cyan for the footer and user input prompt
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    std::cout << "\t\t\t\t\t*\n";
    std::cout << "\t\t\t\t\tEnter your choice: ";

    // Reset the text color to default (white)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Game::displayScore(Cheeseburger* cheeseburger) {
    COORD pos = { 0, SCREEN_HEIGHT };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11); // Light Blue for Score
    std::cout << "Level: " << gameLevel << " Lives: " << cheeseburger->getLives() << " Score: " << cheeseburger->getScore() << std::endl;
    SetConsoleTextAttribute(hConsole, 7); // Reset to normal
}

void Game::resetGame(Cheeseburger* cheeseburger) {
    cheeseburger->lives = 3;      // Reset lives
    cheeseburger->score = 0;     // Reset score
    cheeseburger->speed = 5;     // Reset speed
    cheeseburger->hasShield = false;

    // Reset NyanCats and Powerups
    for (int i = 0; i < MAX_NYAN_CATS; ++i) {
        nyanCats[i]->resetPosition();
    }
    for (int i = 0; i < MAX_POWER_UPS; ++i) {
        powerUps[i]->resetPosition();
        powerUps[i]->deactivate();
    }
    for (int i = 0; i < Max_friend; ++i) {
        friendObj[i]->setActive(false);
    }

    gameLevel = 1; // Reset game level
    isGameOver = false;
    std::cout << "Game has been reset. Good luck!" << std::endl;
}

void Game::startGame() {
    isGameOver = false;
    std::fstream file;
    int highestScore = 0;

    // Open the file for reading and writing
    file.open("highscore.txt", std::ios::in | std::ios::out);

    int choice;
    do {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        // Set the background color to red and text color to blue
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 101);
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            while (!isGameOver) {
                if (!isPaused) {
                    levelup();
                    if (player->getLives() <= 0) {
                        isGameOver = false;
                    }
                    else {
                        update();
                        draw();
                        checkCollisions();
                        Sleep(100);
                    }

                    // Open the file for reading and writing
                    file.open("highscore.txt", std::ios::in | std::ios::out);
                    if (!file) {
                        // If the file doesn't exist, create it and set highestScore to 0
                        file.clear(); // Clear any errors
                        file.open("highscore.txt", std::ios::out); // Create a new file
                        if (!file) {
                            std::cout << "Error while creating file!" << std::endl;
                            return;
                        }
                        file.close();
                        highestScore = 0; // Set initial highest score to 0
                    }
                    else {
                        // If the file exists, read the highest score
                        file >> highestScore;
                        file.close();
                    }

                    // Compare with the player's score
                    if (player->getScore() > highestScore) {
                        highestScore = player->getScore();
                        // Now save the new highest score to the file
                        file.open("highscore.txt", std::ios::out | std::ios::trunc); // Open for writing and truncate the file
                        if (!file) {
                            std::cout << "Error opening file for writing!" << std::endl;
                            return;
                        }
                        file << highestScore; // Write the new highest score
                        file.close();
                    }
                }
            }
            system("cls");
            break;
        case 2:
            if (file) {
                file >> highestScore;
                std::cout << "Highest Score: " << highestScore << std::endl;
                file.close();
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                std::cout << "\n\n\n";
                std::cout << "\t\t\t\t\t\t*\n";
                std::cout << "\t\t\t\t\t\t*                             *\n";
                std::cout << "\t\t\t\t\t\t*      HIGHEST SCORE          *\n";
                std::cout << "\t\t\t\t\t\t*                             *\n";
                std::cout << "\t\t\t\t\t\t*\n";
                std::cout << "\t\t\t\t\t\t*     Highest Score: " << highestScore << "       *" << std::endl;
                std::cout << "\t\t\t\t\t\t*\n";
                std::cout << "\t\t\t\t\t\t    Press any key to exit!      " << std::endl;
                if (_getch()) {
                    // Reset the text color to normal (white)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    system("cls");
                    break;
                }
            }
            else {
                std::cout << "No highscore data found!" << std::endl;
            }
            break;
        case 3:
            std::cout << "Replaying game...\n";
            resetGame(player);
            break;
        case 4:
            system("cls");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

            std::cout << "\n\n";
            std::cout << "\t\t\t\t\t**\n";
            std::cout << "\t\t\t\t\t*                    GAME INSTRUCTIONS               *\n";
            std::cout << "\t\t\t\t\t**\n";
            std::cout << "\n";
            std::cout << "\t\t\t\t\t|1. Welcome to the Ultimate Game Challenge!          |\n";
            std::cout << "\t\t\t\t\t|  Get ready to test your skills and have fun.       |\n";
            std::cout << "\n";
            std::cout << "\t\t\t\t\t**\n";
            std::cout << "\t\t\t\t\t*                       GAME RULES                   *\n";
            std::cout << "\t\t\t\t\t**\n";
            std::cout << "\n";
            std::cout << "\t\t\t\t\t|1. Each level will increase in difficulty.          |\n";
            std::cout << "\t\t\t\t\t|2. You earn points by completing challenges.        |\n";
            std::cout << "\t\t\t\t\t|3. Make sure to beat the timer to advance.          |\n";
            std::cout << "\t\t\t\t\t|4. If you lose all your lives, the game ends.       |\n";
            std::cout << "\n";
            std::cout << "\t\t\t\t\t**\n";
            std::cout << "\t\t\t\t\t*                      HOW TO PLAY                   *\n";
            std::cout << "\t\t\t\t\t**\n";
            std::cout << "\n";
            std::cout << "\t\t\t\t\t|1. Use arrow keys to navigate.                      |\n";
            std::cout << "\t\t\t\t\t|2. Press 'Enter' to select an option.               |\n";
            std::cout << "\t\t\t\t\t|3. Collect powerups/friends and avoid nyancats.     |\n";
            std::cout << "\t\t\t\t\t|4. Press 'ESC' to pause the game anytime.           |\n";
            std::cout << "\t\t\t\t\t|5. Press 'R' to resume the game.                    |\n";
            std::cout << "\n";
            std::cout << "\t\t\t\t\t**\n";
            std::cout << "\t\t\t\t\t*                     ENJOY THE GAME!                *\n";
            std::cout << "\t\t\t\t\t**\n";
            std::cout << "\t\t\t\t\t                 Press any key to exit!              " << std::endl;
            if (_getch()) {
                // Reset the text color to normal (white)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                system("cls");
                break;
            }
        case 5:
            system("cls");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            std::cout << "\t\t\t\t\t*\n";
            std::cout << "\t\t\t\t\t*                  GAME TEAM                *\n";
            std::cout << "\t\t\t\t\t*                Pixel Pioneers             *\n";
            std::cout << "\t\t\t\t\t*\n";

            // Set text color to yellow for the team member list header
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\t\t\t\t\t*  Member Name          |     Roll Number   *\n";
            std::cout << "\t\t\t\t\t*\n";

            // Set text color to green for team member details
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            std::cout << "\t\t\t\t\t*  Warisha Zia          |     23F-0534      *\n";
            std::cout << "\t\t\t\t\t*  Nawal Tariq          |     23F-0776      *\n";
            std::cout << "\t\t\t\t\t*\n";

            // Set text color to magenta for the closing line
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
            std::cout << "\t\t\t\t\t             Let the Games Begin!            \n";
            std::cout << "\t\t\t\t\t            Press any key to exit!" << std::endl;
            if (_getch()) {
                // Reset the text color to normal (white)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                system("cls");
                break;
            }
        case 6:
            std::cout << "Exiting Game\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    } while (choice != 6);
}

Game::~Game() {
    delete player;
    for (int i = 0; i < MAX_NYAN_CATS; ++i) delete nyanCats[i];
    for (int i = 0; i < MAX_POWER_UPS; ++i) delete powerUps[i];
    for (int i = 0; i < Max_friend; ++i) delete friendObj[i];
}
