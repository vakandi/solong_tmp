#include "so_long.h"

//A revoir
int	ft_strlen_so_long(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin_so_long(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	size = (ft_strlen_so_long(s1) + ft_strlen_so_long(s2));
	tab = malloc(sizeof(char) * size + 2);
	if (tab == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		tab[i] = *s2;
		i++;
		s2++;
	}
	tab[size] = '/';
	tab[size + 1] = '\0';
	if (s1)
		free(s1);
	return (tab);
}

void	ft_read_map(int fd, t_map *map)
{
	char	*line;
	char	*map_line;

	line = NULL;
	map_line = NULL;
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_line = ft_strjoin_so_long(map_line, line);
		free(line);
	}
	map->map_tab = ft_split(map_line, '/');
	free(map_line);
}

void	ft_get_map_stat(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->height = 0;
	map->width = ft_strlen_so_long(map->map_tab[y]);
	map->nb_c = 0;
	map->nb_p = 0;
	map->nb_e = 0;
	while (map->map_tab[y])
	{
		x = 0;
		while (map->map_tab[y][++x])
		{
			if (map->map_tab[y][x] == 'C')
				map->nb_c++;
			else if (map->map_tab[y][x] == 'P')
				map->nb_p++;
			else if (map->map_tab[y][x] == 'E')
				map->nb_e++;
		}
		map->height++;
		y++;
	}
}

char	**ft_set_map(int fd, t_map *map)
{
	ft_read_map(fd, map);
	close(fd);
	ft_get_map_stat(map);
	if (ft_error(map) == 0)
		return (NULL);
	return (map->map_tab);
}
