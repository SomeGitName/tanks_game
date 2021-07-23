#pragma once

#include <memory>

class IEventCallback
{
public:
    virtual void operator() () = 0;
};

template<typename T>
class EventCallback : public IEventCallback
{
public:
    EventCallback(std::shared_ptr<T> instance, void (T::*function)())
        : m_instance(instance), m_function(function) {}

    void operator() () override
    {
        T* raw = &(*m_instance);
        (raw->*m_function)(); 
    }

private:
    void (T::*m_function)();
    std::shared_ptr<T> m_instance;
};