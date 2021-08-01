#include "Button.h"
#include "InputManager.h"
#include "Vector2d.h"

#include <iostream>

Button::Button(std::shared_ptr<Sprite> buttonSprite, Vector2d<int> position, Vector2d<int> transform)
    : m_buttonSprite(buttonSprite), m_position(position), m_transform(transform), m_released(true)
{
    m_buttonSprite->setPosition(m_position.x, m_position.y);
}

void Button::update()
{
    Vector2d<int> mousePos = InputManager::getInstance().getMousePosition();
    if (mousePos >= m_position && mousePos <= m_position + m_transform)
    {
        if (InputManager::getInstance().isMouseButtonDown(InputManager::MouseButtons::LEFT) && m_released)
        {
            std::cout << "Pressed" << std::endl;
            m_released = false;
            event.fire();
        }
        else if (!InputManager::getInstance().isMouseButtonDown(InputManager::MouseButtons::LEFT) && !m_released)
        {
            m_released = true;
        }
    }
}

void Button::render()
{
    m_buttonSprite->draw();
}

void Button::addOnClick(std::shared_ptr<IEventCallback> action)
{
    event.addListener(action);
}