/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:40:58 by bbosnak           #+#    #+#             */
/*   Updated: 2023/10/03 00:41:00 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	total;

	total = count * size;
	if (size && count > 2147483647 / size)
		return (0);
	dst = (unsigned char *)malloc(total);
	if (!dst)
		return (NULL);
	ft_memset(dst, 0, total);
	return (dst);
}

int	ft_arrlen(char **arrays)
{
	int	i;

	i = 0;
	while (arrays[i])
		i++;
	return (i);
}

int	exit_game(t_game *game)
{
	free_double_array(game->map);
	mlx_destroy_image(game->mlx, game->imgs.player);
	mlx_destroy_image(game->mlx, game->imgs.wall);
	mlx_destroy_image(game->mlx, game->imgs.exit);
	mlx_destroy_image(game->mlx, game->imgs.coin);
	mlx_destroy_image(game->mlx, game->imgs.bg);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->win);
	free(game->all_objects);
	exit(0);
	return (0);
}

void	free_double_array(char **array)
{
	int	i;

	i = -1;
	while (array && array[++i])
		free(array[i]);
	if (array)
		free(array);
}
