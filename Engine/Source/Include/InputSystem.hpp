#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

using namespace std;

class InputSystem
{
	public:
		void ProcessInput();
		bool IsKeyPressed(const char* key);
		bool IsKeyReleased(const char* key);
		bool quitEvent;


	private:
		SDL_Keycode keyCodeDown;
		vector<SDL_Keycode> pressedKeys;
		vector<SDL_Keycode> releasedKeys;
		SDL_Keycode keyCodeUp;
		SDL_Event event;

};
