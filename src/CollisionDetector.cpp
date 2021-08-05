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
                if (i->collide(j))
                {
                    i->onCollision(*j);
                    j->onCollision(*i);
                }              
            }
        }
    }
}

void CollisionDetector::addHitbox(std::shared_ptr<Hitbox> hitbox) 
{
    auto toFind = std::find(m_hitboxes.begin(), m_hitboxes.end(), hitbox);
    if (toFind != m_hitboxes.end())
    {
        std::cerr << "Hitbox already was added" << std::endl;
    }
    else
    {
        m_hitboxes.push_back(hitbox);
    }
}

void CollisionDetector::removeHitbox(std::shared_ptr<Hitbox> hitbox)
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