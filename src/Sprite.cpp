#include "Sprite.h"

#include <SDL2/SDL_image.h>

#include <iostream>

Sprite::Sprite(std::string path, int w, int h, SDL_Renderer* renderer)
{
    m_renderer = renderer;
    loadTexture(path);
    m_transform.x = w;
    m_transform.y = h;
}

Sprite::Sprite(const Sprite& other)
{
    this->m_renderer = other.m_renderer;
    this->m_texture = other.m_texture;
    this->m_transform = other.m_transform;
    this->m_position = other.m_position;
}


void Sprite::setPosition(int x, int y)
{
    m_position.x = x;
    m_position.y = y;
}

void Sprite::setPosition(Vector2d<int> newPos)
{
    setPosition(newPos.x, newPos.y);
}

void Sprite::loadTexture(std::string path)
{
    SDL_Surface* tmp = IMG_Load(path.c_str());
    if (tmp == NULL)
    {
        std::cout << "Failed to load sprite: " << path << std::endl; 
    }

    m_texture = SDL_CreateTextureFromSurface(m_renderer, tmp);
    SDL_FreeSurface(tmp);
}

void Sprite::draw()
{
    SDL_Rect src;
    SDL_Rect dst;

    src.x = 0;
    src.y = 0;
    src.w = m_transform.x;
    src.h = m_transform.y;

    dst = src;
    dst.x = m_position.x;
    dst.y = m_position.y;

    SDL_RenderCopy(m_renderer, m_texture, &src, &dst);
}