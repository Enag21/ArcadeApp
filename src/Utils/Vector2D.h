#pragma once

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include "Utils.h"

class Vector2D
{
public:
	static const Vector2D Zero;

	Vector2D() : Vector2D{ 0, 0 } {}
	Vector2D(const double& x, const double& y)
		: m_x{ x }
		, m_y{ y }
	{}

	// Overloaded operators
	[[nodiscard]] bool operator==(const Vector2D& rhs) const;
	Vector2D operator-() const;
	Vector2D operator*(double scalar) const;
	Vector2D operator/(double scalar) const;
	Vector2D& operator*=(double scalar);
	Vector2D& operator/=(double scalar);
	Vector2D& operator+=(const Vector2D& rhs);
	Vector2D& operator-=(const Vector2D& rhs);
	friend Vector2D operator*(double scalar, const Vector2D& rhs);
	friend std::ostream& operator<<(std::ostream& consoleOut, const Vector2D& vector);

	// Methods
	inline double getX() const { return m_x; }
	inline double getY() const { return m_y; }
	double Magnitude2() const;
	double Magnitude() const;
	Vector2D Direction() const;
	Vector2D& Normalize();

	double Distance(const Vector2D& vector) const;
	Vector2D ProjectOnTo(const Vector2D& src) const;
	double AngleBetween(const Vector2D& src) const;
	void Rotate(float angle, const Vector2D& aroundPoint);
	Vector2D Reflect(const Vector2D& normal) const;
	Vector2D RotationResult(double angle) const;


private:
	double m_x;
	double m_y;
};

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs);
Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs);
double operator*(const Vector2D& lhs, const Vector2D& rhs);


#endif // !VECTOR2D_H
