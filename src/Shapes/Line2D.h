#pragma once

#ifndef LINE2D_H
#define LINE2D_H

#include "../Utils/Vector2D.h"

class Line2D
{
public:
	Line2D();
	Line2D(double x0, double y0, double x1, double y1);
	Line2D(Vector2D p0, Vector2D p1);

	inline const Vector2D& GetP0() const { return m_P0; }
	inline const Vector2D& GetP1() const { return m_P1; }

	inline void SetP0(Vector2D p0) { m_P0 = std::move(p0); }
	inline void SetP1(Vector2D p1) { m_P1 = std::move(p1); }

	bool operator==(const Line2D& rhs) const;

	float MinDistanceFromPoint(const Vector2D& point, bool limitToSegment = false) const;

	Vector2D ClosestPoint(const Vector2D& point, bool limitToSegment = false) const;

	Vector2D MidPoint() const;

	double Slope() const;

	double Length() const;

private:
	Vector2D m_P0{};
	Vector2D m_P1{};
};

#endif // !LINE2D_H
