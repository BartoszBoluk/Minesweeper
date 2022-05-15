#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"
#include "MinesweeperBoard.h"


class MainMenuState:public State
{
    sf::Font font;
    sf::Text Title_Text;

    std::map<std::string, Button*>buttons;

    MinesweeperBoard* board;


    void initFonts();
    void initButtons();

public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~MainMenuState();

    void updateButton();

    void endState();
    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target=NULL);
    void render(sf::RenderTarget* target=NULL);

};

#endif // MAINMENUSTATE_H
