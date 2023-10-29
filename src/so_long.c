/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:33:39 by bbosnak           #+#    #+#             */
/*   Updated: 2023/10/12 10:47:45 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	early_exit(t_game *game)
{
	free_double_array(game->map);
	free_double_array(game->vmap.map);
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	game;

	game.obj_count = 0;
	game.map = NULL;
	game.vmap.map = NULL;
	if (ac != 2 || read_map(&game, av[1]) == false)
	{
		ft_printf("Read map error\n");
		early_exit(&game);
	}
	free_double_array(game.vmap.map);
	init(&game, game.map_width * SIZE, game.map_height * SIZE);
	create_objs(&game, 0, -1);
	mlx_hook(game.win, 17, 1L << 17, exit_game, &game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}
