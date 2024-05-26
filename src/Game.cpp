/* 
    Manages Game Loop
    Coordinate Between different components
    Handles game state transitions
*/

#include "Game.hpp"
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
Game::Game() : running(true), playerX(5), playerY(5) {
    std::cout << "Game Initialized!\n";
}

// Destrucotr
Game::~Game() {
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
    if(_kbhit()) {
        char input = _getchar();
        switch(input) {
            case 'w': playerY++; break;
            case 'a': playerX--; break;
            case 's': playerY--; break;
            case 'd': playerX++; break;

            case 'q': running = false; break;
        }
    }
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

            case 'q': running = false; break;
        }
    }



    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
#endif
}

// Update the status of the game
void Game::update() {

}

// Render the game to the console
void Game::render() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif

    for(int y = 0; y < 10; y++) {
        for(int x = 0; x < 10; x++) {
            if(x == playerX && y == playerY) {
                std::cout << '@';
            }
            else {
                std::cout << '.';
            }
        }
        std::cout << '\n';
    }

}
