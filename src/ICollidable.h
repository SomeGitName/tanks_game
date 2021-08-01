#pragma once

class ICollidable
{
public:
    virtual void collide(const ICollidable& other) = 0;
};