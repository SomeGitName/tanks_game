#pragma once
#include "Core.h"

class Bullet : public GameObject
{
public:
    Bullet(Vector2d<int> pos, int dir, Vector2d<float> velocity);
    ~Bullet();

    void update();
    void render();

    const std::string getClassName() const { return "Bullet"; }

private:
    Sprite m_sprite;
    HitboxSquare m_hitbox;
    Vector2d<int> m_pos;
    Vector2d<float> m_vel;
    int m_dir;
    
    friend class Tank;

};