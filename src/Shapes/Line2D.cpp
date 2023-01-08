#include "Line2D.h"
#include <Utils.h>


Line2D::Line2D()
	:	Line2D{ Vector2D::Zero, Vector2D::Zero }
{
}

Line2D::Line2D(double x0, double y0, double x1, double y1)
	:	Line2D{ Vector2D{ x0, y0 }, Vector2D{ x1, y1 }}
{
}

Line2D::Line2D(Vector2D p0, Vector2D p1)
	:	m_P0{ std::move(p0) }
	,	m_P1{ std::move(p1) }
{
}

bool Line2D::operator==(const Line2D& rhs) const
{
	return (rhs.GetP0() == m_P0) && (rhs.GetP1() == m_P1);
}

float Line2D::MinDistanceFromPoint(const Vector2D& point, bool limitToSegment) const
{
	return (point - ClosestPoint(point)).Magnitude();
}

Vector2D Line2D::ClosestPoint(const Vector2D& point, bool limitToSegment) const
{

	Vector2D p0ToPoint{ point - m_P0 };
	Vector2D unitLineVector{ (m_P1 - m_P0).Normalize() };

	double distanceToClosestPoint{ p0ToPoint * unitLineVector };

	return unitLineVector * distanceToClosestPoint;
}

Vector2D Line2D::MidPoint() const
{

	return Vector2D{ (m_P0.getX() + m_P1.getX()) / 2.0, (m_P0.getY() + m_P1.getY()) / 2.0 };
}

double Line2D::Slope() const
{
	double deltaX{ m_P1.getX() - m_P0.getX() };
	double deltaY{ m_P1.getY() - m_P0.getY() };

	// Check is the slope is infinite
	if (IsEqual(deltaX, 0.0))
	{
		return -1.0;
	}

	return deltaY / deltaX;
}

double Line2D::Length() const
{
	return m_P0.Distance(m_P1);
}
