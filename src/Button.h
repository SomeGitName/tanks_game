#pragma once
#include "GameObject.h"
#include "Sprite.h"

#include "Event.h"

#include <memory>

class Button : public GameObject
{

// temp
public:
    Event event;
// ----

public:
    Button(std::shared_ptr<Sprite> buttonSprite, Vector2d<int> position, Vector2d<int> transform);


    void render();
    void update();

    void addOnClick(std::shared_ptr<IEventCallback> action);

    const std::string getClassName() const { return "Button"; }
    
private:
    Vector2d<int> m_position;
    Vector2d<int> m_transform;
    std::shared_ptr<Sprite> m_buttonSprite;

    bool m_released;

    

};