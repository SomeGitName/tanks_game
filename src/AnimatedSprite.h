#pragma once
#include "Sprite.h"

#include <SDL2/SDL.h>

#include <string>

class AnimatedSprite : public Sprite
{
public:
    AnimatedSprite(std::string path, int w, int h, int rows, int cols, SDL_Renderer* renderer);
    AnimatedSprite(const AnimatedSprite& other);

    void setFrame(int frame);
    void nextFrame();
    void prevFrame();

    virtual void draw() override;

private:
    int m_rows;
    int m_cols;
    int m_currentFrame;
};