#include "Vector2D.h"
#include <stdexcept>
#include <cmath>

const Vector2D Vector2D::Zero{};

Vector2D operator*(double scalar, const Vector2D& rhs)
{
	return rhs * scalar;
}

std::ostream& operator<<(std::ostream& consoleOut, const Vector2D& vector)
{
	consoleOut << "X: " << vector.m_x << " Y: " << vector.m_y << "\n";
	return consoleOut;
}

Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs)
{
	return Vector2D(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY());
}

Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs)
{
	return lhs + (-rhs);
}

double operator*(const Vector2D& lhs, const Vector2D& rhs)
{
	return lhs.getX() * rhs.getX() + lhs.getY() * rhs.getY();
}

bool Vector2D::operator==(const Vector2D& rhs) const
{
	return ( IsEqual(m_x, rhs.m_x) && IsEqual(m_y, rhs.m_y) );
}

Vector2D Vector2D::operator-() const
{
	return Vector2D(-m_x, -m_y);
}

Vector2D Vector2D::operator*(double scalar) const
{
	return Vector2D(scalar * m_x, scalar * m_y);
}

Vector2D Vector2D::operator/(double scalar) const
{
	if (!IsEqual(0.0, scalar))
	{
		return  Vector2D(m_x / scalar, m_y / scalar);
	}
	throw std::invalid_argument{ "Atempting to divide by zero" };
}

Vector2D& Vector2D::operator*=(double scalar)
{
	*this = *this * scalar;
	return *this;
}

Vector2D& Vector2D::operator/=(double scalar)
{
	if (!IsEqual(0.0, scalar))
	{
		*this = *this / scalar;
		return *this;
	}
	throw std::invalid_argument{ "Atempting to divide by zero" };
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& rhs)
{
	*this = *this - rhs;
	return *this;
}

double Vector2D::Magnitude2() const
{
	return (*this) * (*this);
}

double Vector2D::Magnitude() const
{
	return hypot(m_x, m_y);
}

Vector2D Vector2D::Direction() const
{
	return *this / Magnitude();
}

Vector2D& Vector2D::Normalize()
{
	*this /= Magnitude();
	return *this;
}

double Vector2D::Distance(const Vector2D& vector) const
{
	return ( *this - vector ).Magnitude();
}

Vector2D Vector2D::ProjectOnTo(const Vector2D& src) const
{
	return (*this) * src.Direction() * src.Direction();
}

double Vector2D::AngleBetween(const Vector2D& src) const
{
	Vector2D vector1{ Direction() };
	Vector2D vector2{ src.Direction() };

	return acosf( vector1 * vector2 );
}

void Vector2D::Rotate(float angle, const Vector2D& aroundPoint)
{
	float cosine = cosf(angle);
	float sine = sinf(angle);

	Vector2D thisVec(m_x, m_y);

	thisVec -= aroundPoint;

	float xRot = thisVec.m_x * cosine - thisVec.m_y * sine;
	float yRot = thisVec.m_x * sine + thisVec.m_y * cosine;

	Vector2D rot = Vector2D(xRot, yRot);

	*this = rot + aroundPoint;
}

Vector2D Vector2D::Reflect(const Vector2D& normal) const
{
	return (*this) -2 * ProjectOnTo(normal);
}

Vector2D Vector2D::RotationResult(double angle) const
{
	double cosine{ cos(angle) };
	double sine{ sin(angle) };

	return Vector2D{ m_x * cosine - m_y * sine, m_x * sine + m_y * cosine};
}
