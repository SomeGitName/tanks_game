#pragma once
#include <SDL2/SDL.h>

// #include "Scene.h"
#include "SceneManager.h"

#include <string>

class Game
{
public:
    Game(int width, int height, std::string title);
    void mainLoop();

    void update();
    void render();
    void handleInput();


private:
    int m_windowWidth;
    int m_windowHeight;
    std::string m_title;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    
    bool m_shouldClose;

    SceneManager* m_sceneManager;
    
};