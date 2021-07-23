#pragma once
#include "EventCallback.h"

#include <vector>
#include <memory>

class Event
{
public:
    Event();
    ~Event();

    void addListener(std::shared_ptr<IEventCallback> action);
    void removeListener(std::shared_ptr<IEventCallback> action) {}
    void fire();

private:
    std::vector<std::shared_ptr<IEventCallback>> m_actions;
};