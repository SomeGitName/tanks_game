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

    /**
     * Toggle pause mode
     * 
     * @note all systems are stopped during pause
     */
    void togglePause();

    void exit();


private:
    int m_windowWidth;
    int m_windowHeight;
    std::string m_title;
    bool m_paused;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    
    bool m_shouldClose;

    SceneManager* m_sceneManager;

    
};