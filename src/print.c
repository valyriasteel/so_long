/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:36:14 by bbosnak           #+#    #+#             */
/*   Updated: 2023/10/03 00:36:15 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	sprite_to_addr(t_game *game, t_object *obj, int *addr)
{
	int	i;
	int	j;

	i = -1;
	while (++i < obj->height)
	{
		j = -1;
		while (++j < obj->width)
		{
			if (addr[i * obj->width + j] != -16777216)
				game->img.addr[(obj->y + i) * (game->map_width * SIZE)
					+ (obj->x + j)] = addr[i * obj->width + j];
		}
	}
}

void	print_background(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
			game->img.addr[(y + i) * (game->map_width * SIZE) + (x + j)] \
			= game->imgs.bg_addr[i * SIZE + j];
	}
}

void	print_obj(t_game *game, t_object *object)
{
	if (object->type == '1')
		sprite_to_addr(game, object, game->imgs.wall_addr);
	else if (object->type == 'C')
		sprite_to_addr(game, object, game->imgs.coin_addr);
	else if (object->type == 'E')
		sprite_to_addr(game, object, game->imgs.exit_addr);
	else if (object->type == '0')
		sprite_to_addr(game, object, game->imgs.bg_addr);
	else if (object->type == 'P')
		sprite_to_addr(game, object, game->imgs.player_addr);
}

void	print_map(t_game *game, int x, int y)
{
	while (++y < game->map_height - 1)
	{
		x = -1;
		while (++x < game->map_width - 1)
		{
			print_background(game, x * SIZE, y * SIZE);
		}
	}
	y = -1;
	while (++y < game->obj_count)
	{
		if (game->all_objects[y].is_active)
			print_obj(game, &game->all_objects[y]);
	}
	print_obj(game, &game->player);
}
