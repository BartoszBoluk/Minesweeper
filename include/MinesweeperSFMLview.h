#ifndef MINESWEEPERSFMLVIEW_H
#define MINESWEEPERSFMLVIEW_H

#include "MinesweeperBoard.h"
#include "SFML/Graphics.hpp"

class MinesweeperSFMLview
{
    MinesweeperBoard& board;
    sf::RenderWindow* window;
    sf::RectangleShape boardShape[20][20];

    float FieldSize;

public:
    MinesweeperSFMLview(MinesweeperBoard& board);
    virtual ~MinesweeperSFMLview();

    void update();
    void view();


};

#endif // MINESWEEPERSFMLVIEW_H
