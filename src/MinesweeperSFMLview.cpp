#include "MinesweeperSFMLview.h"

MinesweeperSFMLview::MinesweeperSFMLview(MinesweeperBoard &board):board(board)
{
    this->FieldSize=50.f;

    //J-width I-height

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            this->boardShape[j][i].setFillColor(sf::Color::Red);
            this->boardShape[j][i].setSize(sf::Vector2f(FieldSize, FieldSize));
            this->boardShape[j][i].setPosition(j*FieldSize+2.f,i*FieldSize+2.f);
            this->boardShape[j][i].setOutlineThickness(2.f);
        }
    }
}

MinesweeperSFMLview::~MinesweeperSFMLview()
{
    //dtor
}

void MinesweeperSFMLview::update()
{

}

void MinesweeperSFMLview::view()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            this->window->draw(boardShape[i][j]);
        }
    }
}
