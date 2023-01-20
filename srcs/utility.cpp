#include "utility.h"

vec2::vec2 () : x(0.0), y(0.0) {}

vec2::vec2 (float ax, float ay) : x(ax), y(ay) {}

float &vec2::operator[] (unsigned int index)
{
	if (index <= 1)
		return index == 0 ? x : y;
	else
		return x;
}

vec2 vec2::operator- ()
{
	return vec2(-x, -y);
}

vec2 &vec2::operator= (const vec2 &right)
{
	x = right.x;
	y = right.y;
	return *this;
}

vec2 &vec2::operator+= (const vec2 &right)
{
	x += right.x;
	y += right.y;
	return *this;
}

vec2 &vec2::operator-= (const vec2 &right)
{
	x -= right.x;
	y -= right.y;
	return *this;
}

vec2 &vec2::operator/= (const float &right)
{
	x /= right;
	y /= right;
	return *this;
}

vec2 &vec2::operator*= (const float &right)
{
	x *= right;
	y *= right;
	return *this;
}

vec2 operator+ (const vec2 &left, const vec2 &right)
{
	return vec2(left.x + right.x, left.y + right.y);
}

vec2 operator- (const vec2 &left, const vec2 &right)
{
	return vec2(left.x - right.x, left.y - right.y);
}

vec2 operator/ (const vec2 &left, const float &right)
{
	if (right != 0)
		return vec2(left.x / right, left.y / right);
	else
		return vec2(0.0, 0.0);
}

vec2 operator* (const vec2 &left, const float &right)
{
	return vec2(left.x * right, left.y * right);
}

vec2 operator* (const float &left, const vec2 &right)
{
	return vec2(left * right.x, left * right.y);
}
