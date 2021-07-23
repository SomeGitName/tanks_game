#pragma once
#include "Sprite.h"

#include <SDL2/SDL.h>

#include <string>

class AnimatedSprite : public Sprite
{
public:
    AnimatedSprite(std::string path, int w, int h, unsigned int rows, unsigned int cols, SDL_Renderer* renderer);
    AnimatedSprite(const AnimatedSprite& other);

    void setFrame(int frame);
    void nextFrame();
    void prevFrame();

    virtual void draw() override;

private:
    unsigned int m_rows;
    unsigned int m_cols;
    unsigned int m_currentFrame;
};