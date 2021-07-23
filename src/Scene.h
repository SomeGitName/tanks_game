#pragma once

#include "GameObject.h"

#include <SDL2/SDL.h>

#include <vector>
#include <memory>

class Scene
{
public:
    Scene(SDL_Window* window, SDL_Renderer* renderer);
    virtual void update();
    virtual void render();

    std::vector<std::shared_ptr<GameObject>> m_gameObjects;

    SDL_Renderer* m_renderer;
    SDL_Window* m_window;

};