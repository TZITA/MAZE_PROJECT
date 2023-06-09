#include "../headers/myheader.h"

/**
 * isCollision - A function to check if the player collides with a wall
 * @x: player pos
 * @y: player pos
 *
 * Return: 1 upon collision
 */
int isCollision(double x, double y)
{
	/* Check if the player position collides with a wall*/
	int mapX = (int)x;
	int mapY = (int)y;

	if (mapX < 0 || mapX >= mapW || mapY < 0 || mapY >= mapH)
		return (1); /* Collision with boundary walls*/
	return (worldMap[mapX][mapY] != 0);
}

/**
 * movePlayer - Function to handle keyboard inputs and player movement
 * @init: sdlinit struct
 * @event: SDL event
 */
void movePlayer(sdlinit *init, SDL_Event *event)
{
	if (event->type == SDL_KEYDOWN)
	{
		double nextX = init->player.x + init->player.dirX * 0.1;
		double nextY = init->player.y + init->player.dirY * 0.1;
		double oldDirX = init->player.dirX;
		double oldPlaneX = init->player.planeX;

		switch (event->key.keysym.sym)
		{
			case SDLK_UP:
			case SDLK_w:
				{
					if (!isCollision(nextX, nextY))
					{
						init->player.x = nextX;
						init->player.y = nextY;
					}
					if (isCollision(nextX, nextY) && worldMap[(int)nextX][(int)nextY] == 3)
					{
						init->player.x = rand() % mapW;
						init->player.y = rand() % mapH;
					}
				}
				break;
			case SDLK_DOWN:
			case SDLK_s:
				{
					if (!isCollision(nextX, nextY))
					{
						init->player.x = nextX;
						init->player.y = nextY;
					}
					if (isCollision(nextX, nextY) && worldMap[(int)nextX][(int)nextY] == 3)
					{
						init->player.x = rand() % mapW;
						init->player.y = rand() % mapH;
					}
				}
				break;
			case SDLK_RIGHT:
			case SDLK_d:
				{
					init->player.dirX =
						init->player.dirX * cos(0.1) - init->player.dirY * sin(0.1);
					init->player.dirY = oldDirX * sin(0.1) + init->player.dirY * cos(0.1);
					init->player.planeX =
						init->player.planeX * cos(0.1) - init->player.planeY * sin(0.1);
					init->player.planeY =
						oldPlaneX * sin(0.1) + init->player.planeY * cos(0.1);
				}
				break;
			case SDLK_LEFT:
			case SDLK_a:
				{
					init->player.dirX =
						init->player.dirX * cos(-0.1) - init->player.dirY * sin(-0.1);
					init->player.dirY = oldDirX * sin(-0.1) + init->player.dirY * cos(-0.1);
					init->player.planeX =
						init->player.planeX * cos(-0.1) - init->player.planeY * sin(-0.1);
					init->player.planeY =
						oldPlaneX * sin(-0.1) + init->player.planeY * cos(-0.1);
				}
				break;
		}
	}
}
