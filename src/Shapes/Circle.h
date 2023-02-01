#ifndef CIRCLE_H 
#define CIRCLE_H

#include "Shape.h"

class Circle : Shape
{
public:
    Circle();
    Circle(const Vector2D& center, float radius);

    inline virtual Vector2D GetCenterPoint() const override { return m_Points[0]; } 
    inline float GetRadius() const { return m_Radius; }
    inline void SetRadius(float radius) { m_Radius = radius; }
    inline void MoveTo(const Vector2D& position) { m_Points[0] = position; }

    bool Intersects(const Circle& otherCircle) const;
    bool ContainsPoint(const Vector2D& point) const;

private:
    float m_Radius{};
};


#endif