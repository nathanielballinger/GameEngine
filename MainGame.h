#pragma once
#include <Windows.h>

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>

enum class GameState { PLAY, EXIT };

class MainGame
{

public:
	MainGame();
	~MainGame();
	void run();

private:
	GameState mGameState;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	void initSubsystems();
	void processInput();
	void renderFrame();
};

