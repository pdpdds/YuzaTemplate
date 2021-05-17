#include <SDL.h>

int main(int argc, char** argv)
{
	SDL_Window* pWindow = 0;
	SDL_Renderer* pRenderer = 0;

	int width = 320;
	int height = 200;

	if (SDL_CreateWindowAndRenderer(width, height, 0, &pWindow, &pRenderer) < 0)
	{
		printf("SDL_CreateWindowAndRenderer Error\n");
		return 0;
	}

	bool running = true;

	int lastTickCount = SDL_GetTicks();
	int curTickCount = lastTickCount;
	int k = 0;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
			}
			else if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		curTickCount = SDL_GetTicks();
		if (curTickCount - lastTickCount > 100)
		{
			k++;
			k = k % 2;
			lastTickCount = curTickCount;
		}

		if (k == 0)
			SDL_SetRenderDrawColor(pRenderer, 0, 255, 0, 255);
		else
		{
			SDL_SetRenderDrawColor(pRenderer, 255, 0, 255, 255);
		}

		SDL_RenderClear(pRenderer);
		SDL_RenderFillRect(pRenderer, NULL);

		SDL_RenderPresent(pRenderer);
	}

	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();
}