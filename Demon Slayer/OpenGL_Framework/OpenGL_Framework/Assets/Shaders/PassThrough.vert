#version 420

uniform mat4 uModel;
uniform mat4 uView;
uniform mat4 uProj;

layout(location = 0) in vec3 in_vert;
layout(location = 1) in vec2 in_uv;
layout(location = 2) in vec3 in_normal;

out vec2 texcoord;
out vec3 norm;
out vec3 pos;

void main()
{
	texcoord = vec2(in_uv.x, in_uv.y * -1);
	norm = mat3(uView) * mat3(uModel) * in_normal;

	vec4 viewSpace = uView * uModel * vec4(in_vert, 1.0f);

	gl_Position = uProj * viewSpace;

	pos = viewSpace.xyz;
}