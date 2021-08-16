#include "HitboxSquare.h"

#include <iostream>

HitboxSquare::HitboxSquare(GameObject* go, int x, int y, int w, int h)
    : Hitbox(go)
{
    m_hitbox = {x, y, w, h};
}   

bool HitboxSquare::collide(std::shared_ptr<Hitbox> other)
{
    bool collided = false;
    std::string otherType = other->getClassName();

    if (otherType == "HitboxSquare")
    {
        HitboxSquare* otherRect = dynamic_cast<HitboxSquare*>(other.get());

        SDL_Rect* first = this->getRectPtr();
        SDL_Rect* second = otherRect->getRectPtr();
        SDL_Rect result;

        collided = SDL_IntersectRect(first, second, &result) == SDL_TRUE;
    }
    else if (otherType == "HitboxCircle")
    {
        
    }
    else 
    {
        std::cerr << "Unknown hitbox type" << std::endl;
    }
    return collided;
}

void HitboxSquare::move(Vector2d<int> pos)
{
    m_hitbox.x = pos.x;
    m_hitbox.y = pos.y;
}
