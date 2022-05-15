#include "GameResultState.h"

GameResultState::GameResultState(sf::RenderWindow* window, std::stack<State*>* states, int result):State(window, states)
{
    this->font.loadFromFile("Fonts/arial.ttf");
    this->text.setFont(font);
    this->text.setCharacterSize(145);
    this->text.setPosition(10.f, 20.f);
    this->text.setFillColor(sf::Color(100,100,100,200));
    this->text.setOutlineThickness(2.f);
    this->result=result;
}

GameResultState::~GameResultState()
{
    //dtor
}

void GameResultState::endState()
{

}

void GameResultState::updateKeybinds(const float& dt)
{

}

void GameResultState::updateButton()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }
}

void GameResultState::update(const float& dt)
{
    if(this->result==2)
    {
        this->text.setString("Game Over: \n    Defeat");
    }

    if(this->result==1)
    {
        this->text.setString("Game Over: \n    Victory");
    }


    this->buttons["GAME_STATE"]= new Button(280, 370, 250, 50,
                                            &this->font, "New Game",
                                            sf::Color(100,100,100,200), sf::Color(150,150,150,200), sf::Color(20,20,20,200));

    this->updateButton();

    this->updateKeybinds(dt);

    this->updateMousePositions();

    if(this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new MainMenuState(this->window,  this->states));
    }
}

void GameResultState::renderButtons(sf::RenderTarget* target)
{
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }
}

void GameResultState::render(sf::RenderTarget* target)
{
    target->draw(this->text);

    this->renderButtons(target);
}
