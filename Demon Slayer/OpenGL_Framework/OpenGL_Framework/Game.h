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

#define WINDOW_WIDTH			1600
#define WINDOW_HEIGHT			900
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
	Mesh Demon;
	Mesh Hitbox;
	Mesh Rubble;
	bool isColliding = false;
	bool KnightHurt = false;

	Mesh AnimTest;

	ShaderProgram PassThrough;
	ShaderProgram Animation;

	Texture Grey;
	Texture Blue;
	Texture Red;

	mat4 CameraTransform;
	mat4 CameraProjection;
	mat4 KnightTransform;
	mat4 DemonTransform;
	mat4 StageTransform;
	mat4 HitBoxTransform;
	mat4 AnimTestTransform;


	//Hitbox

	/* Movement */
	float MoveKnightX = 0.0f;
	float MoveKnightY= 0.0f;


	
	int index = 0;
	float interp = 0.0f;


	//Keys
	bool A = false;
	bool S = false;
	bool D = false;
	bool W = false;
	bool L = false;
	bool Space = false;
	bool isOnGround;

private:
	unsigned int VBO1 = GL_NONE;
	unsigned int VBO2 = GL_NONE;
	unsigned int VAO = GL_NONE;

	unsigned int program = GL_NONE;
	unsigned int vertShader = GL_NONE;
	unsigned int fragShader = GL_NONE;

	Camera camera;
};
