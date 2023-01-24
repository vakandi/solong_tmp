#include "../so_long.h"

/*
**	Checks if all symbols
**	in the map are valid
**	Returns 0 if not
*/
int	ft_aux_check_map_file(t_game_map *game_map)
{
	int		counter;
	int		inner_counter;
	char	*line;

	counter = 0;
	inner_counter = 0;
	while (counter <= game_map->map_height)
	{
		inner_counter = 0;
		line = game_map->map_data[counter];
		while (line[inner_counter])
		{
			if (!ft_inset(line[inner_counter], (const char *) "01CEP"))
				return (0);
			inner_counter++;
		}
		counter++;
	}
	return (1);
}
