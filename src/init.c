/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:32:59 by bbosnak           #+#    #+#             */
/*   Updated: 2023/10/03 00:33:01 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	*xpm_to_image(t_game *game, char *path)
{
	int	a;

	return (mlx_xpm_file_to_image(game->mlx, path, &a, &a));
}

static void	init_images(t_game *game)
{
	int	a;

	game->imgs.player = xpm_to_image(game, "sprites/player.xpm");
	game->imgs.wall = xpm_to_image(game, "sprites/wall.xpm");
	game->imgs.exit = xpm_to_image(game, "sprites/exit.xpm");
	game->imgs.coin = xpm_to_image(game, "sprites/coin.xpm");
	game->imgs.bg = xpm_to_image(game, "sprites/bg.xpm");
	game->imgs.player_addr = (int *)mlx_get_data_addr \
	(game->imgs.player, &a, &a, &a);
	game->imgs.wall_addr = (int *)mlx_get_data_addr \
	(game->imgs.wall, &a, &a, &a);
	game->imgs.exit_addr = (int *)mlx_get_data_addr \
	(game->imgs.exit, &a, &a, &a);
	game->imgs.coin_addr = (int *)mlx_get_data_addr \
	(game->imgs.coin, &a, &a, &a);
	game->imgs.bg_addr = (int *)mlx_get_data_addr \
	(game->imgs.bg, &a, &a, &a);
	game->img.addr = (int *)mlx_get_data_addr \
	(game->img.img, &a, &a, &a);
}

void	init(t_game *game, int width, int height)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	game->img.img = mlx_new_image(game->mlx, width, height);
	game->collisions = false;
	game->keys.w = false;
	game->keys.a = false;
	game->keys.s = false;
	game->keys.d = false;
	game->player_speed = 5;
	game->total_movement = 0;
	mlx_hook(game->win, 2, 1L << 0, key_down, game);
	mlx_hook(game->win, 3, 1L << 1, key_up, game);
	init_images(game);
}
