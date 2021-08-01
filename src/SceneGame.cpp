#include "SceneGame.h"
#include "Map.h"
#include "AnimatedSprite.h"
#include "Button.h"
#include "EventCallback.h"
#include "InputManager.h"

#include <functional>

SceneGame::SceneGame(SDL_Window* window, SDL_Renderer* renderer)
    : Scene(window, renderer)
{  
    auto map = std::make_shared<Map>(30, 16, 64, std::make_shared<AnimatedSprite>("../res/map.png", 64, 64, 3, 5, m_renderer));
    m_gameObjects.push_back(map);

    auto button = std::make_shared<Button>(std::make_shared<Sprite>("../res/button1.png", 64, 32, m_renderer), Vector2d<int>(0, 200), Vector2d<int>(64, 32));
    m_gameObjects.push_back(button);

    button->addOnClick(std::make_shared<EventCallback<MapTile>>(map->getTile(0, 0), &MapTile::randomType));

    std::function<void(void)> func = std::bind(&MapTile::randomType, map->getTile(1, 0));
    std::shared_ptr<IEventCallback> callback = std::make_shared<EventCallbackNew>(func);
    button->addOnClick(callback);


    InputManager::getInstance().addOnKeyPress(SDLK_w, callback);
 }   

void SceneGame::update()
{
    SDL_Delay(10);

    for (auto o : m_gameObjects)
    {
        o->update();
    }
}

void SceneGame::render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    // ----------------------------------------------------------------


    // ----------------------------------------------------------------
    for (auto o : m_gameObjects)
    {
        o->render();
    }

    SDL_RenderPresent(m_renderer);
}
