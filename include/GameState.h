#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "MinesweeperBoard.h"
#include "MinesweeperSFMLview.h"
#include "GameResultState.h"

class GameState:public State
{
private:

    MinesweeperBoard* board;

    sf::RectangleShape boardShape[20][20];
    float FieldSize;
    bool endGame, Can_Click;

    sf::Font font;
    sf::Text text[20][20];
    sf::Clock clock;

    MinesweeperSFMLview* view;


public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~GameState();

    void endState();
    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target);

};

#endif // GAMESTATE_H
