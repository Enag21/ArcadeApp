#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "../Utils/Vector2D.h"

class Shape
{
public:
    virtual Vector2D GetCenterPoint() const = 0;
    virtual ~Shape() = default;
    inline virtual std::vector<Vector2D> GetPoints() const { return m_Points; }
    virtual void MoveBy(const Vector2D& deltaOffSet);

protected:
    std::vector<Vector2D> m_Points{};
};

#endif