#include "Circle.h"
#include "../Utils/Utils.h"

Circle::Circle() : Circle(Vector2D::Zero, 0.0) {}
Circle::Circle(const Vector2D& center, float radius)
    :   m_Radius{ radius }
{
    m_Points.push_back(center);
}

bool Circle::Intersects(const Circle& otherCircle) const
{
    return (GetCenterPoint().Distance(otherCircle.GetCenterPoint())) < (m_Radius + otherCircle.GetRadius());
}

bool Circle::ContainsPoint(const Vector2D& point) const
{
    return IsLesserOrEqual(GetCenterPoint().Distance(point), m_Radius);
}