#pragma once

template<typename T>
class Vector2d
{
public:
    Vector2d(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    Vector2d()
    {
        this->x = 0;
        this->y = 0;
    }

    friend Vector2d<T> operator+(const Vector2d<T>& first, const Vector2d<T>& second)
    {
        Vector2d<T> result(first.x + second.x, first.y + second.y);
        return result;
    }

    // Vector2d& operator+(const Vector2d<T>& other)
    // {
    //     this->x += other.x;
    //     this->y += other.y;
    //     return *this;
    // }

    Vector2d& operator+=(const Vector2d<T>& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    friend bool operator>(const Vector2d<T>& first, const Vector2d<T>& second)
    {
        return (first.x > second.x) && (first.y > second.y);
    }

    friend bool operator>=(const Vector2d<T>& first, const Vector2d<T>& second)
    {
        return (first.x >= second.x) && (first.y >= second.y);
    }

    friend bool operator<(const Vector2d<T>& first, const Vector2d<T>& second)
    {
        return (first.x < second.x) && (first.y < second.y);
    }

    friend bool operator<=(const Vector2d<T>& first, const Vector2d<T>& second)
    {
        return (first.x <= second.x) && (first.y <= second.y);
    }

    void operator=(const Vector2d<T>& other)
    {
        this->x = other.x;
        this->y = other.y;
    }

    // Vector2d& operator+(const Vector2d<T>& other)
    // {
    //     this.x += other.x;
    //     this.y += other.y;
    //     return this;
    // }

    // Vector2d& operator-(const Vector2d& other)
    // {
    //     this.x -= other.x;
    //     this.y -= other.y;
    //     return this;
    // }

    // Vector2d& operator*(const Vector2d& other)
    // {
    //     this.x *= other.x;
    //     this.y *= other.y;
    //     return this;
    // }

    // Vector2d& operator/(const Vector2d& other)
    // {
    //     this.x /= other.x;
    //     this.y /= other.y;
    //     return this;
    // }


    // friend Vector2d<T> operator+=(const Vector2d<T>& first, const Vector2d<T>& second)
    // {
    //     return Vector2d<T>(first.x + second.x, first.y + second.y);
    // }
public:
    T x;
    T y;


};