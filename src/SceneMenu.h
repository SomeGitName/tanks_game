#pragma once
#include "SceneManager.h"
#include "Scene.h"
#include "Sprite.h"
#include "Tank.h"
#include "Button.h"
#include "AnimatedSprite.h"

#include <SDL2/SDL.h>

#include <memory>

class SceneMenu : public Scene
{
public:
    SceneMenu(SDL_Window* window, SDL_Renderer* renderer);
    void update();
    void render();

private:
    int frame;

    std::shared_ptr<AnimatedSprite> a;    
    std::shared_ptr<AnimatedSprite> b;    
};

