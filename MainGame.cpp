#include "MainGame.h"



MainGame::MainGame()
{
	try {
		initSubsystems();
	}
	catch (std::exception e) {
		SDL_Quit();
		std::cerr << e.what() << std::endl;
	}

	
}


MainGame::~MainGame()
{
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}


void MainGame::run() 
{
	while (mGameState != GameState::EXIT) {
		processInput();
		renderFrame();
		
	}
}

void MainGame::initSubsystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	mWindow = SDL_CreateWindow(
		"Game Engine",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL);

	if (mWindow == NULL)
		throw std::exception("SDL could not create window!");

	SDL_GLContext glContext = SDL_GL_CreateContext(mWindow);
	if (glContext == NULL)
		throw std::exception("SDL_GLContext could not be created!");

	GLenum error = glewInit();
	if (error != GLEW_OK)
		throw std::exception("Could not initialize glew");

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0, 0, 0, 1.0f);

}

void MainGame::processInput()
{
	SDL_Event mEvent;
	while (SDL_PollEvent(&mEvent)) {
		switch (mEvent.type)
		{
			case SDL_QUIT:
				mGameState = GameState::EXIT;
				break;

			case SDL_MOUSEMOTION:
				std::cout << mEvent.motion.x << " " << mEvent.motion.y << std::endl;
				break;

			default:
				break;
		}
	}
}

void MainGame::renderFrame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SDL_GL_SwapWindow(mWindow);
}
