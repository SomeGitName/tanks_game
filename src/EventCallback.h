#pragma once

#include <memory>
#include <functional>

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


class EventCallbackNew : public IEventCallback
{
public:
    EventCallbackNew(std::function<void(void)> function)
        : m_function(function) {}

    void operator() () override
    {
        m_function();
    }

private:
    std::function<void(void)> m_function;
};