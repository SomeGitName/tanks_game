#include "HitboxSquare.h"

HitboxSquare::HitboxSquare(GameObjectPtr go, int x, int y, int w, int h)
    : Hitbox(go)
{
    m_hitbox = {x, y, w, h};
}   

bool HitboxSquare::collide(const Hitbox& other)
{
    SDL_Rect* first;
    SDL_Rect* second;
    SDL_Rect* result;

    return SDL_IntersectRect(first, second, result);
}

void HitboxSquare::move(Vector2d<int> pos)
{
    m_hitbox.x = pos.x;
    m_hitbox.y = pos.y;
}
