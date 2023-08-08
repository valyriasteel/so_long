#include "../inc/so_long.h"

int	key_down(int code, t_game *game)
{
	if (code == 53)
		exit(0);
	if (code == 13)
		game->keys.w = true;
	if (code == 0)
		game->keys.a = true;
	if (code == 1)
		game->keys.s = true;
	if (code == 2)
		game->keys.d = true;
	return (0);
}

int	key_up(int code, t_game *game)
{
	if (code == 13)
		game->keys.w = false;
	if (code == 0)
		game->keys.a = false;
	if (code == 1)
		game->keys.s = false;
	if (code == 2)
		game->keys.d = false;
	return (0);
}