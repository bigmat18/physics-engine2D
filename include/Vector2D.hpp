#pragma once
#include <string>

class Vector2D
{
public:
    float x;
    float y;

    Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y){};

    Vector2D &operator+=(const Vector2D &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2D &operator+=(float scalar)
    {
        x += scalar;
        y += scalar;
        return *this;
    }

    Vector2D &operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2D &operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    float Dot(const Vector2D &other) const
    {
        return x * other.x + y * other.y;
    }

    float Cross(const Vector2D &other) const
    {
        return x * other.y - y * other.x;
    }

    float Norm() const
    {
        return std::sqrt(x * x + y * y);
    }

    void Normalize()
    {
        float norm = Norm();
        if (norm != 0)
            *this /= norm;
    }

    operator std::string() const
    {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};