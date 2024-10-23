#pragma once

#include <cmath>

struct Vector3 {

	union {
		float x;
		float y;
		float z;
	};

	Vector3() 
	{
		this->x = 0.f;
		this->y = 0.f;
		this->z = 0.f;
	}

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3 operator+(const Vector3& other) const
	{
		return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
	}

	Vector3 operator-(const Vector3& other) const
	{
		return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
	}

	Vector3 operator*(const Vector3& other) const
	{
		return Vector3(this->x * other.x, this->y * other.y, this->z * other.z);
	}

	Vector3 operator/(const Vector3& other) const
	{
		return Vector3(this->x / other.x, this->y / other.y, this->z / other.z);
	}

	Vector3 operator*(const float& other) const
	{
		return Vector3(this->x * other, this->y * other, this->z * other);
	}

	Vector3 operator/(const float& other) const
	{
		return Vector3(this->x / other, this->y / other, this->z / other);
	}

	Vector3 operator+=(const Vector3& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		return *this;
	}

	Vector3 operator-=(const Vector3& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		return *this;
	}

	Vector3 operator*=(const Vector3& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		return *this;
	}

	Vector3 operator/=(const Vector3& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		return *this;
	}

	Vector3 operator*=(const float& other)
	{
		this->x *= other;
		this->y *= other;
		this->z *= other;
		return *this;
	}

	Vector3 operator/=(const float& other)
	{
		this->x /= other;
		this->y /= other;
		this->z /= other;
		return *this;
	}

	bool operator==(const Vector3& other) const
	{
		return this->x == other.x && this->y == other.y && this->z == other.z;
	}

	bool operator!=(const Vector3& other) const
	{
		return this->x != other.x || this->y != other.y || this->z != other.z;
	}

	bool operator>(const Vector3& other) const
	{
		return this->x > other.x && this->y > other.y && this->z > other.z;
	}

	bool operator<(const Vector3& other) const
	{
		return this->x < other.x && this->y < other.y && this->z < other.z;
	}

	bool operator>=(const Vector3& other) const
	{
		return this->x >= other.x && this->y >= other.y && this->z >= other.z;
	}

	bool operator<=(const Vector3& other) const
	{
		return this->x <= other.x && this->y <= other.y && this->z <= other.z;
	}

	float Dot(const Vector3& other) const
	{
		return this->x * other.x + this->y * other.y + this->z * other.z;
	}

	float Magnitude() const
	{
		return sqrtf(this->x * this->x + this->y * this->y + this->z + this->z);
	}

	Vector3 Normalize() const
	{
		float magnitude = this->Magnitude();
		if (magnitude == 0.f)
		{
			return Vector3(0.f, 0.f, 0.f);
		}
		return Vector3(this->x / magnitude, this->y / magnitude, this->z / magnitude);
	}

};