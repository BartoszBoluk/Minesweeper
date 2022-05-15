#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "MainMenuState.h"

class Game
{
private:

    sf::RenderWindow* window;
    sf::Event event;

    sf::Clock dtClock;
    float dt;

    int window_width, window_height;


    std::stack<State*> states;


    void initWindow();
    void initStates();

public:
    Game();
    virtual ~Game();

    void updateSFMLEvents();
    void updateDt();
    void update();

    void render();

    void run();

};

#endif // GAME_H
