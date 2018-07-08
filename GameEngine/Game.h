#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

enum GameState { START, QUIT };

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	void _init();
	int _print_error(const char*);
	void _get_events();

	SDL_Window* _window;
	SDL_Surface* _surface;
	GameState _state;
};

