#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Vector2d.h"
#include "HitboxSquare.h"
#include "CollisionDetector.h"
#include "AnimatedSprite.h"

#include <memory>
#include <iostream>


class A : public GameObject
{
public:
    A(Vector2d<int> pos, Vector2d<float> vel, std::shared_ptr<AnimatedSprite> sprite)
    {
        m_sprite = std::make_shared<AnimatedSprite>(*sprite);
        m_hitbox = std::make_shared<HitboxSquare>(this, pos.x, pos.y, 64, 64);

        std::function<void(const Hitbox&)> f = std::bind(&A::print, this, std::placeholders::_1);
        m_hitbox->setOnCollision("HitboxSquare", f);
        CollisionDetector::getInstance().addHitbox(m_hitbox);


        m_pos.x = pos.x;
        m_pos.y = pos.y;
        m_vel.x = vel.x;
        m_vel.y = vel.y;
    }

    void render()
    {
        m_sprite->draw();
    }

    void update()
    {
        m_pos += m_vel;
        Vector2d<int> posInt;
        posInt.x = m_pos.x;
        posInt.y = m_pos.y;


        m_sprite->setPosition(posInt);
        m_hitbox->move(posInt);

        if (m_count == 0)
            m_sprite->setFrame(3);
        m_count = 0;

    }

    void print(const Hitbox& other)
    {
        m_sprite->setFrame(1);
        m_count = 1;
    }

private:
    std::shared_ptr<AnimatedSprite> m_sprite;
    std::shared_ptr<HitboxSquare> m_hitbox;

    Vector2d<float> m_pos;
    Vector2d<float> m_vel;

    int m_count = 0;
};
