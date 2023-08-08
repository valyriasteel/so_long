#include "../inc/so_long.h"

int main(int ac, char **av)
{
	t_game	game;

	game.obj_count = 0;
	if (ac != 2 || read_map(&game, av[1]) == false)
	{
		printf("Read map error\n");
		return (1);
	}
	init(&game, ft_strlen(game.map[0]) * SIZE, ft_arrlen(game.map) * SIZE);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_loop(game.mlx);
}
