#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H

#include <iostream>
#include <time.h>

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum BoardGameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};


class MinesweeperBoard
{
    Field board[20][20];
    int width;
    int height;
public:
    MinesweeperBoard(int w, int h, GameMode mode);
    virtual ~MinesweeperBoard();

    //Functions

    int getWidth();
    int getHeight();
    int getMinesCount();
    int CountMines(int, int);
    int CountRevealedFields();

    bool hasFlag(int, int);
    bool hasMine(int, int);
    bool isRevealed(int, int);

    void Reveal(int, int);
    void ToggleFlag(int, int);
    void debug_display();

    BoardGameState getGameState();
};
#endif // MINESWEEPERBOARD_H
