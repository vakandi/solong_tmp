/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarollan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:42:10 by rarollan          #+#    #+#             */
/*   Updated: 2022/08/30 16:42:12 by rarollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	void	*char_back;
	void	*char_front;
	void	*char_left;
	void	*char_right;
	void	*wall;
	void	*ground;
	void	*exit;
	void	*coin;
	char	**map_tab;
	int		width;
	int		height;
	int		nb_c;
	int		get_c;
	int		nb_p;
	int		p_x;
	int		p_y;
	int		nb_e;
	int		nb_move;
}		t_map;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

#endif
