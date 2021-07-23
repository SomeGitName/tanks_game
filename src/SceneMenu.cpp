#include "SceneMenu.h"
#include "Sprite.h"
#include "Tank.h"
#include "EventCallback.h"
#include "InputManager.h"

#include <SDL2/SDL.h>

#include <iostream>

SceneMenu::SceneMenu(SDL_Window* window, SDL_Renderer* renderer)
    : Scene(window, renderer)
{
    auto sprite = std::make_shared<Sprite>("../res/tank.png", 32, 32, m_renderer);
    m_gameObjects.push_back(std::make_shared<Tank>(sprite));

    auto sprite2 = std::make_shared<Sprite>("../res/button.png", 100, 50, m_renderer);
    auto btn = std::make_shared<Button>(sprite2, Vector2d<int>(50, 50), Vector2d<int>(100, 50));
    m_gameObjects.push_back(btn);

    frame = 0;

    a = std::make_shared<AnimatedSprite>("../res/map.png", 64, 64, 3, 5, m_renderer);
    b = std::make_shared<AnimatedSprite>(*a);

    a->setPosition(250, 250);
    a->setFrame(1);
    b->setPosition(550, 250);
    b->setFrame(2);

    std::shared_ptr<IEventCallback> callback = std::make_shared<EventCallback<AnimatedSprite>>(a, &AnimatedSprite::nextFrame);
    btn->event.addListener(callback);

    std::shared_ptr<IEventCallback> callback2 = std::make_shared<EventCallback<AnimatedSprite>>(a, &AnimatedSprite::prevFrame);
    std::shared_ptr<IEventCallback> callback3 = std::make_shared<EventCallback<AnimatedSprite>>(b, &AnimatedSprite::prevFrame);

    InputManager::getInstance().addListener(SDLK_d, callback);
    InputManager::getInstance().addListener(SDLK_a, callback2);
    InputManager::getInstance().addListener(SDLK_a, callback3);
}

void SceneMenu::update()
{  
    // ----------------------------------------------------------------


    // ----------------------------------------------------------------
    for (auto o : m_gameObjects)
    {
        o->update();
    }

    SDL_Delay(10);
}

void SceneMenu::render()
{
    SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    // ----------------------------------------------------------------

    a->draw();
    b->draw();

    // ----------------------------------------------------------------
    for (auto o : m_gameObjects)
    {
        o->render();
    }

    SDL_RenderPresent(m_renderer);
}