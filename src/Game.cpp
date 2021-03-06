#include "Game.h"
#include "SceneMenu.h"
#include "SceneGame.h"
#include "InputManager.h"
#include "CollisionDetector.h"
#include "EventCallback.h"

#include <iostream>

// cannot find a better way
#define Input InputManager::getInstance()

Game::Game(int width, int height, std::string title)
    : m_windowWidth(width), m_windowHeight(height), m_title(title)
{
    m_window = NULL;
    m_renderer = NULL;
    m_shouldClose = true;
    m_shouldClose = false;
    m_paused = false;

    SDL_Init(SDL_INIT_EVERYTHING);
    m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_windowWidth, m_windowHeight, SDL_WINDOW_FULLSCREEN);
    if (!m_window)
    {
        std::cerr << "Failed to create window" << std::endl;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    if (!m_renderer)
    {
        std::cerr << "Failed to create renderer" << std::endl;
    }

    Sprite::setRenderer(m_renderer);

    Input.init();

    m_sceneManager = new SceneManager();
    m_sceneManager->currentScene = new SceneGame(m_window, m_renderer);


    auto pauseCallback = std::bind(&Game::togglePause, this);
    Input.addOnKeyPress(SDLK_p, std::make_shared<EventCallbackNew>(pauseCallback));
}

void Game::mainLoop()
{
    while (!m_shouldClose)
    {
        handleInput();

        if (!m_paused)
        {
            update();
        }        
        render();

    }
}


void Game::update()
{
    CollisionDetector::getInstance().update();
    m_sceneManager->currentScene->update();
}

void Game::render()
{
    m_sceneManager->currentScene->render();
}

void Game::handleInput()
{
    Input.update();

    if (Input.shouldQuit() || Input.isKeyDown(SDL_SCANCODE_ESCAPE))
        m_shouldClose = true;
}

void Game::togglePause()
{
    m_paused = !m_paused;
}

void Game::exit()
{
    // TODO: clean stuff

    m_shouldClose = true;
}