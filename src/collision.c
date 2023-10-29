/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:29:46 by bbosnak           #+#    #+#             */
/*   Updated: 2023/10/03 00:29:47 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	print_player_collision(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->player.height)
	{
		x = -1;
		while (++x < game->player.width)
		{
			if (y == 0 || y == game->player.height - 1 || x == 0 \
			|| x == game->player.width - 1)
				game->img.addr[(game->player.y + y) * game->map_width \
				* SIZE + (game->player.x + x)] = 0xFF0000;
		}
	}
}

void	print_collisions(t_game *game, int x, int y)
{
	int	i;

	i = -1;
	if (!game->collisions)
		return ;
	while (++i < game->obj_count)
	{
		y = -1;
		while (++y < game->all_objects[i].height)
		{
			x = -1;
			while (++x < game->all_objects[i].width)
			{
				if ((y == 0 || y == game->all_objects[i].height - 1 \
				|| x == 0 || x == game->all_objects[i].width - 1) \
				&& game->all_objects[i].is_active)
				{
					game->img.addr[(game->all_objects[i].y + y) * \
					(game->map_width * SIZE) + \
					(game->all_objects[i].x + x)] = 0xFF0000;
				}
			}
		}
	}
	print_player_collision(game);
}

void	check_finish(t_game *game)
{
	if (game->coin_count == 0)
		exit_game(game);
}

bool	collision_controller(t_game *game)
{
	int			i;
	t_object	player;
	t_object	obj;

	player = game->player;
	i = -1;
	while (++i < game->obj_count)
	{
		obj = game->all_objects[i];
		if (player.x < obj.x + obj.width && player.x + player.width > obj.x && \
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
				return (true);
		}
	}
	return (false);
}
