#include "Tank.h"

#include "InputManager.h"

Tank::Tank(std::shared_ptr<Sprite> bodySprite, Vector2d<float> position)
    : m_bodySprite(bodySprite), m_position(position)
{
}

void Tank::update()
{
    
}

void Tank::render()
{
    int x = InputManager::getInstance().getMousePosition().x;
    int y = InputManager::getInstance().getMousePosition().y;
    m_bodySprite->setPosition(x, y);
    // m_bodySprite->draw();
    m_bodySprite->drawRotated(180);
}