#pragma once

#include <string>

class GameObject
{
public:
    virtual void update() = 0;
    virtual void render() = 0;

    const std::string getClassName() const { return "GameObject"; }
};