#include "../inc/so_long.h"

void	print_obj(t_game *game, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.coin, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.exit, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.bg, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.player, x, y);
}

void	print_map(t_game *game, int x, int y)
{
	while (++y < game->map_height - 1)
	{
		x = 0;
		while (++x < game->map_width - 1)
		{
			print_obj(game, x * SIZE, y * SIZE, '0');
		}
	}
	y = -1;
	while (++y < game->obj_count)
	{
		if (game->all_objects[y].is_active)
			print_obj(game, game->all_objects[y].x, game->all_objects[y].y,
				game->all_objects[y].type);
		else
			print_obj(game, game->all_objects[y].x, game->all_objects[y].y, '0');
	}
	print_obj(game, game->player.x, game->player.y, 'P');
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
				game->all_objects[i].is_active = false;
			else
				return true;
		}
	}
	return false;
}

void	input_handler(t_game *game)
{
	int	oldx;
	int	oldy;

	oldx = game->player.x;
	oldy = game->player.y;
	if (game->keys.w)
		game->player.y -= game->player_speed;
	if (game->keys.a)
		game->player.x -= game->player_speed;
	if (game->keys.s)
		game->player.y += game->player_speed;
	if (game->keys.d)
		game->player.x += game->player_speed;
	if (collision_controller(game))
	{
		game->player.x = oldx;
		game->player.y = oldy;
	}
}

int	update(t_game *game)
{
	input_handler(game);
	print_map(game, 0, 0);
	return (0);
}