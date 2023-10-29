/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:38:23 by bbosnak           #+#    #+#             */
/*   Updated: 2023/10/03 00:38:24 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	else
	{
		game->total_movement += abs(oldx - game->player.x);
		game->total_movement += abs(oldy - game->player.y);
		ft_printf("\rMovement : %d", game->total_movement);
	}
}

int	update(t_game *game)
{
	input_handler(game);
	print_map(game, 0, 0);
	print_collisions(game, -1, -1);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
