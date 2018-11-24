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
	Stage.Unload();
	Demon.Unload();
	Grey.Unload();
	Blue.Unload();
	Red.Unload();
	//...
}

void Game::initializeGame()
{
	updateTimer = new Timer();

	glEnable(GL_DEPTH_TEST);

	//Shaders
	if (!PassThrough.Load("./Assets/Shaders/PassThrough.vert", "./Assets/Shaders/PassThrough.frag"))
	{
		std::cout << "Shaders failed to initialize.\n";
		system("pause");
		exit(0);
	}

	//Objects
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
	if (!Demon.LoadFromFile("./Assets/Models/Demon.obj"))
	{
		std::cout << "Model failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Hitbox.LoadFromFile("./Assets/Models/hitbox.obj"))
	{
		std::cout << "Model failed to load\n";
		system("pause");
		exit(0);
	}

	//Textures
	if (!Grey.Load("./Assets/Textures/Gray.png"))
	{
		std::cout << "Texture failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Blue.Load("./Assets/Textures/Blue.png"))
	{
		std::cout << "Texture failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Red.Load("./Assets/Textures/Red.png"))
	{
		std::cout << "Texture failed to load\n";
		system("pause");
		exit(0);
	}

	CameraTransform.Translate(vec3(0.0f, 5.0f, 20.0f));
	CameraProjection = mat4::PerspectiveProjection(60.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 1.0f, 10000.0f);

	StageTransform.Translate(vec3(0.0f, 0.0f, -15.0f));

	KnightTransform.RotateY(80.0f);
	KnightTransform.Translate(vec3(-7.5f, 0.0f, 0.0f));

	DemonTransform.RotateY(-80.0f);
	DemonTransform.Translate(vec3(10.0f, 0.0f, 0.0f));

	HitBoxTransform.Translate(vec3(-999.9f, -999.9f, 0));
}

void Game::update()
{
	// update our clock so we have the delta time since the last update
	updateTimer->tick();

	float deltaTime = updateTimer->getElapsedTimeSeconds();
	TotalGameTime += deltaTime;

	//Gravity
	MoveKnightY -= 0.05f;
	if (KnightTransform.GetTranslation().y < 0.0f)
	{
			MoveKnightY = 0.0f;
	}

	//Move Left
	if (A && MoveKnightX > -0.3f)
		MoveKnightX -= 0.01f;
	else if (A == false && MoveKnightX < 0) //Slow down
	{
		MoveKnightX += 0.02f;
		if (MoveKnightX > 0) //Prevents movement after releasing the key
			MoveKnightX = 0;
	}

	//Move Right
	if (D && MoveKnightX < 0.3f)
		MoveKnightX += 0.01f;
	else if (D == false && MoveKnightX > 0) //Slow down
	{
		MoveKnightX -= 0.02f;
		if (MoveKnightX < 0) //Prevents movement after releasing the key
			MoveKnightX = 0;
	}

	if (L == true) {
		HitBoxTransform.SetTranslation(vec3(KnightTransform.GetTranslation().x + 2.0f, KnightTransform.GetTranslation().y + 2.0f, 0.0f));
	}
	else if (L == false) {
		HitBoxTransform.SetTranslation(vec3(-999.9f, -999.9f, 0.0f));

	}

	//Jump
	if (Space && MoveKnightY == 0.0f)
		MoveKnightY = 0.6f;



	KnightTransform.Translate(vec3(MoveKnightX, MoveKnightY, 0.0f));
	HitBoxTransform.Translate(vec3(MoveKnightX, MoveKnightY, 0.0f));
}

void Game::draw()
{
	glClearColor(0.2f, 0, 0, 0);
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


	Grey.Bind();
	glBindVertexArray(Stage.VAO);
	glDrawArrays(GL_TRIANGLES, 0, Stage.GetNumVertices());
	glBindVertexArray(0);
	Grey.Unbind();


	PassThrough.SendUniformMat4("uModel", KnightTransform.data, true);
	Blue.Bind();
	glBindVertexArray(Knight.VAO);
	glDrawArrays(GL_TRIANGLES, 0, Knight.GetNumVertices());
	glBindVertexArray(0);
	Blue.Unbind();


	PassThrough.SendUniformMat4("uModel", DemonTransform.data, true);
	Red.Bind();
	glBindVertexArray(Demon.VAO);
	glDrawArrays(GL_TRIANGLES, 0, Demon.GetNumVertices());
	glBindVertexArray(0);
	Red.Unbind();

	PassThrough.SendUniformMat4("uModel", HitBoxTransform.data, true);
	Red.Bind();
	glBindVertexArray(Hitbox.VAO);
	glDrawArrays(GL_TRIANGLES, 0, Demon.GetNumVertices());
	glBindVertexArray(0);
	Red.Unbind();

	PassThrough.unBind();

	glutSwapBuffers();
}

void Game::keyboardDown(unsigned char key, int mouseX, int mouseY)
{
	if (key == 27)
		exit(1);

	if (key == 'a' || key == 'A') //A
		A = true;

	if (key == 'd' || key == 'D') //D
		D = true;

	if (key == 'w' || key == 'W') //W
		W = true;

	if (key == 's' || key == 'S') //S
		S = true;

	if (key == ' ') //Space bar
		Space = true;
	if (key == 'l' || key == 'L')
		L = true;

}

void Game::keyboardUp(unsigned char key, int mouseX, int mouseY)
{
	if (key == 'a' || key == 'A') //A
		A = false;

	if (key == 'd' || key == 'D') //D
		D = false;

	if (key == 'w' || key == 'W') //W
		W = false;

	if (key == 's' || key == 'S') //S
		S = false;

	if (key == ' ') //Space bar
		Space = false;
	if (key == 'l' || key == 'L')
		L = false;
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
