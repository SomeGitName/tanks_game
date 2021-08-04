#pragma once
#include "GameObject.h"
#include "Vector2d.h"
#include "ICollidable.h"
#include "Event.h"
#include "Vector2d.h"

#include <SDL2/SDL.h>

#include <memory>
#include <map>
#include <string>

class Hitbox
{
public:
    using GameObjectPtr = std::shared_ptr<GameObject>;

    Hitbox(GameObjectPtr go)
        : m_go(go) {}

    virtual ~Hitbox() = default;

    

    virtual bool collide(const Hitbox& other) = 0;
    virtual void setOnCollision(std::string hitboxType, std::function<void(const Hitbox&)> callback);
    
    virtual void onCollision(const Hitbox& other);
    
    const GameObject& getObject() const { return *m_go; }

    const std::string getClassName() const { return "Hitbox";}

protected:
    std::map<std::string, std::function<void(const Hitbox&)>> m_callbacks;

    GameObjectPtr m_go;
};

