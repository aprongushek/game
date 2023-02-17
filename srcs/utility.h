#ifndef UTILITY_H
#define UTILITY_H

#include <string>

extern const int TILE_SIZE;

#define uint unsigned int

int toInt (const std::string &str);
std::string toStr (int i);

class vec2 {
public:
	float x;
	float y;

	vec2 ();
	vec2 (float ax, float ay);

	float &operator[] (uint index);

	vec2 operator- ();
	vec2 &operator= (const vec2 &right);
	vec2 &operator+= (const vec2 &right);
	vec2 &operator-= (const vec2 &right);
	vec2 &operator/= (const float &right);
	vec2 &operator*= (const float &right);

	friend vec2 operator+ (const vec2 &left, const vec2 &right);
	friend vec2 operator- (const vec2 &left, const vec2 &right);
	friend vec2 operator/ (const vec2 &left, const float &right);
	friend vec2 operator/ (const float &left, const vec2 &right);
	friend vec2 operator* (const vec2 &left, const float &right);
	friend vec2 operator* (const float &left, const vec2 &right);

};

vec2 operator+ (const vec2 &left, const vec2 &right);
vec2 operator- (const vec2 &left, const vec2 &right);
vec2 operator/ (const vec2 &left, const float &right);
vec2 operator* (const vec2 &left, const float &right);
vec2 operator* (const float &left, const vec2 &right);

#endif