#pragma once
#include "GameObject.h"
#include "Vector2d.h"
#include "ICollidable.h"

#include <SDL2/SDL.h>

#include <memory>

class IHitbox
{
public:
    using ICollidablePtr = std::shared_ptr<ICollidable>;

    IHitbox(ICollidablePtr go)
        : m_gameObject(go) {}

    virtual void collide(const IHitbox& other) = 0;

    const ICollidable& getObject() const
    {
        return *m_gameObject;
    }

protected:
    ICollidablePtr m_gameObject;
};

class Hitbox : public IHitbox
{
public:
    Hitbox(ICollidablePtr go, int x, int y, int w, int h);

    void collide(const IHitbox& other);

    SDL_Rect getRect() const;

private:
    SDL_Rect m_hitbox;
};