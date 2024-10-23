#pragma once

#include <cmath>

struct Vector2 {

	union {
		float x;
		float y;
	};

	Vector2() 
	{
		this->x = 0.f;
		this->y = 0.f;
	}

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(this->x + other.x, this->y + other.y);
	}

	Vector2 operator-(const Vector2& other) const
	{
		return Vector2(this->x - other.x, this->y - other.y);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Vector2(this->x * other.x, this->y * other.y);
	}

	Vector2 operator/(const Vector2& other) const
	{
		return Vector2(this->x / other.x, this->y / other.y);
	}

	Vector2 operator*(const float& other) const
	{
		return Vector2(this->x * other, this->y * other);
	}

	Vector2 operator/(const float& other) const
	{
		return Vector2(this->x / other, this->y / other);
	}

	Vector2 operator+=(const Vector2& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	Vector2 operator-=(const Vector2& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}

	Vector2 operator*=(const Vector2& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}

	Vector2 operator/=(const Vector2& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}

	Vector2 operator*=(const float& other)
	{
		this->x *= other;
		this->y *= other;
		return *this;
	}

	Vector2 operator/=(const float& other)
	{
		this->x /= other;
		this->y /= other;
		return *this;
	}

	bool operator==(const Vector2& other) const
	{
		return this->x == other.x && this->y == other.y;
	}

	bool operator!=(const Vector2& other) const
	{
		return this->x != other.x || this->y != other.y;
	}

	bool operator>(const Vector2& other) const
	{
		return this->x > other.x && this->y > other.y;
	}

	bool operator<(const Vector2& other) const
	{
		return this->x < other.x && this->y < other.y;
	}

	bool operator>=(const Vector2& other) const
	{
		return this->x >= other.x && this->y >= other.y;
	}

	bool operator<=(const Vector2& other) const
	{
		return this->x <= other.x && this->y <= other.y;
	}

	float Dot(const Vector2& other) const
	{
		return this->x * other.x + this->y * other.y;
	}

	float Magnitude() const
	{
		return sqrtf(this->x * this->x + this->y * this->y);
	}

	Vector2 Normalize() const
	{
		float magnitude = this->Magnitude();
		if (magnitude == 0.f)
		{
			return Vector2(0.f, 0.f);
		}
		return Vector2(this->x / magnitude, this->y / magnitude);
	}

};