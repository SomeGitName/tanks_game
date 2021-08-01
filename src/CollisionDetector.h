#pragma once
#include "GameObject.h"
#include "Hitbox.h"


#include <vector>

class CollisionDetector
{
private:
    CollisionDetector() {}

public:

    static CollisionDetector& getInstance()
    {
        static CollisionDetector instance;
        return instance;
    }

    ~CollisionDetector();

    void init();
    void update();

    void addHitbox(std::shared_ptr<Hitbox> hitbox);
    void removeHitbox(const Hitbox& hitbox);



private:
    std::vector<std::shared_ptr<Hitbox>> m_hitboxes;
};