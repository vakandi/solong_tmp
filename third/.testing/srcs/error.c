#include "so_long.h"

int	error_char(t_map *map)
{
	int		i;
	int		j;
	char	c;

	c = 0;
	i = 0;
	while (map->map_tab[i])
	{
		j = 0;
		while (map->map_tab[i][j])
		{
			if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_input(t_map *map)
{
	if (map->nb_c == 0)
	{
		printf("Error Map must have at least one collectible");
		return (0);
	}
	else if (map->nb_e == 0)
	{
		printf("Error Map must have at least one exit");
		return (0);
	}
	else if (map->nb_p != 1)
	{
		printf("Error Map must have one starting position");
		return (0);
	}
	return (1);
}

int	error_form(t_map *map, int len)
{
	int	i;

	i = 0;
	while (map->map_tab[i])
	{
		if (len != ft_strlen(map->map_tab[i]) - 1)
		{
			printf("ErrorMap must be a rectangle");
			return (0);
		}
		i++;
	}
	return (1);
}

int	error_wall(t_map *map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_tab[i][j])
	{
		if (map->map_tab[i][j++] != '1')
			return (0);
	}
	i++;
	while (map->map_tab[i])
	{
		if (map->map_tab[i][0] != '1' || map->map_tab[i][len] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map->map_tab[i - 1][j])
	{
		if (map->map_tab[i - 1][j++] != '1')
			return (0);
	}
	return (1);
}

int	ft_error(t_map *map)
{
	int	len;

	len = ft_strlen_so_long(map->map_tab[0]) - 1;
	if (!error_char(map))
	{
		printf("Error Invalid character on map");
		return (0);
	}
	if (!error_form(map, len)
		|| !error_input(map))
		return (0);
	else if (!error_wall(map, len))
	{
		printf("Error Map not closed");
		return (0);
	}
	return (1);
}
