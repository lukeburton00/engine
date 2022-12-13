#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class InputSystem
{
	public:
		void ProcessInput();
		bool IsKeyPressed(const char * key);
		bool IsKeyReleased(const char * key);
		bool quitEvent;


	private:
		SDL_Keycode keyCodeDown;
		std::vector<SDL_Keycode> pressedKeys;
		std::vector<SDL_Keycode> releasedKeys;
		SDL_Keycode keyCodeUp;
		SDL_Event event;

};
