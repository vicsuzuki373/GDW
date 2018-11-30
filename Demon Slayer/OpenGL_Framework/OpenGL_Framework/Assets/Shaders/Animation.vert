#version 420

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProj;

layout(location = 0) in vec3 in_vert;
layout(location = 1) in vec2 in_uv;
layout(location = 2) in vec3 in_normal;

layout(location = 3) in vec3 in_vert2;
layout(location = 4) in vec2 in_uv2;
layout(location = 5) in vec3 in_normal2;

layout(location = 6) in vec3 in_vert3;
layout(location = 7) in vec2 in_uv3;
layout(location = 8) in vec3 in_normal3;

layout(location = 9) in vec3 in_vert4;
layout(location = 10) in vec2 in_uv4;
layout(location = 11) in vec3 in_normal4;

layout(location = 12) in vec3 in_vert5;
layout(location = 13) in vec2 in_uv5;
layout(location = 14) in vec3 in_normal5;

layout(location = 15) in vec3 in_vert6;
layout(location = 16) in vec2 in_uv6;
layout(location = 17) in vec3 in_normal6;

uniform float T = 0.0f;
uniform int index = 0;

out vec2 texcoord;
out vec3 norm;
out vec3 pos;

void main()
{
	texcoord = vec2(in_uv.x, in_uv.y * -1);
	norm = mat3(uView) * mat3(uModel) * in_normal;

	vec3 newPos;

	if (index == 0)
		newPos = mix(in_vert, in_vert2, T);
	if (index == 1)
		newPos = mix(in_vert2, in_vert3, T);
	if (index == 2)
		newPos = mix(in_vert3, in_vert4, T);
	if (index == 3)
		newPos = mix(in_vert4, in_vert5, T);
	if (index == 4)
		newPos = mix(in_vert5, in_vert6, T);
	if (index == 5)
		newPos = mix(in_vert6, in_vert, T);
		

	vec4 viewSpace = uView * uModel * vec4(newPos, 1.0f);
	gl_Position = uProj * viewSpace;

	pos = viewSpace.xyz;
}