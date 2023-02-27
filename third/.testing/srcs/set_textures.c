/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarollan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:43:45 by rarollan          #+#    #+#             */
/*   Updated: 2022/08/30 16:43:46 by rarollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_char(int keycode, t_map *map)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_back, map->p_x * 70, map->p_y * 70);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_front, map->p_x * 70, map->p_y * 70);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_left, map->p_x * 70, map->p_y * 70);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->char_right, map->p_x * 70, map->p_y * 70);
}

void	set_ground(t_map *map, int y, int x)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->ground, x * 70, y * 70);
	map->map_tab[map->p_y][map->p_x] = '0';
}

void	check_item(t_map *map, int y, int x)
{
	if (map->map_tab[y][x] == 'C')
		map->get_c++;
}

int	check_exit(t_map *map, int y, int x)
{
	if (map->map_tab[y][x] == 'E')
	{
		if (map->nb_c == map->get_c)
		{
			printf("\nCongratulations, you won !\n\n");
			close_game(map);
		}
		else
		{
			printf("Collectibles left !\n");
			return (1);
		}
	}
	return (0);
}
