#ifndef GAMERESULTSTATE_H
#define GAMERESULTSTATE_H

#include "State.h"
#include "MinesweeperBoard.h"
#include "Button.h"
#include "MainMenuState.h"


class GameResultState:public State
{
    sf::Font font;
    sf::Text text;

    std::map<std::string, Button*>buttons;
    int result;

public:
    GameResultState(sf::RenderWindow* window, std::stack<State*>* states, int result);
    virtual ~GameResultState();

    void updateButton();

    void endState();
    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};

#endif // GAMERESULTSTATE_H
