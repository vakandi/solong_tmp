#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	int		fd;

	if (ac != 2)
	{
		printf("Error Invalid arguments");
		return (1);
	}
	if (!ft_test_file(av[1]))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		printf("Error Failed to open file");
		return (0);
	}
	if (!ft_set_map(fd, &map))
	{
		free_map_tab(&map);
		return (1);
	}
	ft_init_game(&map);
	return (0);
}
