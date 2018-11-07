#pragma once
#include <windows.h>

#include "Mesh.h"
#include "ShaderProgram.h"
#include "Texture.h"

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "Timer.h"
#include "Camera.h"
#include "Transform.h"
#include "Lerp.h"

#define WINDOW_WIDTH			800
#define WINDOW_HEIGHT			600
#define FRAMES_PER_SECOND		60

class Game
{
public:
	Game();
	~Game();

	void initializeGame();
	void update();
	void draw();

	/* input callback functions */
	void keyboardDown(unsigned char key, int mouseX, int mouseY);
	void keyboardUp(unsigned char key, int mouseX, int mouseY);
	void mouseClicked(int button, int state, int x, int y);
	void mouseMoved(int x, int y);

	/* Data Members */
	Timer *updateTimer	= nullptr;
	float TotalGameTime = 0.0f;

	Mesh Knight;
	Mesh Stage;

	ShaderProgram PassThrough;

	Texture GrassTexture;

	mat4 CameraTransform;
	mat4 CameraProjection;
	mat4 KnightTransform;
	mat4 StageTransform;

	/* Axes */
	float xMoveKnight = 0.0f;
	float yMoveKnight = 0.0f;

	/* Perspective Change */
	int current = 0;

private:
	unsigned int VBO1 = GL_NONE;
	unsigned int VBO2 = GL_NONE;
	unsigned int VAO = GL_NONE;

	unsigned int program = GL_NONE;
	unsigned int vertShader = GL_NONE;
	unsigned int fragShader = GL_NONE;

	Camera camera;
	Transform cube;
};
