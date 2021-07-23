#include "MapTile.h"

MapTile::MapTile(std::shared_ptr<AnimatedSprite> sprite, Vector2d<int> pos, int type)
    : m_position(pos), m_type(type)
{
    m_sprite = std::make_shared<AnimatedSprite>(*sprite); // create new sprite with  same texture
    m_sprite->setPosition(m_position);
    m_sprite->setFrame(type);
}

MapTile::~MapTile()
{

}

void MapTile::update()
{

}

void MapTile::render()
{
    m_sprite->draw();
}

void MapTile::changeType(int type)
{
    m_type = type;
}
