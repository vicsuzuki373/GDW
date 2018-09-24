#define _CRT_SECURE_NO_WARNINGS

#include "Mesh.h"
#include <fstream>
#include <iostream>
#include <MiniMath\Core.h>


#define CHAR_BUFFER_SIZE 128
#define BUFFER_OFFSET(i) ((char*)0 + (i))

Mesh::Mesh() {

}

Mesh::~Mesh() {

}

//Load mesh and send to OpenGL
bool Mesh::LoadFromFile(const std::string &file) {
	
	std::ifstream input;
	input.open(file);

	if (!input) {
		std::cout << "Could not open the file" << std::endl;
		return false;
	}

	char inputString[CHAR_BUFFER_SIZE];
}
//Release data form OpenGL
void Mesh::Unload() {

}

unsigned int Mesh::GetNumFaces() const {
}
unsigned int Mesh::GetNumVertices() const {
}