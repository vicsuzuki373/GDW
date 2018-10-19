#pragma once
#include <string>
#include <vector>
#include<GL\glew.h>

class Mesh
{
public:
	Mesh();
	~Mesh();

	//Load mesh and send to OpenGL
	bool LoadFromFile(const std::string &file);
	//Release data form OpenGL
	void Unload();

	unsigned int GetNumFaces() const;
	unsigned int GetNumVertices() const;

	//OpenGL buffers and objects
	GLuint VBO_Vertices = 0;
	GLuint VBO_UVs = 0;
	GLuint VBO_Normals = 0;
	GLuint VAO = 0;

private:
	unsigned int _NumFaces = 0;
	unsigned int _NumVertices = 0;
};