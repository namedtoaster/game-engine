#include "Game.h"
#include "Constants.h"

#include <GL/glew.h>
#include <iostream>

using namespace std;

Game::Game()
{
	_window = nullptr;
	_state = START;
}


Game::~Game()
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

int Game::_print_error(const char* msg) {
	cout << msg << SDL_GetError() << endl;

	return 1;
}

void Game::run() {
	_init();

	while (_state != QUIT) {
		_get_events();
	}
}

void Game::_init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		_print_error("Cannot initialize: ");
	}

	//Create window
	_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (_window == NULL)
	{
		_print_error("Cannot create window: ");
	}
}

void Game::_get_events() {
	//Handle events on queue
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			_state = QUIT;
		}
	}
}