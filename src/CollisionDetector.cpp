#include "CollisionDetector.h"

#include <algorithm>
#include <iostream>

CollisionDetector::~CollisionDetector()
{

}

void CollisionDetector::init()
{

}

void CollisionDetector::update()
{
    for (auto i : m_hitboxes)
    {
        for (auto j : m_hitboxes)
        {
            if (i != j)
            {
                SDL_Rect result;
                int intersect = SDL_IntersectRect(&i->getRect(), &j->getRect(), &result);
                if (intersect == SDL_TRUE)
                {
                    auto o1 = i->getObject();
                    auto o2 = j->getObject();
                    
                    o1.collide(o2);
                    o2.collide(o1);
                }              
            }
        }
    }
}

void CollisionDetector::addHitbox(std::shared_ptr<Hitbox> hitbox) 
{
    removeHitbox(*hitbox);
    m_hitboxes.push_back(hitbox);
}

void CollisionDetector::removeHitbox(const Hitbox& hitbox)
{
    auto toErase = std::find(m_hitboxes.begin(), m_hitboxes.end(), hitbox);
    if (toErase == m_hitboxes.end())
    {
        std::cerr << "trying to remove not existing hitbox" << std::endl;
    }
    else
    {
        m_hitboxes.erase(toErase);
    }
}