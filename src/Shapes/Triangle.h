#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle();
    Triangle(const Vector2D& p0, const Vector2D& p1, const Vector2D& p2);

    inline void SetP0(const Vector2D& point) { m_Points[0] = point; }
    inline void SetP1(const Vector2D& point) { m_Points[1] = point; }
    inline void SetP3(const Vector2D& point) { m_Points[2] = point; }

    inline Vector2D GetP0() const { return m_Points[0]; }
    inline Vector2D GetP1() const { return m_Points[1]; }
    inline Vector2D GetP2() const { return m_Points[2]; }

    virtual Vector2D GetCenterPoint() const override;

    // virtual void MoveTo(const Vector2D& position) override; 

    float Area() const;

    bool ContainsPoint(const Vector2D& point) const;

private:
    float Area(const Vector2D& p0, const Vector2D& p1, const Vector2D& p2) const;
};

#endif