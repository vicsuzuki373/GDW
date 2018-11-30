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
	bool DemonHurt = false;
	bool KnightHurt = false;

	//UI
	Mesh UIPaladinHelmet;
	Texture UIPaladinHelmetTex;
	mat4 UIPaladinHelmetTransform;

	Mesh UIPaladinBar;
	mat4 UIPaladinBarTransform;

	Mesh UIPaladinHealth;
	mat4 UIPaladinHealthTransform;

	Texture UIPaladinHealthBarTex;

	Mesh UIDemonSkull;
	Texture UIDemonSkullTex;
	mat4 UIDemonSkullTransform;

	Mesh UIDemonBar;
	mat4 UIDemonBarTransform;

	Mesh UIDemonHealth;
	mat4 UIDemonHealthTransform;

	Texture UIDemonHealthBarTex;

	ShaderProgram Shader;
	ShaderProgram AnimationShader;
	ShaderProgram UIShader;

	Mesh Paladin;
	Mesh Demon;
	Mesh SmallObjects;
	Mesh BigObjects;
	Mesh Fire;
	Mesh Tree;
	Mesh Building;
	Mesh Wall;
	Mesh Grass;
	Mesh Pew;
	Mesh Candle;
	Mesh Skull;
	Mesh Torch;
	Mesh Altar;
	Mesh Banner;
	Mesh BannerBar;
	Mesh Rubble;

	Texture RedTex;
	Texture PaladinTex;
	Texture DemonTex;
	Texture SmallObjTex;
	Texture BigObjTex;
	Texture FireTex;
	Texture TreeTex;
	Texture BuildingTex;
	Texture WallTex;
	Texture GrassTex;
	Texture PewTex;
	Texture CandleTex;
	Texture SkullTex;
	Texture TorchTex;
	Texture AltarTex;
	Texture BannerTex;
	Texture BannerBarTex;
	Texture RubbleTex;

	mat4 CameraTransform;
	mat4 CameraProjection;
	mat4 PaladinTransform;
	mat4 DemonTransform;
	mat4 SmallObjectsTransform;
	mat4 BigObjectsTransform;
	mat4 FireTransform;
	mat4 TreeTransform;
	mat4 BuildingTransform;
	mat4 WallTransform;
	mat4 GrassTransform;
	mat4 PewTransform;
	mat4 CandleTransform;
	mat4 SkullTransform;
	mat4 TorchTransform;
	mat4 AltarTransform;
	mat4 BannerTransform;
	mat4 BannerBarTransform;
	mat4 RubbleTransform;


	//Hitbox

	/* Movement */
	float MoveKnightX = 0.0f;
	float MoveKnightY= 0.0f;

	bool DemonAttack;
	int FireNumber = 0;
	float FireInterp = 0.0f;
	int DemonAttackNumber = 0;
	float DemonInterp = 0.0f;


	//Keys
	bool A = false;
	bool S = false;
	bool D = false;
	bool W = false;
	bool Space = false;
	bool isOnGround = true;

private:
	unsigned int VBO1 = GL_NONE;
	unsigned int VBO2 = GL_NONE;
	unsigned int VAO = GL_NONE;

	unsigned int program = GL_NONE;
	unsigned int vertShader = GL_NONE;
	unsigned int fragShader = GL_NONE;

	Camera camera;
};
