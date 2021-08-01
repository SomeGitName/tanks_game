#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(std::string path, int w, int h, int rows, int cols, SDL_Renderer* renderer, float scale)
    : Sprite(path, w, h, renderer, scale), m_rows(rows), m_cols(cols)
{
    m_currentFrame = 0;
}
    
AnimatedSprite::AnimatedSprite(const AnimatedSprite& other)
    : Sprite(other)
{
    this->m_currentFrame = other.m_currentFrame;
    this->m_rows = other.m_rows;
    this->m_cols= other.m_cols;
}

void AnimatedSprite::setFrame(int frame)
{
    if (frame >= 0 && frame < m_rows * m_cols)
        m_currentFrame = frame;
}

void AnimatedSprite::nextFrame()
{
    setFrame(m_currentFrame + 1);
}

void AnimatedSprite::prevFrame()
{
    setFrame(m_currentFrame - 1);
}


void AnimatedSprite::draw()
{
    SDL_Rect src;
    SDL_Rect dst;

    int frameY = m_currentFrame / m_cols;
    int frameX = m_currentFrame % m_cols;

    src.x = m_transform.x * frameX;
    src.y = m_transform.y * frameY;
    src.w = m_transform.x;
    src.h = m_transform.y;

    dst = src;
    dst.x = m_position.x;
    dst.y = m_position.y;
    dst.w = (int) m_transform.x * m_scale;
    dst.h = (int) m_transform.y * m_scale;

    SDL_RenderCopy(m_renderer, m_texture, &src, &dst);
}