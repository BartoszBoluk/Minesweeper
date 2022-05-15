#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states):State(window, states)
{
    this->board=new MinesweeperBoard(10,10,EASY);

    this->font.loadFromFile("Fonts/arial.ttf");


    this->FieldSize=50.f;
    this->endGame=false;
    this->Can_Click=false;

    //J-width I-height

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            this->boardShape[j][i].setFillColor(sf::Color(100,100,200));
            this->boardShape[j][i].setSize(sf::Vector2f(FieldSize, FieldSize));
            this->boardShape[j][i].setPosition(j*FieldSize+50.f,i*FieldSize+50.f);
            this->boardShape[j][i].setOutlineThickness(2.f);

            this->text[j][i].setFont(font);
            this->text[j][i].setCharacterSize(30);
            this->text[j][i].setPosition(j*FieldSize+63.f, i*FieldSize+52.f);
            this->text[j][i].setFillColor(sf::Color(100,100,100,200));
            this->text[j][i].setOutlineThickness(2.f);
        }
    }
}

GameState::~GameState()
{
    delete this->board;
}

void GameState::endState()
{
    std::cout<<"Ending Game"<<std::endl;
}

void GameState::updateKeybinds(const float& dt)
{
    this->checkForQuit();
}

void GameState::update(const float& dt)
{
    this->updateKeybinds(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        std::cout<<this->board->getHeight()<<std::endl;

    sf::Time time=clock.getElapsedTime();

    if(time.asSeconds()>0.3f)
        this->Can_Click=true;

    for(int i = 0; i <10; i++)
    {
        for(int j = 0; j <10; j++)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&Can_Click==true)
            {
                if(boardShape[j][i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*this->window))))
                {
                    this->board->Reveal(j,i);
                }
            }

        }
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)&&Can_Click==true)
    {
        for(int i = 0; i <10; i++)
        {
            for(int j = 0; j <10; j++)
            {
                if(boardShape[j][i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*this->window))))
                {
                    this->board->ToggleFlag(j,i);
                }
            }
        }
    }

    for(int i=0; i<this->board->getHeight(); i++)
    {
        for(int j=0; j<this->board->getWidth(); j++)
        {
            if(this->board->hasFlag(j,i)==true)
            {
                this->boardShape[j][i].setFillColor(sf::Color::Green);
            }
            if(this->board->isRevealed(j,i)==true)
            {
                std::stringstream ss;

                ss <<this->board->CountMines(j,i);
                this->text[j][i].setString(ss.str());
            }
            if(this->board->isRevealed(j,i)==true)
            {
                this->boardShape[j][i].setFillColor(sf::Color::Blue);
            }
            if(this->board->isRevealed(j,i)==true&&this->board->hasMine(j,i)==true)
            {
                this->boardShape[j][i].setFillColor(sf::Color::Red);
                this->endGame=true;

            }

            if(this->board->getGameState()==FINISHED_LOSS)
            {
                sf::Time time=clock.getElapsedTime();

                if(time.asSeconds()>1)
                {
                    this->states->push(new GameResultState(this->window,  this->states, 2));
                }

            }

            if(this->board->getGameState()==FINISHED_WIN)
            {
                sf::Time time=clock.getElapsedTime();

                if(time.asSeconds()>1)
                {
                    this->states->push(new GameResultState(this->window,  this->states, 1));
                }

            }

        }
    }
}

void GameState::render(sf::RenderTarget* target)
{
    for(int i=0; i<this->board->getHeight(); i++)
    {
        for(int j=0; j<this->board->getWidth(); j++)
        {
            target->draw(this->boardShape[j][i]);
            target->draw(this->text[j][i]);
        }
    }

}
