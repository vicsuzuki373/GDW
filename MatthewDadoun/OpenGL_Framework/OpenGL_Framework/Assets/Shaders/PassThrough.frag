#version 420

out vec4 outColor;

in vec3 normal;

void main()
{
	outColor = vec4(normal, 1.0f);
}