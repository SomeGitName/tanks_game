#pragma once
#include "Scene.h"

class SceneGame : public Scene
{
public:
    SceneGame(SDL_Window* window, SDL_Renderer* renderer);
    void update();
    void render();

private:
    
};