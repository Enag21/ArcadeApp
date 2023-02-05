#include "Triangle.h"
#include <cmath>
#include "Line2D.h"

Triangle::Triangle() : Triangle(Vector2D::Zero, Vector2D::Zero, Vector2D::Zero)
{}

Triangle::Triangle(const Vector2D& p0, const Vector2D& p1, const Vector2D& p2)
{
    m_Points.push_back(p0);
    m_Points.push_back(p1);
    m_Points.push_back(p2);
}

Vector2D Triangle::GetCenterPoint() const
{

    return Vector2D{ (m_Points[0].getX() + m_Points[1].getX() + m_Points[2].getX()) / 3.0, 
                    (m_Points[0].getY() + m_Points[1].getY() + m_Points[2].getY()) / 3.0 };
}

float Triangle::Area() const
{
    return Area(GetP0(), GetP1(), GetP2());
}

bool Triangle::ContainsPoint(const Vector2D& point) const
{
    float totalArea{ Area(point, GetP0(), GetP1()) + Area(point, GetP0(), GetP2()) + Area(point, GetP1(), GetP2()) };

    return IsEqual(Area(), totalArea);
}

float Triangle::Area(const Vector2D& p0, const Vector2D& p1, const Vector2D& p2) const
{
    return fabs(0.5 * (p0.getX() * (p1.getY() - p2.getY()) + p1.getX() * (p0.getY() - p2.getY()) + p2.getX() * (p0.getY() * p1.getY())));
}

/* void Triangle::MoveTo(const Vector2D& position)
{
    Vector2D deltaOffset{ position - GetCenterPoint() };
    MoveBy(deltaOffset);
} */