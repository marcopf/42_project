/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:54:44 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/08 12:15:24 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_rect(int x, int y, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			my_mlx_pixel_put(&game->img, j, i, 0x00000000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
}

void	test(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, 400, 30);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	draw_rect(400, 30, game);
}

void	print_moves(t_game *game)
{
	char	*str;
	char	*temp;

	test(game);
	temp = ft_itoa(game->player.moves);
	str = ft_strjoin(ft_strdup("mosse: "), temp);
	mlx_string_put(game->mlx, game->mlx_win, 20, 10,
		create_trgb(255, 255, 255, 255), str);
	free(temp);
	free(str);
}

void	smart_move(t_game *game)
{
	if (!locate_charizard(game))
		return ;
	locate_player(game);
	if (game->player.y > game->charizard.y)
		move_char_down(game);
	else if (game->player.y < game->charizard.y)
		move_char_up(game);
	else if (game->player.x > game->charizard.x)
		move_char_right(game);
	else if (game->player.x < game->charizard.x)
		move_char_left(game);
}
