#pragma once
#include <GL\glew.h>
#include <string>

class Texture
{
public:
	Texture() = default;
	~Texture();

	bool Load(const std::string &file);
	void Unload();

	void Bind();
	void Unbind();

	// Handle to the texture object
	GLuint TexObj = 0;
};