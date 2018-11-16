#include "Game.h"

#include <string>


Game::Game()
{
}

Game::~Game()
{
	delete updateTimer;

	PassThrough.UnLoad();
	Knight.Unload();
	GrassTexture.Unload();
	//...
}

void Game::initializeGame()
{
	updateTimer = new Timer();

	glEnable(GL_DEPTH_TEST);

	if (!PassThrough.Load("./Assets/Shaders/PassThrough.vert", "./Assets/Shaders/PassThrough.frag"))
	{
		std::cout << "Shaders failed to initialize.\n";
		system("pause");
		exit(0);
	}

	if (!Knight.LoadFromFile("./Assets/Models/Knight.obj"))
	{
		std::cout << "Model failed to load\n";
		system("pause");
		exit(0);
	}

	if (!Stage.LoadFromFile("./Assets/Models/Stage.obj"))
	{
		std::cout << "Model failed to load\n";
		system("pause");
		exit(0);
	}

	if (!GrassTexture.Load("./Assets/Textures/Grass.png"))
	{
		std::cout << "Texture failed to load\n";
		system("pause");
		exit(0);
	}

	CameraTransform.Translate(vec3(0.0f, 5.0f, 20.0f));
	CameraProjection = mat4::PerspectiveProjection(60.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 1.0f, 10000.0f);
	StageTransform.Translate(vec3(0.0f, 0.0f, -15.0f));
	KnightTransform.RotateY(45.0f);
	KnightTransform.Translate(vec3(-7.5f, 0.0f, 0.0f));
}

void Game::update()
{
	// update our clock so we have the delta time since the last update
	updateTimer->tick();

	float deltaTime = updateTimer->getElapsedTimeSeconds();
	TotalGameTime += deltaTime;

	//cube.setRotationAngleY(TotalGameTime * 15.0f);

	//camera.update(deltaTime);
	//cube.update(deltaTime);

	//KnightTransform.RotateY(deltaTime * 45.0f);
	KnightTransform.Translate(vec3(xMoveKnight, yMoveKnight, 0.0f));
	if (KnightTransform.GetTranslation().y > 0.33f) {
		yMoveKnight += -0.05f;
	}
	if (KnightTransform.GetTranslation().y < 0.0f) {
		yMoveKnight = 0.0f;
		KnightTransform.SetTranslation((vec3(KnightTransform.GetTranslation().x, 0.0f, 0.0f)));
	}
	// ...
}

void Game::draw()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	PassThrough.Bind();
	PassThrough.SendUniformMat4("uModel", StageTransform.data, true);
	PassThrough.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	PassThrough.SendUniformMat4("uProj", CameraProjection.data, true);

	//lighting
	PassThrough.SendUniform("uTex", 0);
	PassThrough.SendUniform("LightPosition", CameraTransform.GetInverse() * vec4(4.0f, 0.0f, 0.0f, 1.0f));
	PassThrough.SendUniform("LightAmbient", vec3(0.5f, 0.5f, 0.5f));
	PassThrough.SendUniform("LightDiffuse", vec3(0.7f, 0.7f, 0.7f));
	PassThrough.SendUniform("LightSpecular", vec3(0.7f, 0.7f, 0.7f));
	PassThrough.SendUniform("LightSpecularExponent", 50.0f);
	PassThrough.SendUniform("Attenuation_Constant", 1.0f);
	PassThrough.SendUniform("Attenuation_Linear", 0.1f);
	PassThrough.SendUniform("Attenuation_Quadratic", 0.01f);

	//bind grass texture (to only monestary bc we unbind it right after
	GrassTexture.Bind();

	glBindVertexArray(Stage.VAO);
	glDrawArrays(GL_TRIANGLES, 0, Stage.GetNumVertices());
	glBindVertexArray(0);

	GrassTexture.Unbind();
	PassThrough.unBind();

	PassThrough.Bind();
	PassThrough.SendUniformMat4("uModel", KnightTransform.data, true);
	PassThrough.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	PassThrough.SendUniformMat4("uProj", CameraProjection.data, true);



	glBindVertexArray(Knight.VAO);
	glDrawArrays(GL_TRIANGLES, 0, Knight.GetNumVertices());
	glBindVertexArray(0);

	PassThrough.unBind();

	glutSwapBuffers();
}

void Game::keyboardDown(unsigned char key, int mouseX, int mouseY)
{
	if (key == 27) // Escape
		exit(1);
	if (key == 'a' || key == 'A') { // A
		xMoveKnight += -0.1f;
		if (xMoveKnight < -0.5f) {
			xMoveKnight = -0.5f;
		}
		if (KnightTransform.GetTranslation().x < -15.5) {
			xMoveKnight = 0.0f;
		}
	}
	if (key == 'd' || key == 'D') // D
		xMoveKnight += 0.1f;
	if (xMoveKnight > 0.5f) {
		xMoveKnight = 0.5f;
	}
	if (KnightTransform.GetTranslation().x >= 12.5) {
		xMoveKnight = -0.01f;
	}
	if (key == 'w' || key == 'W') {
		if (KnightTransform.GetTranslation().y <= 0.5)// D
			yMoveKnight += 0.8f;
	}
	if (key == 'd' && key == 'w') {
		if (KnightTransform.GetTranslation().y <= 0.5)// D
			yMoveKnight += 0.8f;
		xMoveKnight += 0.1f;
	}

}

void Game::keyboardUp(unsigned char key, int mouseX, int mouseY)
{
		//case 32: // the space bar
		//	break;
		//case 27: // the escape key
		//case 'q': // the 'q' key
		//	exit(1);
		//	break;

	// Switches camera perspective when spacebar is pressed
	// Orhtographic is currently broken
		//if (key == 'v')
		//{
		//	if (current == 0)
		//	{
		//		CameraProjection = mat4::OrthographicProjection(-3.0f, 3.0f, 3.0f, -3.0f, 1.0f, 10000.0f);
		//		current = 1;
		//	}
		//	else if (current == 1)
		//	{
		//		CameraProjection = mat4::PerspectiveProjection(60.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 1.0f, 10000.0f);
		//		current = 0;
		//	}
		//}

	// Resets movement
	xMoveKnight = 0.0f;
	yMoveKnight += -0.05f;
}

void Game::mouseClicked(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN) 
	{
		switch(button)
		{
		case GLUT_LEFT_BUTTON:

			break;
		case GLUT_RIGHT_BUTTON:
		
			break;
		case GLUT_MIDDLE_BUTTON:

			break;
		}
	}
	else
	{

	}
}

/*
 * mouseMoved(x,y)
 * - this occurs only when the mouse is pressed down
 *   and the mouse has moved.  you are given the x,y locations
 *   in window coordinates (from the top left corner) and thus 
 *   must be converted to screen coordinates using the screen to window pixels ratio
 *   and the y must be flipped to make the bottom left corner the origin.
 */
void Game::mouseMoved(int x, int y)
{
}
