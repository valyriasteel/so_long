/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:15:30 by bbosnak           #+#    #+#             */
/*   Updated: 2023/10/03 00:15:32 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	path_finder(t_vmap *vmap, int x, int y)
{
	if (vmap->map[y][x] == 'P')
		vmap->player = true;
	if (vmap->map[y][x] == 'C')
		vmap->coins++;
	vmap->map[y][x] = '1';
	if (vmap->map[y + 1][x] && vmap->map[y + 1][x] != '1')
		path_finder(vmap, x, y + 1);
	if (vmap->map[y - 1][x] && vmap->map[y - 1][x] != '1')
		path_finder(vmap, x, y - 1);
	if (vmap->map[y][x + 1] && vmap->map[y][x + 1] != '1')
		path_finder(vmap, x + 1, y);
	if (vmap->map[y][x - 1] && vmap->map[y][x - 1] != '1')
		path_finder(vmap, x - 1, y);
}

static void	copy_map(t_game *game, int x, int y)
{
	int	exitx;
	int	exity;

	game->vmap.map = malloc(sizeof(char *) * game->map_height + 1);
	while (++y < game->map_height)
	{
		x = -1;
		game->vmap.map[y] = malloc(sizeof(char) * game->map_width);
		while (++x < game->map_width)
		{
			game->vmap.map[y][x] = game->map[y][x];
			if (game->map[y][x] == 'E')
			{
				exity = y;
				exitx = x;
			}
		}
	}
	game->vmap.map[y] = NULL;
	game->vmap.player = false;
	path_finder(&game->vmap, exitx, exity);
}

bool	check_path_finder(t_game *game)
{
	if (game->vmap.player == false || game->vmap.coins != game->coin_count)
		return (false);
	return (true);
}

bool	check_objects(t_game *game, int x, int y)
{
	int	*arr;

	arr = ft_calloc(3, sizeof(int));
	while (++y < game->map_height)
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				arr[0]++;
			if (game->map[y][x] == 'E')
				arr[1]++;
			if (game->map[y][x] == 'P')
				arr[2]++;
		}
	}
	if (arr[0] == 0 || arr[1] != 1 || arr[2] != 1)
		return (false);
	game->coin_count = arr[0];
	free(arr);
	copy_map(game, -1, -1);
	return (check_path_finder(game));
}

bool	check_map(t_game *game, int x, int y)
{
	while (++y < game->map_height)
	{
		x = -1;
		while (game->map[y][++x])
		{
			if ((y == 0 || y == game->map_height - 1) && \
			(game->map[y][x] != '1'))
				return (false);
			if ((x == 0 || x == game->map_width - 1) && game->map[y][x] != '1')
				return (false);
			if (ft_strchr("01CEP", game->map[y][x]) == NULL)
				return (false);
		}
		if (x != game->map_width)
			return (false);
	}
	return (check_objects(game, -1, -1));
}
