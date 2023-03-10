#include "so_long.h"

void	free_map_tab(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_tab[i])
	{
		free(map->map_tab[i]);
		i++;
	}
	free(map->map_tab);
}

void	destroy_image(t_map *map)
{
	mlx_destroy_image(map->mlx, map->char_back);
	mlx_destroy_image(map->mlx, map->char_front);
	mlx_destroy_image(map->mlx, map->char_left);
	mlx_destroy_image(map->mlx, map->char_right);
	mlx_destroy_image(map->mlx, map->coin);
	mlx_destroy_image(map->mlx, map->wall);
	mlx_destroy_image(map->mlx, map->ground);
	mlx_destroy_image(map->mlx, map->exit);
}

int	close_game(t_map *map)
{
	free_map_tab(map);
	destroy_image(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit (0);
}

void	ft_game(t_map *map)
{
	map->nb_move = 0;
	map->get_c = 0;
	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, close_game, map);
}
