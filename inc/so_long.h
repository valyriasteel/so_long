#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# include "../mlx/mlx.h"

#define SIZE 50

typedef struct s_object
{
	int		x;
	int		y;
	int		width;
	int		height;
	char	type;
	bool	is_active;
}	t_object;

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
}	t_keys;

typedef struct s_imgs
{
	void	*player;
	void	*wall;
	void	*exit;
	void	*coin;
	void	*bg;
}	t_imgs;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	int			obj_count;
	int			player_speed;
	t_imgs		imgs;
	t_keys		keys;
	t_object	*all_objects;
	t_object	player;
}	t_game;

int		ft_strlen(char *str);
char	**ft_split(char *str, char c);
void	init(t_game *game, int width, int height);
bool	read_map(t_game *game, char *map_path);
char	*ft_strchr(char *str, char c);
int		key_down(int code, t_game *game);
int		key_up(int code, t_game *game);
int		ft_arrlen(char **arrays);
int		update(t_game *game);

#endif