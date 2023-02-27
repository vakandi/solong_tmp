/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarollan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:43:12 by rarollan          #+#    #+#             */
/*   Updated: 2022/08/30 16:43:14 by rarollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	int		fd;

	if (ac != 2)
	{
		printf("Error\nInvalid arguments\n");
		return (1);
	}
	if (!ft_test_file(av[1]))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		printf("Error\nFailed to open file\n");
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
