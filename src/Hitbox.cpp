#include "Hitbox.h"

void Hitbox::setOnCollision(std::string hitboxType, std::function<void(const Hitbox&)> callback)
{
    m_callbacks[hitboxType] = callback;
}

 void Hitbox::onCollision(const Hitbox& other)
 {
     if (m_callbacks[other.getClassName()])
     {
        auto callback = m_callbacks[other.getClassName()];
        callback(other);
     }
 }
    