#pragma once
#include "GameObject.h"
#include "Sprite.h"

#include <memory>



class MapTile : GameObject 
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

    MapTile();

    void update();
    void render();

private:
    std::unique_ptr<Sprite> m_sprite;

};