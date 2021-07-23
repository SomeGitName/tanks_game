#pragma once
#include "MapTile.h"
#include "GameObject.h"

#include <vector>

class Map : public GameObject
{
public:
    Map(unsigned int w, unsigned int h, unsigned int tileSize, std::shared_ptr<AnimatedSprite> sprite);
    ~Map();

    void update();
    void render();

private:
    typedef std::shared_ptr<MapTile> MapTilePtr;

    std::vector<std::vector<MapTilePtr>> m_tiles;

    unsigned int m_width;
    unsigned int m_height;
    unsigned int m_tileSize;

};