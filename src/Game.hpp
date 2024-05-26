#pragma once

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
};
