#pragma once
#include "Vector2d.h"
#include "Event.h"
#include "EventCallback.h"

#include <SDL2/SDL.h>

#include <memory>
#include <vector>
#include <map>
#include <string>

class InputManager
{

private:
    InputManager() {}


public:

    static InputManager& getInstance()
    {
        static InputManager instance;
        return instance;
    }

    void init();
    void update();

    bool isKeyDown(SDL_Scancode key);
    bool isKeyUp(SDL_Scancode key);

    bool isMouseButtonDown(int button);

    Vector2d<int> getMousePosition();

    bool shouldQuit();

    enum MouseButtons
    {
        LEFT = 0,
        MIDDLE = 1,
        RIGHT = 2
    };


    void addOnKeyDown(unsigned int button, std::shared_ptr<IEventCallback> callback);

    void addOnKeyPress(unsigned int button, std::shared_ptr<IEventCallback> callback);
    
    
private:
    std::vector<bool> m_mouseButtonStates;
    Vector2d<int> m_mousePosition;

    Uint8* m_keyStates;    
    bool m_shouldQuit;

    std::map<unsigned int, Event> m_eventsOnKeyDown;

    struct BoolDefaultedToFalse
    {
        bool val = false;
    };
    std::map<unsigned int, BoolDefaultedToFalse> m_isKeyDown;
    std::map<unsigned int, Event> m_eventsOnSinglePress;

};