#include "InputManager.h"

#include <iostream>

void InputManager::init()
{
    for (int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }

    m_shouldQuit = false;
}

void InputManager::update()
{
    m_keyStates = (Uint8*)SDL_GetKeyboardState(0);

    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        switch(e.type)
        {
            // Keyboard keys: -----------

            case SDL_KEYDOWN:
                m_events[e.key.keysym.sym].fire();
                break;


            // ---------------------------

            case SDL_MOUSEBUTTONDOWN:
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    m_mouseButtonStates[MouseButtons::LEFT] = true;
                }
                if (e.button.button == SDL_BUTTON_RIGHT)
                {
                    m_mouseButtonStates[MouseButtons::RIGHT] = true;
                }
                if (e.button.button == SDL_BUTTON_MIDDLE)
                {
                    m_mouseButtonStates[MouseButtons::MIDDLE] = true;
                }
                break;
            
            case SDL_MOUSEBUTTONUP:
                if (e.button.button == SDL_BUTTON_LEFT)
                {
                    m_mouseButtonStates[MouseButtons::LEFT] = false;
                }
                if (e.button.button == SDL_BUTTON_RIGHT)
                {
                    m_mouseButtonStates[MouseButtons::RIGHT] = false;
                }
                if (e.button.button == SDL_BUTTON_MIDDLE)
                {
                    m_mouseButtonStates[MouseButtons::MIDDLE] = false;
                }
                break;
            
            case SDL_MOUSEMOTION:
                m_mousePosition.x = e.motion.x;
                m_mousePosition.y = e.motion.y;
                break;

            case SDL_QUIT:
                m_shouldQuit = true;
                break;

            default:
                break;
        }
    }
}

bool InputManager::isKeyDown(SDL_Scancode key)
{
    if (m_keyStates != NULL)
    {
        return m_keyStates[key] == 1;
    }
    return false;
}

bool InputManager::isKeyUp(SDL_Scancode key)
{
    return !isKeyDown(key);
}

bool InputManager::isMouseButtonDown(int button)
{
    return m_mouseButtonStates.at(button);
}

Vector2d<int> InputManager::getMousePosition()
{
    return m_mousePosition;
}

bool InputManager::shouldQuit()
{
    return m_shouldQuit;
}

void InputManager::addListener(unsigned int button, std::shared_ptr<IEventCallback> event)
{
    m_events[button].addListener(event);
}
