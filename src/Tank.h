#pragma once
#include "Game.h"
#include "GameObject.h"
#include "Vector2d.h"
#include "Sprite.h"
#include "HitboxSquare.h"

#include <memory>

class Tank : public GameObject
{
public:
    Tank(std::shared_ptr<Sprite> bodySprite, Vector2d<float> position = {0, 0});

    void update();
    void render();

    const std::string getClassName() const { return "Tank";}
public:
    Vector2d<float> m_position;
    std::shared_ptr<Sprite> m_bodySprite;

    std::shared_ptr<HitboxSquare> m_hitbox;

};