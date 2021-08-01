#pragma once

#include "Vector2d.h"

#include <SDL2/SDL.h>

#include <string>

class Sprite
{
public:
    Sprite(std::string path, int w, int h, SDL_Renderer* renderer, float scale = 1.0f);
    Sprite(const Sprite& other);


    void setPosition(int x, int y);
    void setPosition(Vector2d<int> newPos);


    virtual void draw();

protected:
    void loadTexture(std::string path);

    float m_scale;

    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    Vector2d<int> m_transform;
    Vector2d<int> m_position;
};