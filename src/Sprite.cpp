#include "Sprite.h"

#include <SDL2/SDL_image.h>

#include <iostream>

SDL_Renderer* Sprite::m_renderer = NULL;

Sprite::Sprite(std::string path, int w, int h, float scale)
{
    loadTexture(path);
    m_transform.x = w;
    m_transform.y = h;
    m_scale = scale;
}

Sprite::Sprite(const Sprite& other)
{
    this->m_texture = other.m_texture;
    this->m_transform = other.m_transform;
    this->m_position = other.m_position;
    this->m_scale = other.m_scale;
}

void Sprite::setRenderer(SDL_Renderer* renderer)
{
    Sprite::m_renderer = renderer;    
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
    dst.w = (int) m_transform.x * m_scale;
    dst.h = (int) m_transform.y * m_scale;

    SDL_RenderCopy(m_renderer, m_texture, &src, &dst);
}

void Sprite::drawRotated(double angle)
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
    dst.w = (int) m_transform.x * m_scale;
    dst.h = (int) m_transform.y * m_scale;

    SDL_RenderCopyEx(m_renderer, m_texture, &src, &dst, angle, NULL, SDL_FLIP_NONE);
}

