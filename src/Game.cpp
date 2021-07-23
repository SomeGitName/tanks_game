#include "Game.h"
#include "SceneMenu.h"
#include "InputManager.h"

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

    SDL_Init(SDL_INIT_EVERYTHING);
    m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_windowWidth, m_windowHeight, 0);
    if (!m_window)
    {
        std::cerr << "Failed to create window" << std::endl;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    if (!m_renderer)
    {
        std::cerr << "Failed to create renderer" << std::endl;
    }


    Input.init();

    m_sceneManager = new SceneManager();
    m_sceneManager->currentScene = new SceneMenu(m_window, m_renderer);

}

void Game::mainLoop()
{
    while (!m_shouldClose)
    {
        Input.update();

        if (Input.shouldQuit() || Input.isKeyDown(SDL_SCANCODE_ESCAPE))
            m_shouldClose = true;

        update();
        render();

    }
}


void Game::update()
{
    m_sceneManager->currentScene->update();
}

void Game::render()
{
    m_sceneManager->currentScene->render();
}

void Game::handleInput()
{

}
