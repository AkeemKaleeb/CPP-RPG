/* 
    Manages Game Loop
    Coordinate Between different components
    Handles game state transitions
*/

#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <chrono>
#include <thread>

#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#endif


// Constructor
Game::Game() : running(true), playerX(5), playerY(5), screenX(16), screenY(9) {
    player = new Player("Hero", 100, 20, 10, 5);
    enemy = new Enemy("Goblin", 50, 15, 5, 0);
    std::cout << "Game Initialized!\n";
}

// Destrucotr
Game::~Game() {
    delete player;
    delete enemy;
    std::cout << "\nGame Ended!\n";
}

// Game Loop
void Game::run() {
    while(running) {
        handleInput();
        update();
        render();

        std::this_thread::sleep_for(std::chrono::milliseconds(16));     // Limit to 60 fps
    }
}

// Take in players input and process commands
void Game::handleInput() {
#if defined(_WIN32) || defined(_WIN64)
    std::cout << "Please use Linux for now\n";
    running = false;
#else
    struct termios oldt, newt;
    int oldf;
    char input;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(tcflag_t)(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

/****************/
/*   COMMANDS   */
/****************/

    if(read(STDIN_FILENO, &input, 1) == 1) {
        switch(input) {
            case 'w': playerY--; break;
            case 'a': playerX--; break;
            case 's': playerY++; break;
            case 'd': playerX++; break;

            case 'e': player->doAttack(*enemy); break;
            case 'q': running = false; break;
        }
    }



    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
#endif

    if(playerX >= screenX) { playerX = screenX - 1; }
    else if(playerX < 0) { playerX = 0; }

    if(playerY >= screenY) { playerY = screenY - 1; }
    else if(playerY < 0) { playerY = 0; }
}

// Update the status of the game
void Game::update() {
    if(!enemy->isAlive()) {
        std::cout << enemy->getName() << " defeated!" << '\n';
        running = false;
    }
}

// Render the game to the console
void Game::render() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif

    for(int y = 0; y < screenY; y++) {
        for(int x = 0; x < screenX; x++) {
            if(x == playerX && y == playerY) {
                std::cout << '@';
            }
            else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }

    player->printStats();
    std::cout << '\n';
    std::cout << enemy->getName() << " Health: " << enemy->getHealth() << '\n';
}
