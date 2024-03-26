#include <cmath>
#include "math_types.h"

namespace Engine
{
    Vector2::Vector2() : x(0), y(0) {}
    Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}
    Vector2::Vector2(const Vector2Int& other) : x(other.x), y(other.y) {}

    Vector2 Vector2::operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Vector2::operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 Vector2::operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2 Vector2::operator/(float scalar) const {
        return Vector2(x / scalar, y / scalar);
    }

    Vector2& Vector2::operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2& Vector2::operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2& Vector2::operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2& Vector2::operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    float Vector2::dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }

    float Vector2::magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2 Vector2::normalized() const {
        float mag = magnitude();
        return mag == 0 ? Vector2() : *this / mag;
    }

    float Vector2::angle(const Vector2& other) const {
        return std::atan2(y, x) - std::atan2(other.y, other.x);
    }

    Vector2Int::Vector2Int() : x(0), y(0) {}
    Vector2Int::Vector2Int(int _x, int _y) : x(_x), y(_y) {}
    Vector2Int::Vector2Int(const Vector2& other) : x(static_cast<int>(other.x)), y(static_cast<int>(other.y)) {}

    Vector2Int Vector2Int::operator+(const Vector2Int& other) const {
        return Vector2Int(x + other.x, y + other.y);
    }

    Vector2Int Vector2Int::operator-(const Vector2Int& other) const {
        return Vector2Int(x - other.x, y - other.y);
    }

    Vector2Int Vector2Int::operator*(int scalar) const {
        return Vector2Int(x * scalar, y * scalar);
    }

    Vector2Int Vector2Int::operator/(int scalar) const {
        return Vector2Int(x / scalar, y / scalar);
    }

    Vector2Int& Vector2Int::operator+=(const Vector2Int& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2Int& Vector2Int::operator-=(const Vector2Int& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2Int& Vector2Int::operator*=(int scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2Int& Vector2Int::operator/=(int scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    int Vector2Int::dot(const Vector2Int& other) const {
        return x * other.x + y * other.y;
    }

    float Vector2Int::magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2Int Vector2Int::normalized() const {
        int mag = magnitude();
        return mag == 0 ? Vector2Int() : *this / mag;
    }

    float Vector2Int::angle(const Vector2Int& other) const {
        return std::atan2(y, x) - std::atan2(other.y, other.x);
    }

    bool Rect::overlaps(Rect other) const
    {
        return x <= other.x + static_cast<int>(other.width) && other.x <= x + static_cast<int>(width) &&
            y <= other.y + static_cast<int>(other.height) && other.y <= y + static_cast<int>(height);
    }

    int Rect::getX() const
    {
        return x;
    }

    int Rect::getY() const
    {
        return y;
    }

    uint32_t Rect::getWidth() const
    {
        return width;
    }

    uint32_t Rect::getHeight() const
    {
        return height;
    }
}