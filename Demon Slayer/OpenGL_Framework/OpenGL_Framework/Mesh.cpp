#define _CRT_SECURE_NO_WARNINGS

#include "Mesh.h"
#include <fstream>
#include <iostream>
#include <MiniMath\Core.h>

#define CHAR_BUFFER_SIZE 128
#define BUFFER_OFFSET(i)((char *)0+(i))

struct MeshFace
{
	MeshFace()
	{
		vertices[0] = 0;
		vertices[1] = 0;
		vertices[2] = 0;

		textureUVs[0] = 0;
		textureUVs[1] = 0;
		textureUVs[2] = 0;

		normals[0] = 0;
		normals[1] = 0;
		normals[2] = 0;
	}

	MeshFace(unsigned v1, unsigned v2, unsigned v3,
		unsigned t1, unsigned t2, unsigned t3,
		unsigned n1, unsigned n2, unsigned n3)
	{
		vertices[0] = v1;
		vertices[1] = v2;
		vertices[2] = v3;

		textureUVs[0] = t1;
		textureUVs[1] = t2;
		textureUVs[2] = t3;

		normals[0] = n1;
		normals[1] = n2;
		normals[2] = n3;
	}

	unsigned vertices[3];
	unsigned textureUVs[3];
	unsigned normals[3];
};

Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}

// Load a mesh, and send it to OpenGL
bool Mesh::LoadFromFile(const std::string &file)
{
	if (Frame == 0) {
		VBO_Vertices = new GLuint[MaxFrames];
		VBO_UVs = new GLuint[MaxFrames];
		VBO_Normals = new GLuint[MaxFrames];

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);
	}

	glGenBuffers(1, &VBO_Vertices[Frame]);
	glGenBuffers(1, &VBO_UVs[Frame]);
	glGenBuffers(1, &VBO_Normals[Frame]);


	std::ifstream input;
	input.open(file);

	if (!input)
	{
		std::cout << "Could not open the file." << std::endl;
		return false;
	}

	char inputString[CHAR_BUFFER_SIZE];
	
	// Unique data
	std::vector<vec3>vertexData;
	std::vector<vec2>textureData;
	std::vector<vec3>normalData;

	// Index/Face data
	std::vector<MeshFace>faceData;

	// OpenGL ready data
	std::vector<float>unPackedVertexData;
	std::vector<float>unPackedTextureData;
	std::vector<float>unPackedNormalData;

	while (!input.eof())
	{
		input.getline(inputString, CHAR_BUFFER_SIZE);

		if (std::strstr(inputString, "#") != nullptr)
		{
			// This line is a comment
			continue;
		}
		else if (std::strstr(inputString, "vn") != nullptr)
		{
			// This line has Normal data
			vec3 temp;

			std::sscanf(inputString, "vn %f %f %f", &temp.x, &temp.y, &temp.z);
			normalData.push_back(temp);
		}
		else if (std::strstr(inputString, "vt") != nullptr)
		{
			// This line has UV data
			vec2 temp;

			std::sscanf(inputString, "vt %f %f", &temp.x, &temp.y);
			textureData.push_back(temp);
		}
		else if (std::strstr(inputString, "v") != nullptr)
		{
			// This line has Vertex data
			vec3 temp;

			std::sscanf(inputString, "v %f %f %f", &temp.x, &temp.y, &temp.z);
			vertexData.push_back(temp);
		}
		else  if (inputString[0] == 'f')
		{
			// This line has Face data
			MeshFace temp;

			std::sscanf(inputString, "f %u/%u/%u %u/%u/%u %u/%u/%u",
				&temp.vertices[0], &temp.textureUVs[0], &temp.normals[0],
				&temp.vertices[1], &temp.textureUVs[1], &temp.normals[1],
				&temp.vertices[2], &temp.textureUVs[2], &temp.normals[2]);

			faceData.push_back(temp);
		}
	}
	input.close();

	// Unpack the data
	for (unsigned i = 0; i < faceData.size();i++)
	{
		for (unsigned j = 0; j < 3 ; j++)
		{
			unPackedVertexData.push_back(vertexData[faceData[i].vertices[j] - 1].x);
			unPackedVertexData.push_back(vertexData[faceData[i].vertices[j] - 1].y);
			unPackedVertexData.push_back(vertexData[faceData[i].vertices[j] - 1].z);
	
			unPackedTextureData.push_back(textureData[faceData[i].textureUVs[j] - 1].x);
			unPackedTextureData.push_back(textureData[faceData[i].textureUVs[j] - 1].y);

			unPackedNormalData.push_back(normalData[faceData[i].normals[j] - 1].x);
			unPackedNormalData.push_back(normalData[faceData[i].normals[j] - 1].y);
			unPackedNormalData.push_back(normalData[faceData[i].normals[j] - 1].z);
		}
	}

	_NumFaces = faceData.size();
	_NumVertices = _NumFaces * 3;

	// Send data to OpenGL
	unsigned int indexOffset = Frame * 3;

	glEnableVertexAttribArray(0 + indexOffset); // Vertex
	glEnableVertexAttribArray(1 + indexOffset); // UVs
	glEnableVertexAttribArray(2 + indexOffset); // Normals

	glBindBuffer(GL_ARRAY_BUFFER, VBO_Vertices[Frame]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * unPackedVertexData.size(), &unPackedVertexData[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0 + indexOffset, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, VBO_UVs[Frame]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * unPackedTextureData.size(), &unPackedTextureData[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)1 + indexOffset, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, BUFFER_OFFSET(0));

	glBindBuffer(GL_ARRAY_BUFFER, VBO_Normals[Frame]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * unPackedNormalData.size(), &unPackedNormalData[0], GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)2 + indexOffset, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, BUFFER_OFFSET(0));

	// Cleanup

	Frame++;
	if (Frame == MaxFrames) {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	vertexData.clear();
	textureData.clear();
	normalData.clear();
	faceData.clear();
	unPackedVertexData.clear();
	unPackedTextureData.clear();
	unPackedNormalData.clear();

	return true;
}

// Release data from OpenGL (VRAM)
void Mesh::Unload()
{
	for (unsigned int i = 0; i < MaxFrames; ++i)
	{
		glDeleteBuffers(1, &VBO_Normals[i]);
		glDeleteBuffers(1, &VBO_UVs[i]);
		glDeleteBuffers(1, &VBO_Vertices[i]);
	}
	glDeleteVertexArrays(1, &VAO);

	VBO_Normals = nullptr;
	VBO_UVs = nullptr;
	VBO_Vertices = nullptr;
	VAO = 0;
	Frame = 0;

	_NumFaces = 0;
	_NumVertices = 0;
}

unsigned int Mesh::GetNumFaces() const
{
	return _NumFaces;
}

unsigned int Mesh::GetNumVertices() const
{
	return _NumVertices;
}

void Mesh::bind() const
{
	glBindVertexArray(VAO);
}

void Mesh::unbind()
{
	glBindVertexArray(0);
}

void Mesh::draw() const
{
	glDrawArrays(GL_TRIANGLES, 0, _NumVertices);
}