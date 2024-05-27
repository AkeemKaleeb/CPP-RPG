#pragma once
#include "Player.hpp"
#include "Enemy.hpp"

class Game {

public:
    Game();
    ~Game();

    void run();

private:
    void handleInput();
    void update();
    void render();

    bool running;
    int playerX, playerY;
    int screenX, screenY;

    Player* player;
    Enemy* enemy;
};
