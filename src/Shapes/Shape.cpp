#include "Shape.h"


void Shape::MoveBy(const Vector2D& deltaOffSet)
{
    for(auto& point : m_Points)
    {
        point = point + deltaOffSet;
    }
}