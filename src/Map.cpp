#include "Map.h"
#include "AnimatedSprite.h"

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
            m_tiles[x].push_back(std::make_shared<MapTile>(sprite, pos, 3));
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
