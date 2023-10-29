/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 00:04:36 by bbosnak           #+#    #+#             */
/*   Updated: 2023/10/03 00:04:38 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SIZE 50

# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"

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
	int		*player_addr;
	void	*wall;
	int		*wall_addr;
	void	*exit;
	int		*exit_addr;
	void	*coin;
	int		*coin_addr;
	void	*bg;
	int		*bg_addr;
}	t_imgs;

typedef struct s_img
{
	void	*img;
	int		*addr;
}	t_img;

typedef struct s_vmap
{
	char	**map;
	int		coins;
	bool	player;
}	t_vmap;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	int			obj_count;
	int			player_speed;
	int			coin_count;
	int			total_movement;
	bool		collisions;
	t_imgs		imgs;
	t_keys		keys;
	t_object	*all_objects;
	t_object	player;
	t_img		img;
	t_vmap		vmap;
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
void	print_collisions(t_game *game, int x, int y);
bool	collision_controller(t_game *game);
void	print_map(t_game *game, int x, int y);
void	print_obj(t_game *game, t_object *object);
void	print_background(t_game *game, int x, int y);
void	sprite_to_addr(t_game *game, t_object *obj, int *addr);
bool	check_map(t_game *game, int x, int y);
void	create_objs(t_game *game, int x, int y);
void	*ft_calloc(size_t count, size_t size);
int		exit_game(t_game *game);
void	free_double_array(char **array);

#endif
