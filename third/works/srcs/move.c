#include "so_long.h"

void	move_w(int keycode, t_map *map)
{
	if (map->map_tab[map->p_y - 1][map->p_x] != '1')
	{
		if (!check_exit(map, map->p_y - 1, map->p_x))
		{
			map->p_y--;
			check_item(map, map->p_y, map->p_x);
			set_ground(map, map->p_y + 1, map->p_x);
			map->nb_move++;
			printf("%d steps\n", map->nb_move);
		}
	}
	set_char(keycode, map);
}

void	move_d(int keycode, t_map *map)
{
	if (map->map_tab[map->p_y][map->p_x + 1] != '1')
	{
		if (!check_exit(map, map->p_y, map->p_x + 1))
		{
			map->p_x++;
			check_item(map, map->p_y, map->p_x);
			set_ground(map, map->p_y, map->p_x - 1);
			map->nb_move++;
			printf("%d steps\n", map->nb_move);
		}
	}
	set_char(keycode, map);
}

void	move_s(int keycode, t_map *map)
{
	if (map->map_tab[map->p_y + 1][map->p_x] != '1')
	{
		if (!check_exit(map, map->p_y + 1, map->p_x))
		{
			map->p_y++;
			check_item(map, map->p_y, map->p_x);
			set_ground(map, map->p_y - 1, map->p_x);
			map->nb_move++;
			printf("%d steps\n", map->nb_move);
		}
	}
	set_char(keycode, map);
}

void	move_a(int keycode, t_map *map)
{
	if (map->map_tab[map->p_y][map->p_x - 1] != '1')
	{
		if (!check_exit(map, map->p_y, map->p_x - 1))
		{
			map->p_x--;
			check_item(map, map->p_y, map->p_x);
			set_ground(map, map->p_y, map->p_x + 1);
			map->nb_move++;
			printf("%d steps\n", map->nb_move);
		}
	}
	set_char(keycode, map);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == KEY_ESC)
		close_game(map);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_w(keycode, map);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_d(keycode, map);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_s(keycode, map);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_a(keycode, map);
	return (0);
}
