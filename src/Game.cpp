#include "Game.h"

void Game::initWindow()
{
    this->window_width=800;
    this->window_height=600;
    this->window=new sf::RenderWindow(sf::VideoMode(window_width, window_height), "Saper");
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->states));
}

Game::Game()
{
    this->initWindow();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while(!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->event))
    {

        if (this->event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::update()
{
    this->updateSFMLEvents();

    if(!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if(this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }

    else
    {
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear(sf::Color(213, 215, 214));

    if(!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
