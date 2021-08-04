#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "Vector2d.h"
#include "HitboxSquare.h"

#include <memory>


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

    void randomType();

    const std::string getClassName() const { return "MapTile"; }

private:
    std::shared_ptr<AnimatedSprite> m_sprite;
    Vector2d<int> m_position;
    int m_type;

};