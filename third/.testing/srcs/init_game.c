#include "so_long.h"

void	load_img(t_map *map)
{
	int		img_width;
	int		img_height;

	map->char_back = mlx_xpm_file_to_image
		(map->mlx, "img/char_back.xpm", &img_width, &img_height);
	map->char_front = mlx_xpm_file_to_image
		(map->mlx, "img/char_front.xpm", &img_width, &img_height);
	map->char_left = mlx_xpm_file_to_image
		(map->mlx, "img/char_left.xpm", &img_width, &img_height);
	map->char_right = mlx_xpm_file_to_image
		(map->mlx, "img/char_right.xpm", &img_width, &img_height);
	map->wall = mlx_xpm_file_to_image
		(map->mlx, "img/wall.xpm", &img_width, &img_height);
	map->ground = mlx_xpm_file_to_image
		(map->mlx, "img/ground.xpm", &img_width, &img_height);
	map->exit = mlx_xpm_file_to_image
		(map->mlx, "img/exit.xpm", &img_width, &img_height);
	map->coin = mlx_xpm_file_to_image
		(map->mlx, "img/coin.xpm", &img_width, &img_height);
}

void	set_items(t_map *map, t_pos pos)
{
	if (map->map_tab[pos.y][pos.x] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->coin, pos.x * 70, pos.y * 70);
	else if (map->map_tab[pos.y][pos.x] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->exit, pos.x * 70, pos.y * 70);
	else if (map->map_tab[pos.y][pos.x] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_right, pos.x * 70, pos.y * 70);
		map->p_x = pos.x;
		map->p_y = pos.y;
	}
}

void	set_img(t_map *map)
{
	t_pos	pos;

	pos.y = 0;
	while (map->map_tab[pos.y])
	{
		pos.x = 0;
		while (map->map_tab[pos.y][pos.x])
		{
			if (map->map_tab[pos.y][pos.x] == '1')
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->wall, pos.x * 70, pos.y * 70);
			else
			{
				mlx_put_image_to_window(map->mlx, map->mlx_win,
					map->ground, pos.x * 70, pos.y * 70);
				set_items(map, pos);
			}
			pos.x++;
		}
		pos.y++;
	}
}

void	ft_init_game(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		free(map->mlx);
		return ;
	}
	map->mlx_win = mlx_new_window(map->mlx, (map->width * 70),
			(map->height * 70), "so_long");
	load_img(map);
	set_img(map);
	ft_game(map);
	mlx_loop(map->mlx);
}
