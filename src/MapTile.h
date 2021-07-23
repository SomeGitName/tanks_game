#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Vector2d.h"

#include <memory>

// class Map;

class MapTile : public GameObject 
{
public:
    enum TileType
    {
        EMPTY = 0,
        WALL,
        WALL_IRON,
        WATER,
        TREES,
        BASE
    };

    MapTile(std::shared_ptr<AnimatedSprite> sprite, Vector2d<int> pos, int type);
    ~MapTile();

    void update();
    void render();

    void changeType(int type);

private:
    std::shared_ptr<AnimatedSprite> m_sprite;
    Vector2d<int> m_position;
    int m_type;
    // std::shared_ptr<Map> m_map;

};