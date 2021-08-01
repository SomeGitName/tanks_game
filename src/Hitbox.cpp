#include "Hitbox.h"


Hitbox::Hitbox(ICollidablePtr go, int x, int y, int w, int h)
    : IHitbox(go)
{
    m_hitbox = {x, y, w, h};
}   

void Hitbox::collide(const IHitbox& other)
{
}

SDL_Rect Hitbox::getRect() const
{
    return m_hitbox;
}