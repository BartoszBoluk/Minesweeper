#ifndef STATE_H
#define STATE_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <utility>
#include <string>

#include <SFML/Graphics.hpp>


class State
{
protected:
    sf::RenderWindow* window;
    std::stack<State*>* states;
    bool quit;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

public:
    State(sf::RenderWindow* window, std::stack<State*>* states);
    virtual ~State();

    const bool& getQuit() const;
    virtual void checkForQuit();
    virtual void updateMousePositions();

    virtual void endState()=0;
    virtual void updateKeybinds(const float& dt)=0;
    virtual void update(const float& dt)=0;
    virtual void render(sf::RenderTarget* target)=0;
};

#endif // STATE_H
