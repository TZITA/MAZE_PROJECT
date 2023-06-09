#include "../headers/myheader.h"

/**
 * Init - A function to initialize SDL window, renderer and etc
 * @init: sdlinit struct
 *
 * Return: 1, upon failure 0.
 */
int Init(sdlinit *init)
{
	init->window = SDL_CreateWindow("FIND THE RED WALL", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_W, SCREEN_H, 0);
	if (!init->window)
	{
		printf("Failed to create SDL window: %s\n", SDL_GetError());
		return (0);
	}
	init->renderer = SDL_CreateRenderer(init->window, -1,
			SDL_RENDERER_PRESENTVSYNC);
	if (!init->renderer)
	{
		printf("Failed to create SDL renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(init->window);
		return (0);
	}
	init->texture = SDL_CreateTexture(init->renderer, SDL_PIXELFORMAT_RGBA32,
			SDL_TEXTUREACCESS_STREAMING, SCREEN_W, SCREEN_H);
	if (!init->texture)
	{
		printf("Failed to create SDL texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(init->renderer);
		SDL_DestroyWindow(init->window);
		return (0);
	}

	init->pixels = (Uint32 *)malloc(SCREEN_W * SCREEN_H * sizeof(Uint32));
	init->player.x = 3.456;
	init->player.y = 2.345;
	init->player.dirX = 1;
	init->player.dirY = 0;
	init->player.planeX = 0;
	init->player.planeY = 0.66;

	return (1);
}
