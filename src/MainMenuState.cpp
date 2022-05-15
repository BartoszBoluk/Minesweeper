#include "MainMenuState.h"

void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"]= new Button(280, 200, 250, 50,
                                            &this->font, "New Game",
                                            sf::Color(100,100,100,200), sf::Color(150,150,150,200), sf::Color(20,20,20,200));

    this->buttons["SETTINGS"]= new Button(280, 320, 250, 50,
                                            &this->font, "Settings",
                                            sf::Color(100,100,100,200), sf::Color(150,150,150,200), sf::Color(20,20,20,200));

    this->buttons["EXIT_STATE"]= new Button(280, 440, 250, 50,
                                            &this->font, "Quit",
                                            sf::Color(100,100,100,200), sf::Color(150,150,150,200), sf::Color(20,20,20,200));

}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
    :State(window, states)
{
    this->initFonts();
    this->initButtons();

    this->Title_Text.setCharacterSize(120);
    this->Title_Text.setPosition(240.f, 10.f);
    this->Title_Text.setOutlineThickness(5.f);
    this->Title_Text.setOutlineColor(sf::Color::Black);
    this->Title_Text.setFillColor(sf::Color::White);
    this->Title_Text.setFont(this->font);
    this->Title_Text.setString("Saper");
}

MainMenuState::~MainMenuState()
{
    auto it=this->buttons.begin();
    for (it=this->buttons.begin(); it !=this->buttons.end(); ++it)
    {
        delete it->second;
    }
}

void MainMenuState::updateButton()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

    if(this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window,  this->states));
    }

    if(this->buttons["SETTINGS"]->isPressed())
    {

    }

    if(this->buttons["EXIT_STATE"]->isPressed())
    {
        this->endState();
        this->window->close();
    }
}

void MainMenuState::endState()
{

}

void MainMenuState::updateKeybinds(const float & dt)
{

}

void MainMenuState::update(const float &dt)
{
    this->updateKeybinds(dt);

    this->updateMousePositions();

    this->updateButton();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
    for(auto &it : this->buttons)
    {
        it.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget* target)
{
    this->renderButtons(target);

    target->draw(this->Title_Text);
}
