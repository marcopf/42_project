/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:06:26 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/09 20:26:33 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct e_charizard{
	void	*c1;
	void	*c2;
	void	*c3;
	void	*c4;
	void	*c5;
	void	*c6;
	void	*a1;
	void	*a2;
	void	*a3;
	void	*a4;
	int		x;
	int		y;
}	t_char;

typedef struct s_image {
	void	*floor;
	void	*border;
	void	*item;
	void	*open_door;
	void	*player;
	void	*c_door;
	void	*patrol;
	void	*e3;
	int		offset_x;
	int		offset_y;
	int		img_width;
	int		img_height;

}	t_imgs;

typedef struct e_player{
	void	*top;
	void	*bottom;
	void	*left;
	void	*right;
	int		x;
	int		y;
	int		moves;
	int		collectibles;
}	t_player;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct e_game {
	void		*mlx;
	void		*mlx_win;
	t_imgs		imgs;
	t_player	player;
	t_char		charizard;
	char		**map;
	int			frame;
	int			moves;
	int			img_width;
	int			img_height;
	int			done;
	int			door_x;
	int			door_y;
	t_data		img;

}	t_game;

#endif
