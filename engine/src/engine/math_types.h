#pragma once
#include <array>
#include <string>

namespace Engine
{

    struct Vector2Int;

    struct Vector2 {
        Vector2();
        Vector2(float _x, float _y);
        Vector2(const Vector2Int& other);
        Vector2(const Vector2& other);

        float x;
        float y;

        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
        Vector2 operator*(float scalar) const;
        Vector2 operator/(float scalar) const;
        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        Vector2& operator*=(float scalar);
        Vector2& operator/=(float scalar);
        Vector2& operator=(const Vector2& other);
        bool operator==(const Vector2& other);
        bool operator!=(const Vector2& other);


        float dot(const Vector2& other) const;
        float magnitude() const;
        Vector2 normalized() const;
        float angle(const Vector2& other) const;

        static const Vector2 zero;
        static const Vector2 one;
        static const Vector2 right;
        static const Vector2 up;
    };

    struct Vector2Int {
        Vector2Int();
        Vector2Int(int _x, int _y);
        Vector2Int(const Vector2& other);

        int x, y;

        Vector2Int operator+(const Vector2Int& other) const;
        Vector2Int operator-(const Vector2Int& other) const;
        Vector2Int operator*(int scalar) const;
        Vector2Int operator/(int scalar) const;
        Vector2Int& operator+=(const Vector2Int& other);
        Vector2Int& operator-=(const Vector2Int& other);
        Vector2Int& operator*=(int scalar);
        Vector2Int& operator/=(int scalar);
        int dot(const Vector2Int& other) const;
        float magnitude() const;
        float angle(const Vector2Int& other) const;
    };

    class Matrix3x3
    {
        struct MatrixRowView
        {
            friend class Matrix3x3;
        private:
            float* m_start;
            MatrixRowView(float* start);

        public:
            float& operator[](uint8_t offset);
        };

    public:
        static const Matrix3x3 identity;

    private:
        std::array<float, 9> m_data;

        
    public:

        Matrix3x3(std::array<float, 9> data);

        const float* getData() const;
        
        Matrix3x3 transposed() const;
        void transpose();

        std::string toString() const;
        
        MatrixRowView operator[](uint8_t offset);
        
        Matrix3x3 operator+(const Matrix3x3& other) const;
        Matrix3x3 operator-(const Matrix3x3& other) const;
        Matrix3x3 operator*(const Matrix3x3& other) const;
        Matrix3x3& operator+=(const Matrix3x3& other);
        Matrix3x3& operator*=(const Matrix3x3& other);
        Matrix3x3& operator-=(const Matrix3x3& other);
    };

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

} // Engine