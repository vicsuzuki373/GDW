#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
	delete updateTimer;

	PassThrough.UnLoad();
	Monestary.Unload();
	GrassTexture.Unload();
}

void Game::initializeGame()
{
	updateTimer = new Timer();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	if (!PassThrough.Load("./Assets/Shaders/PassThrough.vert", "./Assets/Shaders/PassThrough.frag"))
	{
		std::cout << "Shaders failed to initialize\n";
		system("pause");
		exit(0);
	}

	if (!Monestary.LoadFromFile("./Assets/Models/monestary.obj"))
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

	CameraTransform.Translate(vec3(20.0f, 10.0f, -5.0f));
	CameraProjection = mat4::PerspectiveProjection(60.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 1.0f, 10000.0f);

	//...
}

void Game::update()
{
	// update our clock so we have the delta time since the last update
	updateTimer->tick();

	float deltaTime = updateTimer->getElapsedTimeSeconds();
	TotalGameTime += deltaTime;

	//MonestaryTransform.RotateY(deltaTime * 45.0f);
	if (Wpressed == true){
		MonestaryTransform.Translate(vec3(0.0f, 0.1f, 0.0f));
	}
	if (Apressed == true) {
		MonestaryTransform.Translate(vec3(-0.1f, 0.0f, 0.0f));
	}
	if (Spressed == true) {
		MonestaryTransform.Translate(vec3(0.0f, -0.1f, 0.0f));
	}
	if (Dpressed == true) {
		MonestaryTransform.Translate(vec3(0.1f, 0.0f, 0.0f));
	}
	if (Epressed == true) {
		for (int i=0; i<=360; i++)
		MonestaryTransform.RotateY(1.0f);
		}
	if (Rpressed == true) {
		for (int i = 0; i <= 360; i++)
			MonestaryTransform.RotateY(-1.0f);
	}
}

void Game::draw()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	PassThrough.Bind();
	PassThrough.SendUniformMat4("uModel", MonestaryTransform.data, true);
	PassThrough.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	PassThrough.SendUniformMat4("uProj", CameraProjection.data, true);
	PassThrough.SendUniform("uTex", 0);
	PassThrough.SendUniform("LightPosition", CameraTransform.GetInverse() * vec4(4.0f, 0.0f, 0.0f, 1.0f));
	PassThrough.SendUniform("LightAmbient", vec3(0.15f, 0.15f, 0.15f));
	PassThrough.SendUniform("LightDiffuse", vec3(0.7f, 0.1f, 0.2f));
	PassThrough.SendUniform("LightSpecular", vec3(0.8f, 0.1f, 0.1f));
	PassThrough.SendUniform("LightSpecularExponent", 50.0f);
	PassThrough.SendUniform("Attenuation_Constant", 1.0f);
	PassThrough.SendUniform("Attenuation_Linear", 0.1f);
	PassThrough.SendUniform("Attenuation_Quadratic", 0.01f);

	GrassTexture.Bind();

	glBindVertexArray(Monestary.VAO);
	glDrawArrays(GL_TRIANGLES, 0, Monestary.GetNumVertices());
	glBindVertexArray(0);

	GrassTexture.Unbind();

	PassThrough.UnBind();

	glutSwapBuffers();
}

void Game::keyboardDown(unsigned char key, int mouseX, int mouseY)
{
	switch(key)
	{
	case 27: // the escape key
	case 'w':
		Wpressed = true;
		break;
	case 'a':
		Apressed = true;
		break;
	case 's':
		Spressed = true;
		break;
	case 'd':
		Dpressed = true;
		break;
	case 'e':
		Epressed = true;
		break;
	case 'r':
		Rpressed = true;
		break;
	case 'q': // the 'q' key
		exit(1);
		break;
	}
}

void Game::keyboardUp(unsigned char key, int mouseX, int mouseY)
{
	switch(key)
	{
	case 32: // the space bar
		break;
	case 'w':
		Wpressed = false;
		break;
	case 'a':
		Apressed = false;
		break;
	case 's':
		Spressed = false;
		break;
	case 'd':
		Dpressed = false;
		break;
	case 'e':
		Epressed = false;
		break;
		case 'r':
		Rpressed = false;
		break;
	case 27: // the escape key
	case 'q': // the 'q' key
		exit(1);
		break;
	}
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
