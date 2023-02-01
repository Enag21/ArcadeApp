#include "AARectangle.h"
#include "../Utils/Utils.h"
#include <cmath>

AARectangle::AARectangle()
    : AARectangle(Vector2D::Zero, Vector2D::Zero)
{}

AARectangle::AARectangle(const Vector2D& topLeft, unsigned int width, unsigned int height)
    : AARectangle(topLeft, Vector2D(topLeft.getX() + width - 1, topLeft.getY() + height - 1))
{}

AARectangle::AARectangle(const Vector2D& topLeft, const Vector2D& bottomRight)
{
    m_Points.push_back(topLeft);
    m_Points.push_back(bottomRight);
}

float AARectangle::GetWidth() const
{
    return GetBottomRightPoint().getX() - GetTopLeftPoint().getX() + 1;
}

float AARectangle::GetHeight() const
{
    return GetTopLeftPoint().getY() - GetBottomRightPoint().getY() + 1;
}

void AARectangle::MoveTo(Vector2D& position)
{
    float width { GetWidth() };
    float height { GetHeight() };

    SetTopLeftPoint(position);
    SetBottomRightPoint(Vector2D(position.getX() + width - 1, position.getY() + height - 1));
}

Vector2D AARectangle::GetCenterPoint() const
{
    return Vector2D(GetTopLeftPoint().getX() + GetWidth() / 2.0f, GetTopLeftPoint().getY() + GetHeight() / 2.0f);
}

bool AARectangle::Intersects(AARectangle& otherRectangle) const
{
    return !(otherRectangle.GetBottomRightPoint().getX() < GetTopLeftPoint().getX() ||
            otherRectangle.GetTopLeftPoint().getX() > GetBottomRightPoint().getX() ||
            otherRectangle.GetBottomRightPoint().getY() < GetTopLeftPoint().getY() ||
            otherRectangle.GetTopLeftPoint().getY() > GetBottomRightPoint().getY());
}

bool AARectangle::ContainsPoint(Vector2D& point) const
{
    bool withinX = point.getX() >= GetTopLeftPoint().getX() && point.getX() <= GetBottomRightPoint().getX();
    bool withinY = point.getY() >= GetTopLeftPoint().getY() && point.getY() <= GetBottomRightPoint().getY();

    return withinX && withinY;    
}

AARectangle AARectangle::Inset(AARectangle& rect, Vector2D& insets)
{
    return AARectangle(rect.GetTopLeftPoint() + insets, rect.GetWidth() - 2 * insets.getX(), rect.GetHeight() - 2 * insets.getY());
}

std::vector<Vector2D> AARectangle::GetPoints() const
{
    std::vector<Vector2D> points{};

    points.push_back(m_Points[0]);
    points.push_back(Vector2D(m_Points[1].getX(), m_Points[0].getY()));
    points.push_back(m_Points[1]);
    points.push_back(Vector2D(m_Points[0].getX(), m_Points[1].getY()));

    return points;
}