#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# include "mlx.h"
# include "libft.h"
# include "constant.h"
# include "struct.h"

/*
** FILE - error.c
*/

int		error_char(t_map *map);
int		error_form(t_map *map, int len);
int		error_input(t_map *map);
int		error_wall(t_map *map, int len);
int		ft_error(t_map *map);

/*
** FILE - init_game.c
*/

void	load_img(t_map *map);
void	set_img(t_map *map);
void	set_items(t_map *map, t_pos pos);
void	ft_init_game(t_map *map);

/*
** FILE - set_textures.c
*/

int		check_exit(t_map *map, int y, int x);
void	set_char(int keycode, t_map *map);
void	set_ground(t_map *map, int y, int x);
void	check_item(t_map *map, int y, int x);

/*
** FILE - parsing.c
*/

char	*ft_strjoin_so_long(char *s1, char *s2);
char	**ft_set_map(int fd, t_map *map);
int		ft_strlen_so_long(char *str);
void	ft_read_map(int fd, t_map *map);
void	ft_get_map_stat(t_map *map);

/*
** FILE - move.c
*/

int		key_hook(int keycode, t_map *map);
void	move_a(int keycode, t_map *map);
void	move_d(int keycode, t_map *map);
void	move_s(int keycode, t_map *map);
void	move_w(int keycode, t_map *map);

/*
** FILE - utils.c
*/

int		close_game(t_map *map);
void	destroy_image(t_map *map);
void	free_map_tab(t_map *map);
void	ft_game(t_map *map);

#endif
