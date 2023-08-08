#include "../inc/so_long.h"

void	print_m(t_game *game) // kaldirilacak
{
	for (int i = 0; game->map[i]; i++)
	{
		printf("%s\n", game->map[i]);
	}
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		idx;
	char	*res;

	i = -1;
	idx = -1;
	res = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	while (str1 && str1[++i])
		res[++idx] = str1[i];
	i = -1;
	while (str2 && str2[++i])
		res[++idx] = str2[i];
	res[++idx] = '\0';
	if (str1)
		free(str1);
	return (res);
}

bool	create_objs(t_game *game, int x, int y)
{
	int	idx;

	idx = 0;
	game->all_objects = malloc(sizeof(t_object) * game->obj_count);
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (ft_strchr("1EC", game->map[y][x]) != NULL)
			{
				game->all_objects[idx].x = x * SIZE;
				game->all_objects[idx].y = y * SIZE;
				game->all_objects[idx].width = 50;
				game->all_objects[idx].height = 50;
				game->all_objects[idx].is_active = true;
				game->all_objects[idx++].type = game->map[y][x];
			}
			if (game->map[y][x] == 'P')
			{
				game->player.x = x * SIZE;
				game->player.y = y * SIZE;
				game->player.width = 50;
				game->player.height = 50;
				game->player.type = 'P';
			}
		}
	}
	return(true);
}

bool	read_map(t_game *game, char *map_path)
{
	int		fd;
	char	*map;
	char 	buff[2];

	map = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (false);
	while (read(fd, buff, 1) > 0)
	{
		map = ft_strjoin(map, buff);
		if (ft_strchr("1EC", buff[0]) != NULL)
			game->obj_count++;
	}
	game->map = ft_split(map, '\n');
	game->map_width = ft_strlen(game->map[0]);
	game->map_height = ft_arrlen(game->map);
	free(map);
	close(fd);
	return (create_objs(game, 0, -1));
}
