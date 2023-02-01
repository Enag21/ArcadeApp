#ifndef AARECTANGLE_H
#define AARECTANGLE_H

#include "Shape.h"

class AARectangle : Shape
{
public: 
    AARectangle();
    AARectangle(const Vector2D& topLeft, unsigned int width, unsigned int height);
    AARectangle(const Vector2D& topLeft, const Vector2D& bottomRight);

    inline void SetTopLeftPoint(const Vector2D& topLeft) { m_Points[0] = topLeft; }
    inline void SetBottomRightPoint(const Vector2D& bottomRight) { m_Points[1] = bottomRight; }

    inline Vector2D GetTopLeftPoint() const { return m_Points[0]; } 
    inline Vector2D GetBottomRightPoint() const { return m_Points[1]; } 

    float GetWidth() const;
    float GetHeight() const;

    void MoveTo(Vector2D& position);

    virtual Vector2D GetCenterPoint() const override;

    bool Intersects(AARectangle& otherRectangle) const;
    bool ContainsPoint(Vector2D& point) const;

    static AARectangle Inset(AARectangle& rect, Vector2D& insets);

    virtual std::vector<Vector2D> GetPoints() const override;
};

#endif