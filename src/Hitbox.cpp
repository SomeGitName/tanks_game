#include "Hitbox.h"

void Hitbox::setOnCollision(std::string hitboxType, std::function<void(const Hitbox&)> callback)
{
    m_callbacks[hitboxType] = callback;
}

 void Hitbox::onCollision(const Hitbox& other)
 {
     std::string otherName = other.getClassName();
     if (m_callbacks[otherName])
     {
        auto callback = m_callbacks[otherName];
        callback(other);
     }
 }
    