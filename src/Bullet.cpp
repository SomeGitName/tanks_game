#include "Bullet.h"



Bullet::Bullet(Vector2d<int> pos, int direction, Vector2d<float> velocity)
    : m_sprite("../res/bullet.png", 10, 20),
      m_pos(pos), 
      m_dir(direction), 
      m_vel(velocity),
      m_hitbox(this, pos.x, pos.y, 2, 4)
{
    m_sprite.setPosition(pos.x, pos.y);
}

Bullet::~Bullet()
{

}

void Bullet::update()
{

}

void Bullet::render()
{
    m_sprite.draw();
}