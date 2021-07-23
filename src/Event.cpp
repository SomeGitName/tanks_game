#include "Event.h"

#include <algorithm>
#include <iostream>

Event::Event() {}
Event::~Event() {}

void Event::addListener(std::shared_ptr<IEventCallback> action)
{
    auto position = std::find(m_actions.begin(), m_actions.end(), action);

    if (position != m_actions.end())
    {
        std::cerr << "Action existed in delegate list\n";
        return;
    }

    m_actions.push_back(action);
}

// void Event::removeListener(std::shared_ptr<IEventCallback> action) {}

void Event::fire()
{
    for (auto action : m_actions)
    {
        (*action)();
    }
}