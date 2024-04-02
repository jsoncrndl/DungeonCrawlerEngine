#include <cmath>
#include <format>
#include "math_types.h"

namespace Engine
{
    Vector2::Vector2() : x(0), y(0) {}
    Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}
    Vector2::Vector2(const Vector2Int& other) : x(static_cast<float>(other.x)), y(static_cast<float>(other.y)) {}

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
        return static_cast<float>(std::sqrt(x * x + y * y));
    }

    float Vector2Int::angle(const Vector2Int& other) const {
        return static_cast<float>(std::atan2(y, x) - std::atan2(other.y, other.x));
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

    Matrix3x3::MatrixRowView::MatrixRowView(float* start) : m_start(start)
    {
    }

    float& Matrix3x3::MatrixRowView::operator[](uint8_t offset)
    {
        return m_start[offset];
    }
    Matrix3x3::Matrix3x3(std::array<float, 9> data) : m_data(data)
    {
    }

    const float* Matrix3x3::getData() const
    {
        return m_data.data();
    }

    Matrix3x3 Matrix3x3::transposed() const
    {
        return Matrix3x3({
            m_data[0], m_data[3], m_data[6],
            m_data[1], m_data[4], m_data[7], 
            m_data[2], m_data[5], m_data[8]});
    }

    void Matrix3x3::transpose()
    {
        float temp = m_data[1];
        m_data[1] = m_data[3];
        m_data[3] = temp;

        temp = m_data[2];
        m_data[2] = m_data[6];
        m_data[6] = temp;

        temp = m_data[5];
        m_data[5] = m_data[7];
        m_data[7] = temp;
    }

    std::string Matrix3x3::toString() const
    {
        return std::format("[{0}, {1}, {2},\n {3}, {4}, {5},\n {6}, {7}, {8}]", m_data[0], m_data[1], m_data[2], m_data[3], m_data[4], m_data[5], m_data[6], m_data[7], m_data[8]);
    }

    Matrix3x3::MatrixRowView Matrix3x3::operator[](uint8_t offset)
    {
        return MatrixRowView(m_data.data() + offset);
    }
    Matrix3x3 Matrix3x3::operator+(const Matrix3x3& other) const
    {
        return Matrix3x3({
            m_data[0] + other.m_data[0], m_data[1] + other.m_data[1], m_data[2] + other.m_data[2],
            m_data[3] + other.m_data[3], m_data[4] + other.m_data[4], m_data[5] + other.m_data[5],
            m_data[6] + other.m_data[6], m_data[7] + other.m_data[7], m_data[8] + other.m_data[8]
            });
    }
    Matrix3x3 Matrix3x3::operator-(const Matrix3x3& other) const
    {
        return Matrix3x3({
            m_data[0] - other.m_data[0], m_data[1] - other.m_data[1], m_data[2] - other.m_data[2],
            m_data[3] - other.m_data[3], m_data[4] - other.m_data[4], m_data[5] - other.m_data[5],
            m_data[6] - other.m_data[6], m_data[7] - other.m_data[7], m_data[8] - other.m_data[8]
            });
    }

    // 0, 1, 2,     0, 1, 2      
    // 3, 4, 5,  *  3, 4, 5
    // 6, 7, 8      6, 7, 8


    Matrix3x3 Matrix3x3::operator*(const Matrix3x3& other) const
    {
        return Matrix3x3({
            m_data[0] * other.m_data[0] + m_data[1] * other.m_data[3] + m_data[2] * other.m_data[6], m_data[0] * other.m_data[1] + m_data[1] * other.m_data[4] + m_data[2] * other.m_data[7], m_data[0] * other.m_data[2] + m_data[1] * other.m_data[5] + m_data[2] * other.m_data[8],
            m_data[3] * other.m_data[0] + m_data[4] * other.m_data[3] + m_data[5] * other.m_data[6], m_data[3] * other.m_data[1] + m_data[4] * other.m_data[4] + m_data[5] * other.m_data[7], m_data[3] * other.m_data[2] + m_data[4] * other.m_data[5] + m_data[5] * other.m_data[8],
            m_data[6] * other.m_data[0] + m_data[7] * other.m_data[3] + m_data[8] * other.m_data[6], m_data[6] * other.m_data[1] + m_data[7] * other.m_data[4] + m_data[8] * other.m_data[7], m_data[6] * other.m_data[2] + m_data[7] * other.m_data[5] + m_data[8] * other.m_data[8],
            });
    }
    Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& other)
    {
        m_data[0] += other.m_data[0];
        m_data[1] += other.m_data[1];
        m_data[2] += other.m_data[2];
        m_data[3] += other.m_data[3];
        m_data[4] += other.m_data[4];
        m_data[5] += other.m_data[5];
        m_data[6] += other.m_data[6];
        m_data[7] += other.m_data[7];
        m_data[8] += other.m_data[8];
        return *this;
    }
    Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& other)
    {
        m_data[0] += other.m_data[0];
        m_data[1] += other.m_data[1];
        m_data[2] += other.m_data[2];
        m_data[3] += other.m_data[3];
        m_data[4] += other.m_data[4];
        m_data[5] += other.m_data[5];
        m_data[6] += other.m_data[6];
        m_data[7] += other.m_data[7];
        m_data[8] += other.m_data[8];
        return *this;
    }

    Matrix3x3& Matrix3x3::operator*=(const Matrix3x3& other)
    {
        float m0 = m_data[0] * other.m_data[0] + m_data[1] * other.m_data[3] + m_data[2] * other.m_data[6];
        float m1 = m_data[0] * other.m_data[1] + m_data[1] * other.m_data[4] + m_data[2] * other.m_data[7];
        float m2 = m_data[0] * other.m_data[2] + m_data[1] * other.m_data[5] + m_data[2] * other.m_data[8];
        float m3 = m_data[3] * other.m_data[0] + m_data[4] * other.m_data[3] + m_data[5] * other.m_data[6];
        float m4 = m_data[3] * other.m_data[1] + m_data[4] * other.m_data[4] + m_data[5] * other.m_data[7];
        float m5 = m_data[3] * other.m_data[2] + m_data[4] * other.m_data[5] + m_data[5] * other.m_data[8];
        float m6 = m_data[6] * other.m_data[0] + m_data[7] * other.m_data[3] + m_data[8] * other.m_data[6];
        float m7 = m_data[6] * other.m_data[1] + m_data[7] * other.m_data[4] + m_data[8] * other.m_data[7];
        float m8 = m_data[6] * other.m_data[2] + m_data[7] * other.m_data[5] + m_data[8] * other.m_data[8];

        m_data[0] = m0;
        m_data[1] = m1;
        m_data[2] = m2;
        m_data[3] = m3;
        m_data[4] = m4;
        m_data[5] = m5;
        m_data[6] = m6;
        m_data[7] = m7;
        m_data[8] = m8;

        return *this;
    }

    const Matrix3x3 Matrix3x3::identity = Matrix3x3({ 1, 0, 0, 0, 1, 0, 0, 0, 1 });
}