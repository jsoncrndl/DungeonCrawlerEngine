#pragma once
//#include <cmath>
//
namespace Engine
{
//
//    // For this section of code I decided to try using ChatGPT to generate the vector classes. This was mostly to save time on a repetetive task and see how it did.
//    // 
//    // It took a few prompts, but I eventually got something I was happy with:
//    // 1. Give me a c++ Vector2 struct that is header only, all constexpr and supports all major operations with overloading
//    // 2. Thanks, also include += and -=
//    // 3. And *= and /=
//    // 4. Give me a Vector2Int struct that does the same but limited to integers
//    // 5. Do I need to update the code some way to allow static_cast<> to work between the two?
//    // 6. Thank you, can you do the same to allow for conversion from Vector2 to Vector2Int with truncating? Also please separate the operation signatures from the definitions 
//
//    struct Vector2Int;
//
//    struct Vector2 {
//        constexpr Vector2();
//        constexpr Vector2(float _x, float _y);
//        constexpr Vector2(const Vector2Int& other);
//
//        float x, y;
//
//        constexpr Vector2 operator+(const Vector2& other) const;
//        constexpr Vector2 operator-(const Vector2& other) const;
//        constexpr Vector2 operator*(float scalar) const;
//        constexpr Vector2 operator/(float scalar) const;
//        constexpr Vector2& operator+=(const Vector2& other);
//        constexpr Vector2& operator-=(const Vector2& other);
//        constexpr Vector2& operator*=(float scalar);
//        constexpr Vector2& operator/=(float scalar);
//        constexpr float dot(const Vector2& other) const;
//        constexpr float magnitude() const;
//        constexpr Vector2 normalized() const;
//        constexpr float angle(const Vector2& other) const;
//    };
//
//    struct Vector2Int {
//        constexpr Vector2Int();
//        constexpr Vector2Int(int _x, int _y);
//        constexpr Vector2Int(const Vector2& other);
//
//        int x, y;
//
//        constexpr Vector2Int operator+(const Vector2Int& other) const;
//        constexpr Vector2Int operator-(const Vector2Int& other) const;
//        constexpr Vector2Int operator*(int scalar) const;
//        constexpr Vector2Int operator/(int scalar) const;
//        constexpr Vector2Int& operator+=(const Vector2Int& other);
//        constexpr Vector2Int& operator-=(const Vector2Int& other);
//        constexpr Vector2Int& operator*=(int scalar);
//        constexpr Vector2Int& operator/=(int scalar);
//        constexpr int dot(const Vector2Int& other) const;
//        constexpr float magnitude() const;
//        constexpr Vector2Int normalized() const;
//        constexpr float angle(const Vector2Int& other) const;
//    };
//
//    Vector2::Vector2() : x(0), y(0) {}
//    Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}
//    constexpr Vector2::Vector2(const Vector2Int& other) : x(other.x), y(other.y) {}
//
//    constexpr Vector2 Vector2::operator+(const Vector2& other) const {
//        return Vector2(x + other.x, y + other.y);
//    }
//
//    constexpr Vector2 Vector2::operator-(const Vector2& other) const {
//        return Vector2(x - other.x, y - other.y);
//    }
//
//    constexpr Vector2 Vector2::operator*(float scalar) const {
//        return Vector2(x * scalar, y * scalar);
//    }
//
//    constexpr Vector2 Vector2::operator/(float scalar) const {
//        return Vector2(x / scalar, y / scalar);
//    }
//
//    constexpr Vector2& Vector2::operator+=(const Vector2& other) {
//        x += other.x;
//        y += other.y;
//        return *this;
//    }
//
//    constexpr Vector2& Vector2::operator-=(const Vector2& other) {
//        x -= other.x;
//        y -= other.y;
//        return *this;
//    }
//
//    constexpr Vector2& Vector2::operator*=(float scalar) {
//        x *= scalar;
//        y *= scalar;
//        return *this;
//    }
//
//    constexpr Vector2& Vector2::operator/=(float scalar) {
//        x /= scalar;
//        y /= scalar;
//        return *this;
//    }
//
//    constexpr float Vector2::dot(const Vector2& other) const {
//        return x * other.x + y * other.y;
//    }
//
//    constexpr float Vector2::magnitude() const {
//        return std::sqrt(x * x + y * y);
//    }
//
//    constexpr Vector2 Vector2::normalized() const {
//        float mag = magnitude();
//        return mag == 0 ? Vector2() : *this / mag;
//    }
//
//    constexpr float Vector2::angle(const Vector2& other) const {
//        return std::atan2(y, x) - std::atan2(other.y, other.x);
//    }
//
//    constexpr Vector2Int::Vector2Int() : x(0), y(0) {}
//    constexpr Vector2Int::Vector2Int(int _x, int _y) : x(_x), y(_y) {}
//    constexpr Vector2Int::Vector2Int(const Vector2& other) : x(static_cast<int>(other.x)), y(static_cast<int>(other.y)) {}
//
//    constexpr Vector2Int Vector2Int::operator+(const Vector2Int& other) const {
//        return Vector2Int(x + other.x, y + other.y);
//    }
//
//    constexpr Vector2Int Vector2Int::operator-(const Vector2Int& other) const {
//        return Vector2Int(x - other.x, y - other.y);
//    }
//
//    constexpr Vector2Int Vector2Int::operator*(int scalar) const {
//        return Vector2Int(x * scalar, y * scalar);
//    }
//
//    constexpr Vector2Int Vector2Int::operator/(int scalar) const {
//        return Vector2Int(x / scalar, y / scalar);
//    }
//
//    constexpr Vector2Int& Vector2Int::operator+=(const Vector2Int& other) {
//        x += other.x;
//        y += other.y;
//        return *this;
//    }
//
//    constexpr Vector2Int& Vector2Int::operator-=(const Vector2Int& other) {
//        x -= other.x;
//        y -= other.y;
//        return *this;
//    }
//
//    constexpr Vector2Int& Vector2Int::operator*=(int scalar) {
//        x *= scalar;
//        y *= scalar;
//        return *this;
//    }
//
//    constexpr Vector2Int& Vector2Int::operator/=(int scalar) {
//        x /= scalar;
//        y /= scalar;
//        return *this;
//    }
//
//    constexpr int Vector2Int::dot(const Vector2Int& other) const {
//        return x * other.x + y * other.y;
//    }
//
//    constexpr float Vector2Int::magnitude() const {
//        return std::sqrt(x * x + y * y);
//    }
//
//    constexpr Vector2Int Vector2Int::normalized() const {
//        int mag = magnitude();
//        return mag == 0 ? Vector2Int() : *this / mag;
//    }
//
//    constexpr float Vector2Int::angle(const Vector2Int& other) const {
//        return std::atan2(y, x) - std::atan2(other.y, other.x);
//    }
//
//    // End ChatGPT code

    class Rect
    {
        int x;
        int y;
        uint32_t width;
        uint32_t height;

    public:
        Rect(int x, int y, uint32_t width, uint32_t height) : x(x), y(y), width(width), height(height)
        {
        }

        inline bool overlaps(Rect other) const;

        int getX() const;
        int getY() const;
        uint32_t getWidth() const;
        uint32_t getHeight() const;
    };

    inline bool Rect::overlaps(Rect other) const
    {
        return x <= other.x + static_cast<int>(other.width) && other.x <= x + static_cast<int>(width) &&
            y <= other.y + static_cast<int>(other.height) && other.y <= y + static_cast<int>(height);
    }

    inline int Rect::getX() const
    {
        return x;
    }

    inline int Rect::getY() const
    {
        return y;
    }

    inline uint32_t Rect::getWidth() const
    {
        return width;
    }

    inline uint32_t Rect::getHeight() const
    {
        return height;
    }
    

    //class BoundingBox
    //{
    //    float x;
    //    float y;
    //    float width;
    //    float height;


    //public:
    //    BoundingBox(float x, float y, float width, float height) :
    //    
    //        x(std::min(x, x + width)),
    //        y(std::min(y, y + width)),
    //        width(std::abs(width)),
    //        height(std::abs(height))
    //    {
    //    }

    //    bool overlaps(BoundingBox other) const;
    //};

    //bool BoundingBox::overlaps(BoundingBox other) const
    //{
    //    return x <= other.x + other.width && other.x <= x + width &&
    //        y <= other.y + other.height && other.y <= y + height;
    //}

    class Vector2Int {};
} // Engine