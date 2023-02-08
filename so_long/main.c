/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:41:44 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/08 14:07:35 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame_setter(t_game *game)
{
	static int	frame;

	usleep(9300);
	if (frame == 60)
		frame = 0;
	frame++;
	game->frame = frame;
}

int	destroy(t_game *game)
{
	free_map(game->map);
	exit(0);
}

void	animate_charizard(t_game *game)
{
	if (!locate_charizard(game))
		return ;
	if (game->frame > 50)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->imgs.floor, (game->charizard.x) * 61,
			((game->charizard.y) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.patrol_a, (game->charizard.x) * 61,
			((game->charizard.y) * 61) + 30);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->imgs.floor, (game->charizard.x) * 61,
			((game->charizard.y) * 61) + 30);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->charizard.patrol_b, (game->charizard.x) * 61,
			((game->charizard.y) * 61) + 30);
	}
}

int	render(t_game *game)
{
	frame_setter(game);
	animate_charizard(game);
	move_charizard(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 1)
	{
		ft_printf("mi serve la path del file mappa\n");
		return (0);
	}
	srand(time(NULL));
	game.mlx = mlx_init();
	game.map = map_maker(argv[1]);
	game.mlx_win = mlx_new_window(game.mlx, (ft_strlen(game.map[0]) - 1) * 62,
			((get_y(game.map)) * 62) + 10, "so_long");
	img_init(&game);
	draw_map(&game);
	print_moves(&game);
	mlx_hook(game.mlx_win, 2, 0, key_hook, (void *)&game);
	mlx_hook(game.mlx_win, 17, 0, destroy, (void *)&game);
	mlx_loop_hook(game.mlx, render, (void *)&game);
	mlx_loop(game.mlx);
}
