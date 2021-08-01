#include "Map.h"
#include "AnimatedSprite.h"
#include "Random.h"

#include <iostream>

Map::Map(unsigned int w, unsigned int h, unsigned int tileSize, std::shared_ptr<AnimatedSprite> sprite)
    : m_width(w), m_height(h), m_tileSize(tileSize)
{
    for (int x = 0; x < m_width; x++)
    {
        std::vector<MapTilePtr> col;
        m_tiles.push_back(col);

        for (int y = 0; y < m_height; y++)
        {
            Vector2d<int> pos(x * tileSize, y * tileSize);
            m_tiles[x].push_back(std::make_shared<MapTile>(sprite, pos, Random::randomInt(0, 15)));
        }
    }
}

Map::~Map()
{

}

void Map::update()
{

}

void Map::render()
{
    for (auto col : m_tiles)
        for (auto tile : col)
        tile->render();
}

std::shared_ptr<MapTile> Map::getTile(int x, int y)
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
    {
        std::cerr << "Map: out of bounds" << std::endl;
        return nullptr;
    }
    return m_tiles[x][y];
}

std::shared_ptr<MapTile> Map::getTile(Vector2d<int> pos)
{
    return getTile(pos.x, pos.y);    
}