#include "Game.h"

#include <string>


Game::Game()
{
}

Game::~Game()
{
	delete updateTimer;
	//...
}

void Game::initializeGame()
{
	updateTimer = new Timer();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_CULL_FACE);

	//Shaders
	if (!Shader.Load("./Assets/Shaders/PassThrough.vert", "./Assets/Shaders/PassThrough.frag"))
	{
		std::cout << "Shaders failed to initialize.\n";
		system("pause");
		exit(0);
	}
	if (!AnimationShader.Load("./Assets/Shaders/Animation.vert", "./Assets/Shaders/PassThrough.frag"))
	{
		std::cout << "Animation Shader failed to initialize.\n";
		system("pause");
		exit(0);
	}
	if (!UIShader.Load("./Assets/Shaders/UI.vert", "./Assets/Shaders/UI.frag"))
	{
		std::cout << "UI Shader failed to initialize.\n";
		system("pause");
		exit(0);
	}

	//Objects
	Paladin.MaxFrames = 1;
	if (!Paladin.LoadFromFile("./Assets/Models/Paladin.obj"))
	{
		std::cout << "Paladin failed to load\n";
		system("pause");
		exit(0);
	}
	SmallObjects.MaxFrames = 1;
	if (!SmallObjects.LoadFromFile("./Assets/Models/Scene_SmallObjects.obj"))
	{
		std::cout << "Scene_SmallObjects failed to load\n";
		system("pause");
		exit(0);
	}
	BigObjects.MaxFrames = 1;
	if (!BigObjects.LoadFromFile("./Assets/Models/Scene_BigObjects.obj"))
	{
		std::cout << "Scene_BigObjects failed to load\n";
		system("pause");
		exit(0);
	}
	Tree.MaxFrames = 1;
	if (!Tree.LoadFromFile("./Assets/Models/Tree.obj"))
	{
		std::cout << "Tree failed to load\n";
		system("pause");
		exit(0);
	}
	Building.MaxFrames = 1;
	if (!Building.LoadFromFile("./Assets/Models/Building.obj"))
	{
		std::cout << "Building failed to load\n";
		system("pause");
		exit(0);
	}
	Wall.MaxFrames = 1;
	if (!Wall.LoadFromFile("./Assets/Models/Wall.obj"))
	{
		std::cout << "Wall failed to load\n";
		system("pause");
		exit(0);
	}
	Grass.MaxFrames = 1;
	if (!Grass.LoadFromFile("./Assets/Models/Ground.obj"))
	{
		std::cout << "Grass failed to load\n";
		system("pause");
		exit(0);
	}
	Pew.MaxFrames = 1;
	if (!Pew.LoadFromFile("./Assets/Models/Pew.obj"))
	{
		std::cout << "Pew failed to load\n";
		system("pause");
		exit(0);
	}
	Candle.MaxFrames = 1;
	if (!Candle.LoadFromFile("./Assets/Models/Candle.obj"))
	{
		std::cout << "Candle failed to load\n";
		system("pause");
		exit(0);
	}
	Skull.MaxFrames = 1;
	if (!Skull.LoadFromFile("./Assets/Models/Skull.obj"))
	{
		std::cout << "Skull failed to load\n";
		system("pause");
		exit(0);
	}
	Torch.MaxFrames = 1;
	if (!Torch.LoadFromFile("./Assets/Models/Torch.obj"))
	{
		std::cout << "Torch failed to load\n";
		system("pause");
		exit(0);
	}
	Altar.MaxFrames = 1;
	if (!Altar.LoadFromFile("./Assets/Models/Altar.obj"))
	{
		std::cout << "Altar failed to load\n";
		system("pause");
		exit(0);
	}
	Banner.MaxFrames = 1;
	if (!Banner.LoadFromFile("./Assets/Models/Banner.obj"))
	{
		std::cout << "Banner failed to load\n";
		system("pause");
		exit(0);
	}
	BannerBar.MaxFrames = 1;
	if (!BannerBar.LoadFromFile("./Assets/Models/BannerBar.obj"))
	{
		std::cout << "BannerBar failed to load\n";
		system("pause");
		exit(0);
	}
	Rubble.MaxFrames = 1;
	if (!Rubble.LoadFromFile("./Assets/Models/Rubble.obj"))
	{
		std::cout << "Rubble failed to load\n";
		system("pause");
		exit(0);
	}

	//UI Paladin
	UIPaladinHelmet.MaxFrames = 1;
	if (!UIPaladinHelmet.LoadFromFile("./Assets/Models/UIPaladinHelmet.obj"))
	{
		std::cout << "UIPaladinHelmet failed to load\n";
		system("pause");
		exit(0);
	}
	UIPaladinBar.MaxFrames = 1;
	if (!UIPaladinBar.LoadFromFile("./Assets/Models/UIPaladinBar.obj"))
	{
		std::cout << "UIPaladinBar failed to load\n";
		system("pause");
		exit(0);
	}
	UIPaladinHealth.MaxFrames = 1;
	if (!UIPaladinHealth.LoadFromFile("./Assets/Models/UIPaladinHealth.obj"))
	{
		std::cout << "UIPaladinHealth failed to load\n";
		system("pause");
		exit(0);
	}
	//UI Demon
	UIDemonSkull.MaxFrames = 1;
	if (!UIDemonSkull.LoadFromFile("./Assets/Models/UIDemonSkull.obj"))
	{
		std::cout << "UIDemonSkull failed to load\n";
		system("pause");
		exit(0);
	}
	UIDemonBar.MaxFrames = 1;
	if (!UIDemonBar.LoadFromFile("./Assets/Models/UIDemonBar.obj"))
	{
		std::cout << "UIDemonBar failed to load\n";
		system("pause");
		exit(0);
	}
	UIDemonHealth.MaxFrames = 1;
	if (!UIDemonHealth.LoadFromFile("./Assets/Models/UIDemonHealth.obj"))
	{
		std::cout << "UIDemonHealth failed to load\n";
		system("pause");
		exit(0);
	}


	//Animation
	Demon.MaxFrames = 6;
	if (!Demon.LoadFromFile("./Assets/Animations/DemonAttack_01.obj"))
	{
		std::cout << "DemonAttack1 failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Demon.LoadFromFile("./Assets/Animations/DemonAttack_02.obj"))
	{
		std::cout << "DemonAttack2 failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Demon.LoadFromFile("./Assets/Animations/DemonAttack_03.obj"))
	{
		std::cout << "DemonAttack3 failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Demon.LoadFromFile("./Assets/Animations/DemonAttack_04.obj"))
	{
		std::cout << "DemonAttack4 failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Demon.LoadFromFile("./Assets/Animations/DemonAttack_05.obj"))
	{
		std::cout << "DemonAttack5 failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Demon.LoadFromFile("./Assets/Animations/DemonAttack_06.obj"))
	{
		std::cout << "DemonAttack6 failed to load\n";
		system("pause");
		exit(0);
	}

	Fire.MaxFrames = 6;
	if (!Fire.LoadFromFile("./Assets/Animations/Fire_01.obj"))
	{
		std::cout << "Fire_01 failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Fire.LoadFromFile("./Assets/Animations/Fire_02.obj"))
	{
		std::cout << "Fire_02 failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Fire.LoadFromFile("./Assets/Animations/Fire_03.obj"))
	{
		std::cout << "Fire_03 failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Fire.LoadFromFile("./Assets/Animations/Fire_04.obj"))
	{
		std::cout << "Fire_04 failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Fire.LoadFromFile("./Assets/Animations/Fire_05.obj"))
	{
		std::cout << "Fire_05 failed to load\n";
		system("pause");
		exit(0);
	}
	if (!Fire.LoadFromFile("./Assets/Animations/Fire_06.obj"))
	{
		std::cout << "Fire_06 failed to load\n";
		system("pause");
		exit(0);
	}

	//Textures
	if (!RedTex.Load("./Assets/Textures/Red.png"))
	{
		std::cout << "Gray failed to load\n";
		system("pause");
		exit(0);
	}
	if (!PaladinTex.Load("./Assets/Textures/PaladinTexture.png"))
	{
		std::cout << "Blue failed to load\n";
		system("pause");
		exit(0);
	}
	if (!DemonTex.Load("./Assets/Textures/Demon.png"))
	{
		std::cout << "Red failed to load\n";
		system("pause");
		exit(0);
	}
	if (!SmallObjTex.Load("./Assets/Textures/TextureSmall.png"))
	{
		std::cout << "TextureSmall failed to load\n";
		system("pause");
		exit(0);
	}
	if (!BigObjTex.Load("./Assets/Textures/TextureBig.png"))
	{
		std::cout << "TextureBig failed to load\n";
		system("pause");
		exit(0);
	}
	if (!FireTex.Load("./Assets/Textures/Fire.png"))
	{
		std::cout << "Fire failed to load\n";
		system("pause");
		exit(0);
	}
	if (!TreeTex.Load("./Assets/Textures/Tree.png"))
	{
		std::cout << "TreeTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!BuildingTex.Load("./Assets/Textures/Building.png"))
	{
		std::cout << "BuildingTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!WallTex.Load("./Assets/Textures/Wall.png"))
	{
		std::cout << "WallTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!GrassTex.Load("./Assets/Textures/Ground.png"))
	{
		std::cout << "GrassTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!PewTex.Load("./Assets/Textures/Pew.png"))
	{
		std::cout << "PewTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!CandleTex.Load("./Assets/Textures/Candle.png"))
	{
		std::cout << "CandleTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!SkullTex.Load("./Assets/Textures/Skull.png"))
	{
		std::cout << "SkullTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!TorchTex.Load("./Assets/Textures/torch.png"))
	{
		std::cout << "TorchTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!AltarTex.Load("./Assets/Textures/TableCloth.png"))
	{
		std::cout << "TableCloth failed to load\n";
		system("pause");
		exit(0);
	}
	if (!BannerTex.Load("./Assets/Textures/Banner.png"))
	{
		std::cout << "BannerTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!BannerBarTex.Load("./Assets/Textures/BannerBar.png"))
	{
		std::cout << "BannerBarTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!RubbleTex.Load("./Assets/Textures/Rubble.png"))
	{
		std::cout << "RubbleTex failed to load\n";
		system("pause");
		exit(0);
	}

	//UI Paladin Textures
	if (!UIPaladinHelmetTex.Load("./Assets/Textures/UIPaladinHelmet.png"))
	{
		std::cout << "UIPaladinHelmetTex failed to load\n";
		system("pause");
		exit(0);
	}
	if (!UIPaladinHealthBarTex.Load("./Assets/Textures/UIPaladinHealthBar.png"))
	{
		std::cout << "UIPaladinHealthBar failed to load\n";
		system("pause");
		exit(0);
	}
	//UI Demon Textures
	if (!UIDemonSkullTex.Load("./Assets/Textures/UIDemonSkull.png"))
	{
		std::cout << "UIDemonSkull failed to load\n";
		system("pause");
		exit(0);
	}
	if (!UIDemonHealthBarTex.Load("./Assets/Textures/UIDemonHealthBar.png"))
	{
		std::cout << "UIDemonHealthBar failed to load\n";
		system("pause");
		exit(0);
	}

<<<<<<< HEAD
	CameraTransform.Translate(vec3(0.0f, 6.5f, 25.0f));
	CameraTransform.RotateX(-10.0f);
	CameraProjection = mat4::PerspectiveProjection(60.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.01f, 10000.0f);

	//Paladin
	PaladinTransform.RotateY(80.0f);
	PaladinTransform.Translate(vec3(-14.0f, 0.0f, 0.0f));
=======
	StageTransform.Translate(vec3(0.0f, 0.0f, -15.0f));
	KnightTransform.RotateY(80.0f);
	KnightTransform.Translate(vec3(-7.5f, 0.0f, 0.0f));
>>>>>>> master

	//Demon
	DemonTransform.RotateY(-80.0f);
<<<<<<< HEAD
	DemonTransform.Translate(vec3(7.0f, 0.0f, 0.0f));

	//Small and Big Objects
	BigObjectsTransform.Scale(1.5f);
	SmallObjectsTransform.Scale(1.5f);

	//Tree, Wall and building
	TreeTransform.Translate(vec3(15.0f, 0.0f, -30.0f));
	BuildingTransform.Translate(vec3(20.0f, 0.0f, -70.0f));
	WallTransform.RotateY(90.0f);
	WallTransform.Translate(vec3(35.0f, 0.0f, -80.0f));

	//Ground
	GrassTransform.Translate(vec3(0.0f, -0.1f, -37.0f));

	//Pew,Candle
	PewTransform.Scale(0.6f);
	PewTransform.RotateY(-36.0f);
	PewTransform.Translate(vec3(-8.0f, 0.0f, 5.0f));
	CandleTransform.Scale(2.0f);
	CandleTransform.Translate(vec3(7.0f, 0.0f, 6.0f));

	//Fire,Skull and Torch
	FireTransform.Scale(0.1f);
	FireTransform.Translate(vec3(7.0f, 1.15f, 6.0f));
	SkullTransform.Translate(vec3(-8.0f, 0.0f, 10.0f));
	TorchTransform.Scale(1.5f);
	TorchTransform.Translate(vec3(-12.8f, 3.0f, 4.3f));

	//Altar, Banner and Rubble
	AltarTransform.RotateY(90.0f);
	AltarTransform.Translate(vec3(2.0f, 0.0f, -4.0f));
	RubbleTransform.Scale(1.5f);
	RubbleTransform.Translate(vec3(5.0f,0.0f, -8.0f));
	BannerTransform.Translate(vec3(-12.3f, 6.0f, 2.6f));
	BannerBarTransform.Translate(vec3(-12.3f, 5.0f, 2.6f));

	//UI
	UIPaladinHelmetTransform.Scale(6.0f);
	UIPaladinHelmetTransform.Translate(vec3(-6.9f, 15.0f, 10.2f));

	UIPaladinBarTransform.Scale(3.5f);
	UIPaladinBarTransform.Translate(vec3(-22.0f, 17.5f, 10.0f));

	UIPaladinHealthTransform.Scale(3.5f);
	UIPaladinHealthTransform.Translate(vec3(-22.0f, 14.85f, 10.1f));

	UIDemonSkullTransform.Scale(7.0f);
	UIDemonSkullTransform.Translate(vec3(73.5f, 16.7f, 10.2f));

	UIDemonBarTransform.Scale(3.5f);
	UIDemonBarTransform.Translate(vec3(21.5f, 17.5f, 10.0f));

	UIDemonHealthTransform.Scale(3.5f);
	UIDemonHealthTransform.Translate(vec3(21.5f, 14.85f, 10.1f));
=======
	DemonTransform.Translate(vec3(10.0f, 0.0f, 0.0f));

	AnimTestTransform.Translate(vec3(0.0f, 0.0f, -4.0f));
	HitBoxTransform.Translate(vec3(-999.9f, -999.9f, 0));
>>>>>>> master
}

void Game::update()
{
	// update our clock so we have the delta time since the last update
	updateTimer->tick();

	float deltaTime = updateTimer->getElapsedTimeSeconds();
	TotalGameTime += deltaTime;

	if (PaladinTransform.GetTranslation().y > 0.0f)
		MoveKnightY -= 0.04f;
	else
	{
		MoveKnightY = 0.0f;
<<<<<<< HEAD
		PaladinTransform.Translate(vec3(0.0f, PaladinTransform.GetTranslation().y * -1, 0.0f));
=======
		KnightTransform.SetTranslation(vec3(KnightTransform.GetTranslation().x, 0.0f, 0.0f));
>>>>>>> master
	}
	//Move Left
	if (A && MoveKnightX > -0.3f)
	{
		MoveKnightX -= 0.01f;
	}
	else if (A == false && MoveKnightX < 0) //Slow down
	{
		MoveKnightX += 0.02f;
		if (MoveKnightX > 0) //Prevents movement after releasing the key
			MoveKnightX = 0;
	}

	if (PaladinTransform.GetTranslation().x < -19)
	{
		MoveKnightX = 0.0f;
		PaladinTransform.Translate(vec3((PaladinTransform.GetTranslation().x + 19) * -1, 0.0f, 0.0f));
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

	//Jump
	if (Space && MoveKnightY == 0.0f)
		MoveKnightY = 0.5f;

	//Collision with demon
	if (PaladinTransform.GetTranslation().x + 1.0f >= DemonTransform.GetTranslation().x - 0.5f&&
		PaladinTransform.GetTranslation().x - 1.0f <= DemonTransform.GetTranslation().x + 0.5f)
	{
		DemonHurt = true;
		MoveKnightX = -0.3f;
		MoveKnightY = 0.4f;
		UIDemonHealthTransform.Translate(vec3(1.0f, 0.0f, 0.0f));
	}
	else {
		DemonHurt = false;
	}

<<<<<<< HEAD
	if (PaladinTransform.GetTranslation().x + 1.0f >= DemonTransform.GetTranslation().x - 4.5f &&
		PaladinTransform.GetTranslation().x - 1.0f <= DemonTransform.GetTranslation().x + 0.5f)
	{
		if(DemonAttackNumber == 0)
			DemonAttack = true;
		if (DemonAttackNumber == 3 && KnightHurt == false)
		{
			MoveKnightX = -0.3f;
			MoveKnightY = 0.4f;
			KnightHurt = true;
			UIPaladinHealthTransform.Translate(vec3(-4.0f, 0.0f, 0.0f));
		}
	}
=======
	//Jump
	if (Space && MoveKnightY == 0.0f)
		MoveKnightY = 0.8f;
>>>>>>> master

	if (HitBoxTransform.GetTranslation().x+1.0f>=DemonTransform.GetTranslation().x-1.0f&&HitBoxTransform.GetTranslation().x - 1.0f <= DemonTransform.GetTranslation().x + 1.0f) {
		isColliding = true;
	}
	else {
		isColliding = false;
	}

	if (KnightTransform.GetTranslation().x + 1.0f >= DemonTransform.GetTranslation().x - 0.5f&&KnightTransform.GetTranslation().x - 1.0f <= DemonTransform.GetTranslation().x + 0.5f) {
		MoveKnightX = -0.7f;
		MoveKnightY = 0.7f;
		KnightHurt = true;
	}
	else {
		KnightHurt = false;
	}
	

	if (DemonAttack)
	{
		DemonInterp += 0.07f;
		if (DemonInterp > 1.0f)
		{
			DemonInterp = 0.0f;
			DemonAttackNumber++;
			if (DemonAttackNumber == 6)
			{
				DemonAttackNumber = 0;
				DemonAttack = false;
				KnightHurt = false;
			}
		}
	}


	FireInterp += 0.2f;
	if (FireInterp > 1.0f)
	{
		FireInterp = 0.0f;
		FireNumber++;
		if (FireNumber == 6)
			FireNumber = 0;
	}

	if (UIPaladinHealthTransform.GetTranslation().x < -51 || UIDemonHealthTransform.GetTranslation().x > 50)
	{
		system("pause");
		exit(0);
	}

	PaladinTransform.Translate(vec3(MoveKnightX, MoveKnightY, 0.0f));
}

void Game::draw()
{
	glClearColor(0.06f, 0.02f, 0.15f, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	


	Shader.Bind();
	Shader.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	Shader.SendUniformMat4("uProj", CameraProjection.data, true);
	//lighting
	Shader.SendUniform("LightPosition", CameraTransform.GetInverse() * vec4(6.0f, 2.0f, 7.0f, 1.0f));
	Shader.SendUniform("LightPosition2", CameraTransform.GetInverse() * vec4(30.0f, 30.0f, -20.0f, 1.0f));


<<<<<<< HEAD
	//Objects
	Shader.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	Shader.SendUniformMat4("uProj", CameraProjection.data, true);

	Shader.SendUniformMat4("uModel", SmallObjectsTransform.data, true);
	SmallObjTex.Bind();
	SmallObjects.bind();
	SmallObjects.draw();
	SmallObjects.unbind();
	SmallObjTex.Unbind();

	Shader.SendUniformMat4("uModel", BigObjectsTransform.data, true);
	BigObjTex.Bind();
	BigObjects.bind();
	BigObjects.draw();
	BigObjects.unbind();
	BigObjTex.Unbind();

	Shader.SendUniformMat4("uModel", PaladinTransform.data, true);
	if (KnightHurt)
	{
		RedTex.Bind();
	}
	else
	{
		PaladinTex.Bind();
	}
	glDisable(GL_CULL_FACE);
	Paladin.bind();
	Paladin.draw();
	Paladin.unbind();
	glEnable(GL_CULL_FACE);
	PaladinTex.Unbind();

	TreeTex.Bind();
	Tree.bind();
	Shader.SendUniformMat4("uModel", TreeTransform.data, true);
	Tree.draw();
	TreeTransform.Translate(vec3(-10.0f, 0.0f, -10.0f));
	Shader.SendUniformMat4("uModel", TreeTransform.data, true);
	Tree.draw();
	TreeTransform.Translate(vec3(-10.0f, 0.0f, 10.0f));
	Shader.SendUniformMat4("uModel", TreeTransform.data, true);
	Tree.draw();
	TreeTransform.Translate(vec3(-10.0f, 0.0f, -10.0f));
	Shader.SendUniformMat4("uModel", TreeTransform.data, true);
	Tree.draw();
	Tree.unbind();
	TreeTex.Unbind();
	TreeTransform.Translate(vec3(30.0f, 0.0f, 10.0f));

	Shader.SendUniformMat4("uModel", BuildingTransform.data, true);
	BuildingTex.Bind();
	Building.bind();
	Building.draw();
	Building.unbind();
	BuildingTex.Unbind();

	WallTex.Bind();
	Wall.bind();
	Shader.SendUniformMat4("uModel", WallTransform.data, true);
	Wall.draw();
	WallTransform.Translate(vec3(-23.0f, 0.0f, 0.0f));
	Shader.SendUniformMat4("uModel", WallTransform.data, true);
	Wall.draw();
	WallTransform.Translate(vec3(-23.0f, 0.0f, 0.0f));
	Shader.SendUniformMat4("uModel", WallTransform.data, true);
	Wall.draw();
	Wall.unbind();
	WallTex.Unbind();
	WallTransform.Translate(vec3(46.0f, 0.0f, 0.0f));


	Shader.SendUniformMat4("uModel", GrassTransform.data, true);
	GrassTex.Bind();
	Grass.bind();
	Grass.draw();
	Grass.unbind();
	GrassTex.Unbind();

	PewTex.Bind();
	Pew.bind();
	Shader.SendUniformMat4("uModel", PewTransform.data, true);
	Pew.draw();
	PewTransform.Translate(vec3(14.0f, 0.0f, 0.0f));
	PewTransform.RotateY(-30.0f);
	Shader.SendUniformMat4("uModel", PewTransform.data, true);
	Pew.draw();
	Pew.unbind();
	PewTex.Unbind();
	PewTransform.RotateY(30.0f);
	PewTransform.Translate(vec3(-14.0f, 0.0f, 0.0f));

	CandleTex.Bind();
	Candle.bind();
	Shader.SendUniformMat4("uModel", CandleTransform.data, true);
	Candle.draw();
	CandleTransform.Translate(vec3(-0.5f, 0.0f, 1.0f));
	Shader.SendUniformMat4("uModel", CandleTransform.data, true);
	Candle.draw();
	CandleTransform.Translate(vec3(-0.7f, 0.0f, -0.3f));
	Shader.SendUniformMat4("uModel", CandleTransform.data, true);
	Candle.draw();
	CandleTransform.Translate(vec3(0.0f, 0.0f, -1.0f));
	Shader.SendUniformMat4("uModel", CandleTransform.data, true);
	Candle.draw();
	Candle.unbind();
	CandleTex.Unbind();
	CandleTransform.Translate(vec3(1.2f, 0.0f, 0.3f));


	SkullTex.Bind();
	Skull.bind();
	Shader.SendUniformMat4("uModel", SkullTransform.data, true);
	Skull.draw();
	SkullTransform.Translate(vec3(1.0f, 0.0f,-1.0f));
	Shader.SendUniformMat4("uModel", SkullTransform.data, true);
	Skull.draw();
	SkullTransform.Translate(vec3(1.2f, 0.0f, -0.2f));
	Shader.SendUniformMat4("uModel", SkullTransform.data, true);
	Skull.draw();
	SkullTransform.Translate(vec3(0.0f, 0.0f, 1.0f));
	Shader.SendUniformMat4("uModel", SkullTransform.data, true);
	Skull.draw();
	Skull.unbind();
	SkullTex.Unbind();
	SkullTransform.Translate(vec3(-2.2f, 0.0f, 0.2f));

	TorchTex.Bind();
	Torch.bind();
	Shader.SendUniformMat4("uModel", TorchTransform.data, true);
	Torch.draw();
	TorchTransform.Translate(vec3(0.0f, 0.0f, -6.8f));
	Shader.SendUniformMat4("uModel", TorchTransform.data, true);
	Torch.draw();
	TorchTransform.Translate(vec3(4.4f, 0.0f, 9.65f));
	TorchTransform.RotateY(-90.0f);
	Shader.SendUniformMat4("uModel", TorchTransform.data, true);
	Torch.draw();
	Torch.unbind();
	TorchTex.Unbind();
	TorchTransform.RotateY(90.0f);
	TorchTransform.Translate(vec3(-4.4f, 0.0f, -2.85f));

	Shader.SendUniformMat4("uModel", AltarTransform.data, true);
	AltarTex.Bind();
	Altar.bind();
	Altar.draw();
	Altar.unbind();
	AltarTex.Unbind();

	Shader.SendUniformMat4("uModel", RubbleTransform.data, true);
	RubbleTex.Bind();
	Rubble.bind();
	Rubble.draw();
	Rubble.unbind();
	RubbleTex.Unbind();

	BannerBarTex.Bind();
	BannerBar.bind();
	Shader.SendUniformMat4("uModel", BannerBarTransform.data, true);
	BannerBar.draw();
	BannerBarTransform.Translate(vec3(0.0f, 0.0f, -7.0f));
	Shader.SendUniformMat4("uModel", BannerBarTransform.data, true);
	BannerBar.draw();
	BannerBar.unbind();
	BannerBarTex.Unbind();
	BannerBarTransform.Translate(vec3(0.0f, 0.0f, 7.0f));

	BannerTex.Bind();
	Banner.bind();
	Shader.SendUniformMat4("uModel", BannerTransform.data, true);
	Banner.draw();
	BannerTransform.Translate(vec3(0.0f, 0.0f, -7.0f));
	Shader.SendUniformMat4("uModel", BannerTransform.data, true);
	Banner.draw();
	Banner.unbind();
	BannerTex.Unbind();
	BannerTransform.Translate(vec3(0.0f, 0.0f, 7.0f));

	Shader.unBind();

	//Animation
	AnimationShader.Bind();
	AnimationShader.SendUniformMat4("uModel", DemonTransform.data, true);
	AnimationShader.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	AnimationShader.SendUniformMat4("uProj", CameraProjection.data, true);
	AnimationShader.SendUniform("LightPosition", CameraTransform.GetInverse() * vec4(6.0f, 2.0f, 7.0f, 1.0f));
	AnimationShader.SendUniform("LightPosition2", CameraTransform.GetInverse() * vec4(30.0f, 30.0f, -20.0f, 1.0f));

	AnimationShader.SendUniform("T", DemonInterp);
	AnimationShader.SendUniform("index", DemonAttackNumber);

	if (DemonHurt) {
		RedTex.Bind();
	}
	else {
		DemonTex.Bind();
=======
	PassThrough.SendUniformMat4("uModel", KnightTransform.data, true);
	if (KnightHurt == true) {
		Grey.Bind();
		if (KnightTransform.GetTranslation().y <= 0.0f)
		{
			MoveKnightY = 0.0f;
		}
	}
	else
	{
		Blue.Bind();
	}
	Knight.bind();
	Knight.draw();
	Knight.unbind();
	Blue.Unbind();


	PassThrough.SendUniformMat4("uModel", DemonTransform.data, true);
	if (isColliding == true) {
		Blue.Bind();
	}
	else {
		Red.Bind();
>>>>>>> master
	}
	Demon.bind();
	Demon.draw();
	Demon.unbind();
<<<<<<< HEAD
	DemonTex.Unbind();
	RedTex.Bind();

	AnimationShader.SendUniform("T", FireInterp);
	AnimationShader.SendUniform("index", FireNumber);
	FireTex.Bind();
	Fire.bind();
	AnimationShader.SendUniformMat4("uModel", FireTransform.data, true);
	Fire.draw();
	FireTransform.Translate(vec3(-0.5f, 0.0f, 1.0f));
	AnimationShader.SendUniformMat4("uModel", FireTransform.data, true);
	Fire.draw();
	FireTransform.Translate(vec3(-0.7f, 0.0f, -0.3f));
	AnimationShader.SendUniformMat4("uModel", FireTransform.data, true);
	Fire.draw();
	FireTransform.Translate(vec3(0.0f, 0.0f, -1.0f));
	AnimationShader.SendUniformMat4("uModel", FireTransform.data, true);
	Fire.draw();
	Fire.unbind();
	FireTex.Unbind();
	FireTransform.Translate(vec3(1.2f, 0.0f, 0.3f));


	AnimationShader.unBind();


	UIShader.Bind();
	//UI
	CameraTransform.RotateX(10.0f);
	CameraTransform.Translate(vec3(0.0f, -6.5f, 0.0f));
	CameraProjection = mat4::OrthographicProjection(WINDOW_WIDTH / -40, WINDOW_WIDTH / 40, WINDOW_HEIGHT / 40, WINDOW_HEIGHT / -40, 0.01f, 10000.0f);
	UIShader.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	UIShader.SendUniformMat4("uProj", CameraProjection.data, true);

	UIShader.SendUniformMat4("uModel", UIPaladinHelmetTransform.data, true);
	UIPaladinHelmetTex.Bind();
	UIPaladinHelmet.bind();
	UIPaladinHelmet.draw();
	UIPaladinHelmet.unbind();
	UIPaladinHelmetTex.Unbind();

	UIPaladinHealthBarTex.Bind();

	UIShader.SendUniformMat4("uModel", UIPaladinBarTransform.data, true);
	UIPaladinBar.bind();
	UIPaladinBar.draw();
	UIPaladinBar.unbind();

	UIShader.SendUniformMat4("uModel", UIPaladinHealthTransform.data, true);
	UIPaladinHealth.bind();
	UIPaladinHealth.draw();
	UIPaladinHealth.unbind();

	UIPaladinHealthBarTex.Unbind();

	UIShader.SendUniformMat4("uModel", UIDemonSkullTransform.data, true);
	UIDemonSkullTex.Bind();
	UIDemonSkull.bind();
	UIDemonSkull.draw();
	UIDemonSkull.unbind();
	UIDemonSkullTex.Unbind();

	UIDemonHealthBarTex.Bind();

	UIShader.SendUniformMat4("uModel", UIDemonBarTransform.data, true);
	UIDemonBar.bind();
	UIDemonBar.draw();
	UIDemonBar.unbind();

	UIShader.SendUniformMat4("uModel", UIDemonHealthTransform.data, true);
	UIDemonHealth.bind();
	UIDemonHealth.draw();
	UIDemonHealth.unbind();

	UIDemonHealthBarTex.Unbind();

	CameraTransform.Translate(vec3(0.0f, 6.5f, 0.0f));
	CameraTransform.RotateX(-10.0f);
	CameraProjection = mat4::PerspectiveProjection(60.0f, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.01f, 10000.0f);

	UIShader.unBind();
=======
	Red.Unbind();
	Blue.Bind();

	PassThrough.SendUniformMat4("uModel", HitBoxTransform.data, true);
	Red.Bind();
	Hitbox.bind();
	Hitbox.draw();
	Hitbox.unbind();
	Red.Unbind();

	PassThrough.unBind();

	interp += updateTimer->getElapsedTimeSeconds();
	if (interp > 1.0f)
	{
		interp = 0.0f;
		index++;
		if (index == 4)
			index = 0;
	}

	Animation.Bind();
	Animation.SendUniformMat4("uModel", AnimTestTransform.data, true);
	Animation.SendUniformMat4("uView", CameraTransform.GetInverse().data, true);
	Animation.SendUniformMat4("uProj", CameraProjection.data, true);
	Animation.SendUniform("T", interp);
	Animation.SendUniform("index", index);
	Animation.SendUniform("LightPosition", CameraTransform.GetInverse() * vec4(4.0f, 0.0f, 0.0f, 1.0f));

	AnimTest.bind();
	AnimTest.draw();
	AnimTest.unbind();

	Animation.unBind();
>>>>>>> master

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
<<<<<<< HEAD
=======
	if (key == '0' || key == '0')
		L = true;
>>>>>>> master


	switch (key) {
	case 'i':
		//CameraTransform.Translate(vec3(0.0f, 0.0f, -1.0f));
		break;
	case 'k':
		//CameraTransform.Translate(vec3(0.0f, 0.0f, 1.0f));
		break;
	case 'j':
		//CameraTransform.Translate(vec3(-1.0f, 0.0f, 0.0f));
		break;
	case 'l':
		//CameraTransform.Translate(vec3(1.0f, 0.0f, 0.0f));
		break;
	case 'p':
		//Shader.reload();
		//AnimationShader.reload();
		//UIShader.reload();
		break;
	}
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
