#include "Game.h"

#include <string>

const float mesh[] = {
	// Vertices start here:
	-1.0f, 	-1.0f, 	-1.0f, 	 // triangle 1, Vertex 1
	-1.0f, 	-1.0f, 	 1.0f, 	 // triangle 1, Vertex 2
	-1.0f, 	 1.0f, 	 1.0f, 	 // triangle 1, Vertex 3
	1.0f, 	 1.0f, 	-1.0f, 	 // triangle 2, Vertex 1
	-1.0f, 	-1.0f, 	-1.0f, 	 // triangle 2, Vertex 2
	-1.0f, 	 1.0f, 	-1.0f, 	 // triangle 2, Vertex 3
	1.0f, 	-1.0f, 	 1.0f,
	-1.0f, 	-1.0f, 	-1.0f,
	1.0f, 	-1.0f, 	-1.0f,
	1.0f, 	 1.0f, 	-1.0f,
	1.0f, 	-1.0f, 	-1.0f,
	-1.0f, 	-1.0f, 	-1.0f,
	-1.0f, 	-1.0f, 	-1.0f,
	-1.0f, 	 1.0f, 	 1.0f,
	-1.0f, 	 1.0f, 	-1.0f,
	1.0f, 	-1.0f, 	 1.0f,
	-1.0f, 	-1.0f, 	 1.0f,
	-1.0f, 	-1.0f, 	-1.0f,
	-1.0f, 	 1.0f, 	 1.0f,
	-1.0f, 	-1.0f, 	 1.0f,
	1.0f, 	-1.0f, 	 1.0f,
	1.0f, 	 1.0f, 	 1.0f,
	1.0f, 	-1.0f, 	-1.0f,
	1.0f, 	 1.0f, 	-1.0f,
	1.0f, 	-1.0f, 	-1.0f,
	1.0f, 	 1.0f, 	 1.0f,
	1.0f, 	-1.0f, 	 1.0f,
	1.0f, 	 1.0f, 	 1.0f,
	1.0f, 	 1.0f, 	-1.0f,
	-1.0f, 	 1.0f, 	-1.0f,
	1.0f, 	 1.0f, 	 1.0f,
	-1.0f, 	 1.0f, 	-1.0f,
	-1.0f, 	 1.0f, 	 1.0f,
	1.0f, 	 1.0f, 	 1.0f,
	-1.0f, 	 1.0f, 	 1.0f,
	1.0f, 	-1.0f, 	 1.0f,
	// Colors start here:
	0.583f,  0.771f,  0.014f,
	0.609f,  0.115f,  0.436f,
	0.327f,  0.483f,  0.844f,
	0.822f,  0.569f,  0.201f,
	0.435f,  0.602f,  0.223f,
	0.310f,  0.747f,  0.185f,
	0.597f,  0.770f,  0.761f,
	0.559f,  0.436f,  0.730f,
	0.359f,  0.583f,  0.152f,
	0.483f,  0.596f,  0.789f,
	0.559f,  0.861f,  0.639f,
	0.195f,  0.548f,  0.859f,
	0.014f,  0.184f,  0.576f,
	0.771f,  0.328f,  0.970f,
	0.406f,  0.615f,  0.116f,
	0.676f,  0.977f,  0.133f,
	0.971f,  0.572f,  0.833f,
	0.140f,  0.616f,  0.489f,
	0.997f,  0.513f,  0.064f,
	0.945f,  0.719f,  0.592f,
	0.543f,  0.021f,  0.978f,
	0.279f,  0.317f,  0.505f,
	0.167f,  0.620f,  0.077f,
	0.347f,  0.857f,  0.137f,
	0.055f,  0.953f,  0.042f,
	0.714f,  0.505f,  0.345f,
	0.783f,  0.290f,  0.734f,
	0.722f,  0.645f,  0.174f,
	0.302f,  0.455f,  0.848f,
	0.225f,  0.587f,  0.040f,
	0.517f,  0.713f,  0.338f,
	0.053f,  0.959f,  0.120f,
	0.393f,  0.621f,  0.362f,
	0.673f,  0.211f,  0.457f,
	0.820f,  0.883f,  0.371f,
	0.982f,  0.099f,  0.879f
};

const char* vertexShaderSource = 
	"#version 330\n"
	"layout(location = 0) in vec3 mesh_position;\n"
	"layout(location = 1) in vec3 mesh_color;\n"
	"uniform mat4 u_mvp;\n"
	"out vec3 color;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = u_mvp * vec4(mesh_position, 1.0);\n"
	"	color = mesh_color;\n"
	"}\n";

const char* fragmentShaderSource = 
	"#version 330\n"
	"in vec3 color;\n"
	"out vec4 pixelColor;\n"
	"void main() { pixelColor = vec4(color, 1.0f); }\n";

Game::Game()
{
}

Game::~Game()
{
	delete updateTimer;

	PassThrough.UnLoad();
	Knight.Unload();

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

	CameraTransform.Translate(vec3(0.0f, 5.0f, 20.0f));
	CameraProjection = mat4::PerspectiveProjection(60.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 1.0f, 10000.0f);
	StageTransform.Translate(vec3(0.0f, 0.0f, -15.0f));
	KnightTransform.RotateY(45.0f);
	KnightTransform.Translate(vec3(-7.5f, 0.0f, 0.0f));

	//// Create Vertex Array Object
	//glGenVertexArrays(1, &VAO);
	//glBindVertexArray(VAO);

	//// Create Vertex Buffer Obejct
	//glGenBuffers(1, &VBO1);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO1);

	//// Upload data to OpenGL
	//glBufferData(
	//	GL_ARRAY_BUFFER,   // Type of buffer
	//	sizeof(mesh)/2,	   // Size in bytes
	//	mesh,			   // Pointer to data
	//	GL_STATIC_DRAW);   // Regular usage

	//// Stream 0: Vertices
	//// Stream 1: Colors
	//
	//// Enable the streams we need
	//glEnableVertexAttribArray(0);
	//glEnableVertexAttribArray(1);

	//glVertexAttribPointer(
	//	0,					// Stream ID
	//	3,
	//	GL_FLOAT,
	//	GL_FALSE,			// NOT VECTOR NORMALIZATION
	//	0,					// 0 = tightly packed data
	//	reinterpret_cast<void*>(0));
	//
	//// Create second Vertex Buffer Object
	//glGenBuffers(1, &VBO2);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO2);

	//glBufferData(
	//	GL_ARRAY_BUFFER,   // Type of buffer
	//	sizeof(mesh) / 2,	   // Size in bytes
	//	&mesh[(sizeof(mesh) / 4) / 2],		   // Pointer to data
	//	GL_STATIC_DRAW);   // Regular usage

	//glVertexAttribPointer(
	//	1,
	//	3,
	//	GL_FLOAT,
	//	GL_FALSE,
	//	0,
	//	reinterpret_cast<void*>(0));

	//glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
	//glBindVertexArray(GL_NONE);
	//
	//int success = GL_FALSE;

	//// Create shader program
	//program = glCreateProgram();

	//// Create vertex shader
	//vertShader = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(
	//	vertShader,
	//	1,
	//	&vertexShaderSource,
	//	nullptr);

	//glCompileShader(vertShader);

	//glGetShaderiv(
	//	vertShader,
	//	GL_COMPILE_STATUS,
	//	&success);
	//if (success == GL_FALSE) { exit(0); }
	//
	//// Create fragment shader
	//fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(
	//	fragShader,
	//	1,
	//	&fragmentShaderSource,
	//	nullptr);

	//glCompileShader(fragShader);

	//glGetShaderiv(
	//	fragShader,
	//	GL_COMPILE_STATUS,
	//	&success);
	//if (success == GL_FALSE) { exit(0); }

	//// Build program object
	//glAttachShader(program, vertShader);
	//glAttachShader(program, fragShader);
	//glLinkProgram(program);

	//// Setup Scene
	//float aspect = 800.0f / 432.0f; // Width / Height
	//camera.perspective(60.0f, aspect, 1.0f, 1000.0f);
	//camera.m_pLocalPosition = vec3(0.0f, 4.0f, 4.0f);
	//camera.setRotationAngleX(-45.0f);

	// ...
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

	glBindVertexArray(Stage.VAO);
	glDrawArrays(GL_TRIANGLES, 0, Stage.GetNumVertices());
	glBindVertexArray(0);

	PassThrough.unBind();

	PassThrough.Bind();
	PassThrough.SendUniformMat4("uModel", KnightTransform.data, true);
	PassThrough.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	PassThrough.SendUniformMat4("uProj", CameraProjection.data, true);

	glBindVertexArray(Knight.VAO);
	glDrawArrays(GL_TRIANGLES, 0, Knight.GetNumVertices());
	glBindVertexArray(0);

	PassThrough.unBind();

	//// Bind Program
	//glUseProgram(program);

	//// Send MVP to the shaders
	//int mvpLoc = glGetUniformLocation(program, "u_mvp");

	//mat4 mvp = camera.getProjection() * camera.getView().GetInverse() * cube.getLocalToWorldMatrix();
	//glUniformMatrix4fv(mvpLoc, 1, false, mvp.data);

	////int modelLoc = glGetUniformLocation(program,
	////	"u_model");
	////int viewLoc = glGetUniformLocation(program,
	////	"u_view");
	////int projectionLoc = glGetUniformLocation(program,
	////	"u_projection");

	////glUniformMatrix4fv(modelLoc, 1, false,
	////	cube.getLocalToWorldMatrix().data);
	////glUniformMatrix4fv(viewLoc, 1, false,
	////	camera.getLocalToWorldMatrix().GetInverse().data);
	////glUniformMatrix4fv(projectionLoc, 1, false,
	////	camera.getProjection().data);

	//// Bind Mesh
	//glBindVertexArray(VAO);
	//glDrawArrays(GL_TRIANGLES, 0, 12 * 3);

	//glBindVertexArray(GL_NONE);
	//glUseProgram(GL_NONE);

	glutSwapBuffers();
}

void Game::keyboardDown(unsigned char key, int mouseX, int mouseY)
{
	if (key == 27) // Escape
		exit(1);
	if (key == 'a') // A
		xMoveKnight += -0.01f;
	if (key == 'd') // D
		xMoveKnight += 0.01f;
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
	yMoveKnight = 0.0f;
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
