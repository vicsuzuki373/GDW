#include "Vector.h"

vec2 vec2::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}

vec2 vec2::operator/=(float divisor)
{
	x /= divisor;
	y /= divisor;
	return *this;
}

vec2 vec2::operator*=(vec2 a)
{
	x *= a.x;
	y *= a.y;
	return *this;
}

vec2 vec2::operator/=(vec2 a)
{
	x /= a.x;
	y /= a.y;
	return *this;
}

vec2 vec2::operator-=(vec2 a)
{
	x -= a.x;
	y -= a.y;
	return *this;
}

vec2 vec2::operator+=(vec2 a)
{
	x += a.x;
	y += a.y;
	return *this;
}

bool vec2::operator==(vec2 a) const
{
	if (x == a.x && y == a.y)
		return true;
	else
		return false;
}

bool vec2::operator!=(vec2 a) const
{
	if (x != a.x || y != a.y)
		return true;
	else
		return false;
}

vec2 vec2::operator*(float scalar) const
{
	return vec2(x * scalar, y * scalar);
}

vec2 vec2::operator/(float divisor) const
{
	return vec2(x / divisor, y / divisor);
}

vec2 vec2::operator*(vec2 a) const
{
	return vec2(x * a.x, y * a.y);
}

vec2 vec2::operator/(vec2 a) const
{
	return vec2(x / a.x, y / a.y);
}

vec2 vec2::operator+(vec2 a) const
{
	return vec2(x + a.x, y + a.y);
}

vec2 vec2::operator-(vec2 a) const
{
	return vec2(x - a.x, y - a.y);
}












vec3 vec3::operator*(float scalar) const
{
	return vec3(x * scalar, y * scalar, z * scalar);
}

vec3 vec3::operator/(float divisor) const
{
	return vec3(x / divisor, y / divisor, z / divisor);
}

vec3 vec3::operator*(vec3 a) const
{
	return vec3(x * a.x, y * a.y, z * a.z);
}

vec3 vec3::operator/(vec3 a) const
{
	return vec3(x / a.x, y / a.y, z / a.z);
}

vec3 vec3::operator+(vec3 a) const
{
	return vec3(x + a.x, y + a.y, z + a.z);
}

vec3 vec3::operator-(vec3 a) const
{
	return vec3(x - a.x, y - a.y, z - a.z);
}

vec3 vec3::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	x *= scalar;
	return *this;
}

vec3 vec3::operator/=(float divisor)
{
	x /= divisor;
	y /= divisor;
	x /= divisor;
	return *this;
}

vec3 vec3::operator*=(vec3 a)
{
	x *= a.x;
	y *= a.y;
	x *= a.z;
	return *this;
}

vec3 vec3::operator/=(vec3 a)
{
	x /= a.x;
	y /= a.y;
	x /= a.z;
	return *this;
}

vec3 vec3::operator-=(vec3 a)
{
	x -= a.x;
	y -= a.y;
	x -= a.z;
	return *this;
}

vec3 vec3::operator+=(vec3 a)
{
	x += a.x;
	y += a.y;
	x += a.z;
	return *this;
}

bool vec3::operator==(vec3 a) const
{
	if (x == a.x && y == a.y && z == a.z)
		return true;
	else
		return false;
}

bool vec3::operator!=(vec3 a) const
{
	if (x != a.x || y != a.y || z != a.z)
		return true;
	else
		return false;
}












vec4 vec4::operator*(float scalar) const
{
	return vec4(x * scalar, y * scalar, z * scalar, w * scalar);
}

vec4 vec4::operator/(float divisor) const
{
	return vec4(x / divisor, y / divisor, z / divisor, w / divisor);
}

vec4 vec4::operator*(vec4 a) const
{
	return vec4(x * a.x, y * a.y, z * a.z, w * a.w);
}

vec4 vec4::operator/(vec4 a) const
{
	return vec4(x / a.x, y / a.y, z / a.z, w / a.w);
}

vec4 vec4::operator+(vec4 a) const
{
	return vec4(x + a.x, y + a.y, z + a.z, w + a.w);
}

vec4 vec4::operator-(vec4 a) const
{
	return vec4(x - a.x, y - a.y, z - a.z, w - a.w);
}

vec4 vec4::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}

vec4 vec4::operator/=(float divisor)
{
	x /= divisor;
	y /= divisor;
	z /= divisor;
	w /= divisor;
	return *this;
}

vec4 vec4::operator*=(vec4 a)
{
	x *= a.x;
	y *= a.y;
	z *= a.z;
	w *= a.w;
	return *this;
}

vec4 vec4::operator/=(vec4 a)
{
	x /= a.x;
	y /= a.y;
	z /= a.z;
	w /= a.w;
	return *this;
}

vec4 vec4::operator-=(vec4 a)
{
	x -= a.x;
	y -= a.y;
	z -= a.z;
	w -= a.w;
	return *this;
}

vec4 vec4::operator+=(vec4 a)
{
	x += a.x;
	y += a.y;
	z += a.z;
	w += a.w;
	return *this;
}

bool vec4::operator==(vec4 a) const
{
	if (x == a.x && y == a.y && z == a.z && w == a.w)
		return true;
	else
		return false;
}

bool vec4::operator!=(vec4 a) const
{
	if (x != a.x || y != a.y || z != a.z || w != a.w)
		return true;
	else
		return false;
}