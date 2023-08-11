#include "../inc/so_long.h"

void	print_collisions(t_game *game)
{
	int i = -1;
	while (++i < game->obj_count)
	{
		for (int y = 0; y < game->all_objects[i].height; y++)
		{
			for (int x = 0; x < game->all_objects[i].width; x++)
			{
				if ((y == 0 || y == game->all_objects[i].width - 1 || x == 0 || x == game->all_objects[i].height - 1) && game->all_objects[i].is_active)
				{
					game->img.addr[(game->all_objects[i].y + y) * game->map_width * SIZE + (game->all_objects[i].x + x)] = 0xFF0000;			
				}
			}
		}
	}
	for (int y = 0; y < game->player.height; y++)
	{
		for (int x = 0; x < game->player.width; x++)
		{
			if (y == 0 || y == game->player.height - 1 || x == 0 || x == game->player.width - 1)
				game->img.addr[(game->player.y + y) * game->map_width * SIZE + (game->player.x + x)] = 0xFF0000;
		}
	}
}

void	check_finish(t_game *game)
{
	if (game->coin_count == 0)
		exit(0);
}

bool	collision_controller(t_game *game)
{
	t_object	player;

	player = game->player;
	int i = -1;
	while (++i < game->obj_count)
	{
		t_object obj = game->all_objects[i];
		if(player.x < obj.x + obj.width && player.x + player.width > obj.x &&
    	player.y < obj.y + obj.height && player.y + player.height > obj.y)
		{
			if (obj.type == 'C')
			{
				if (game->all_objects[i].is_active)
					game->coin_count--;
				game->all_objects[i].is_active = false;
			}
			else if (obj.type == 'E')
				check_finish(game);
			else
				return true;
		}
	}
	return false;
}