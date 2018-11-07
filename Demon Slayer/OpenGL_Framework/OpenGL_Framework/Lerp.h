#pragma once
#include <MiniMath\Core.h>

float lerp(float start, float end, float t) {
	return (1 - t)*start + t * end;
}

vec2 lerp(vec2 start, vec2 end, float t) {
	vec2 temp;
	temp.x = (1 - t)*start.x + t * end.x;
	temp.y = (1 - t)*start.y + t * end.y;
	return temp;
}

vec3 lerp(vec3 start, vec3 end, float t) {
	vec3 temp;
	temp.x = (1 - t)*start.x + t * end.x;
	temp.y = (1 - t)*start.y + t * end.y;
	temp.z = (1 - t)*start.z + t * end.z;
	return temp;
}

vec4 lerp(vec4 start, vec4 end, float t) {
	vec4 temp;
	temp.x = (1 - t)*start.x + t * end.x;
	temp.y = (1 - t)*start.y + t * end.y;
	temp.z = (1 - t)*start.z + t * end.z;
	temp.w = (1 - t)*start.z + t * end.z;
	return temp;
}