#include "InputSystem.hpp"

void InputSystem::ProcessInput()
{
	releasedKeys.clear();
	while (SDL_PollEvent(&event) != 0)
	{
		switch(event.type)
		{
			case SDL_KEYDOWN:
			{
				keyCodeDown = event.key.keysym.sym;
				pressedKeys.push_back(keyCodeDown);
				break;
			}

			case SDL_KEYUP:
			{
				keyCodeUp = event.key.keysym.sym;
				pressedKeys.erase(remove(pressedKeys.begin(), pressedKeys.end(), keyCodeUp));
				releasedKeys.push_back(keyCodeUp);
				break;
			}

			case SDL_QUIT:
			{
				quitEvent = true;
				break;
			}

			default:
			{
				break;
			}
		}
	}
}

bool InputSystem::IsKeyPressed(const char* keyName)
{

	if (count(pressedKeys.begin(), pressedKeys.end(), SDL_GetKeyFromName(keyName)))
	{
		return true;
	}
	return false;
}

bool InputSystem::IsKeyReleased(const char* keyName)
{
	if (count(releasedKeys.begin(), releasedKeys.end(), SDL_GetKeyFromName(keyName)))
	{
		releasedKeys.erase(remove(releasedKeys.begin(), releasedKeys.end(), keyCodeUp));
		return true;
	}
	return false;
}
