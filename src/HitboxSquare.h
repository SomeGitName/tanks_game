#pragma once
#include "Hitbox.h"
#include "Vector2d.h"

class HitboxSquare : public Hitbox
{
public:
    HitboxSquare(GameObject* go, int x, int y, int w, int h);

    bool collide(std::shared_ptr<Hitbox> other);

    void move(Vector2d<int> pos);

    SDL_Rect*         getRectPtr() { return &m_hitbox; };
    const std::string getClassName() const { return "HitboxSquare";}

private:
    SDL_Rect m_hitbox;
};