#include "MinesweeperBoard.h"

MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode)
{
    width=w;
    height=h;
    for(int i=0; i<=width; i++)
    {
        for(int j=0; j<=height; j++)
        {
            board[i][j].hasFlag=false;
            board[i][j].hasMine=false;
            board[i][j].isRevealed=false;
        }
    }
    if(mode==DEBUG)
    {
        for(int i=0; i<width; i++)
            board[i][0].hasMine=true;
    }

    if(mode==EASY)
    {
        int k,l;
        srand(time(NULL));
        int wynik=(width*height)*0.1;
        while(wynik>0)
        {
            k=rand()%width;
            l=rand()%height;
            if(board[k][l].hasMine==false)
            {
                board[k][l].hasMine=true;
                wynik--;
            }
        }
    }
    if(mode==NORMAL)
    {
        int k,l;
        srand(time(NULL));
        int wynik=(width*height)*0.2;
        int liczbamin=0;
        while(wynik>0)
        {
            k=rand()%width;
            l=rand()%height;
            if(board[k][l].hasMine==false)
            {
                board[k][l].hasMine=true;
                wynik--;
            }
        }

    }
    if(mode==HARD)
    {
        int k,l;
        srand(time(NULL));
        int wynik=(width*height)*0.3;
        int liczbamin=0;
        while(wynik>0)
        {
            k=rand()%width;
            l=rand()%height;
            if(board[k][l].hasMine==false)
            {
                board[k][l].hasMine=true;
                wynik--;
            }
        }

    }
}

MinesweeperBoard::~MinesweeperBoard()
{
    //dtor
}

void MinesweeperBoard::Reveal(int x, int y)
{
    board[x][y].isRevealed=true;
}

void MinesweeperBoard::ToggleFlag(int x, int y)
{
    board[x][y].hasFlag=true;
}

int MinesweeperBoard::getWidth()
{
    return width;
}

int MinesweeperBoard::getHeight()
{
    return height;
}

int MinesweeperBoard::getMinesCount()
{
    int MinesCount=0;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(board[j][i].hasMine==true)
                MinesCount++;
        }
    }
    return MinesCount;
}

bool MinesweeperBoard::hasFlag(int x, int y)
{
    if(board[x][y].hasFlag==true)
        return true;
    else
        return false;
}

bool MinesweeperBoard::hasMine(int x, int y)
{
    if(board[x][y].hasMine==true)
        return true;
    else
        return false;
}

bool MinesweeperBoard::isRevealed(int x, int y)
{
    if(board[x][y].isRevealed==true)
        return true;
    else
        return false;
}

BoardGameState MinesweeperBoard::getGameState()
{
    int state=0;
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if(isRevealed(j, i)==true&&hasMine(j,i)==true)
                state=1;
        }
    }
    if(getMinesCount()==CountRevealedFields())
        return FINISHED_WIN;
    if(state==1)
        return FINISHED_LOSS;
    else
        return RUNNING;
}

int MinesweeperBoard::CountRevealedFields()
{
    int Counter=0;
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if(board[j][i].isRevealed==false)
                Counter++;
        }
    }
    return Counter;
}

int MinesweeperBoard::CountMines(int x, int y) //liczy miny dookola pola które chcemy sprawdziæ
{
    if(x>=width||y>=height)
        return -1;
    if(board[x][y].isRevealed==false)
        return -1;
    if(board[x][y].isRevealed==true)
    {
        int liczbamin=0;
        if(x==0 and y!=0)
        {
            if(board[x][y-1].hasMine==1)
                liczbamin++;
            if(board[x][y+1].hasMine==1)
                liczbamin++;
            if(board[x+1][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
            if(board[x+1][y+1].hasMine==1)
                liczbamin++;
        }
        else if(y==0 and x!=0)
        {
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x-1][y+1].hasMine==1)
                liczbamin++;
            if(board[x][y+1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
            if(board[x+1][y+1].hasMine==1)
                liczbamin++;
        }
        else if(x==width and y!=height)
        {
            if(board[x-1][y-1].hasMine==1)
                liczbamin++;
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x-1][y+1].hasMine==1)
                liczbamin++;
            if(board[x][y-1].hasMine==1)
                liczbamin++;
            if(board[x][y+1].hasMine==1)
                liczbamin++;
        }
        else if(y==height and y!=width)
        {
            if(board[x-1][y-1].hasMine==1)
                liczbamin++;
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
        }
        else if(x==0 and y==0)
        {
            if(board[x][y+1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
            if(board[x+1][y+1].hasMine==1)
                liczbamin++;
        }
        else if(x==width and y==0)
        {
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x-1][y+1].hasMine==1)
                liczbamin++;
            if(board[x][y+1].hasMine==1)
                liczbamin++;

        }
        else if(x==width and y==height)
        {
            if(board[x-1][y-1].hasMine==1)
                liczbamin++;
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x][y-1].hasMine==1)
                liczbamin++;
        }
        else if(x==0 and y==width)
        {
            if(board[x][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
        }
        else
        {

            if(board[x-1][y-1].hasMine==1)
                liczbamin++;
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x-1][y+1].hasMine==1)
                liczbamin++;
            if(board[x][y-1].hasMine==1)
                liczbamin++;
            if(board[x][y+1].hasMine==1)
                liczbamin++;
            if(board[x+1][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
            if(board[x+1][y+1].hasMine==1)
                liczbamin++;
        }
        return liczbamin;
    }
}

void MinesweeperBoard::debug_display()
{

    for(int i=0; i<height; i++)
    {
        std::cout<<std::endl;
        for(int j=0; j<width; j++)
        {
            std::cout<<"[";

            if(board[j][i].hasMine==true)
                std::cout<<"M";
            else
                std::cout<<".";
            if(board[j][i].hasFlag==true)
                std::cout<<"F";
            else
                std::cout<<".";
            if(board[j][i].isRevealed==true)
                std::cout<<"O";
            else
                std::cout<<".";
            std::cout<<"]";
        }
        std::cout<<std::endl;
    }

}
