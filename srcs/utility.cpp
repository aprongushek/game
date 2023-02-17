#include "utility.h"

#include <string>
#include <sstream>

#define ERR_OUT_OF_RANGE "index is out of range"
#define ERR_DIVISION_BY_ZERO "division by zero"

const int TILE_SIZE = 81;

int toInt (const std::string &str)
{
	std::stringstream ss;
	int i;
	ss << str;
	ss >> i;
	return i;
}

std::string toStr (int i)
{
	std::stringstream ss;
	std::string str;
	ss << i;
	ss >> str;
	return str;
}

vec2::vec2 () : x(0.0), y(0.0) {}

vec2::vec2 (float ax, float ay) : x(ax), y(ay) {}

float &vec2::operator[] (uint index)
{
	if (index <= 1) {
		return index == 0 ? x : y;
	} else {
		throw ERR_OUT_OF_RANGE;
		return x;
	}
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
	if (right == 0) {
		throw ERR_DIVISION_BY_ZERO;
		return *this;
	} else {
		x /= right;
		y /= right;
		return *this;
	}
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
	if (right != 0) {
		return vec2(left.x / right, left.y / right);
	} else {
		throw ERR_DIVISION_BY_ZERO;
		return vec2(0.0, 0.0);
	}
}

vec2 operator* (const vec2 &left, const float &right)
{
	return vec2(left.x * right, left.y * right);
}

vec2 operator* (const float &left, const vec2 &right)
{
	return vec2(left * right.x, left * right.y);
}
