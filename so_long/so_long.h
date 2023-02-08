/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:44:46 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/08 11:14:25 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "structs.h"
# include <time.h>
# include <stdarg.h>
# include "libftprintf.h"

char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
char	*get_next_line(int fd);
int		counter(char *path);
char	**map_maker(char *path);
void	free_map(char **strs);
int		is_rect(char **map);
int		get_y(char **strs);
int		border_wall(char **map);
int		is_valid_map(char **map);
void	draw_map(t_game *game);
void	img_init(t_game *game);
void	free_map(char **strs);
int		key_hook(int key, t_game *game);
void	locate_player(t_game *game);
void	collectibles_setter(t_game *game);
int		can_we_get_out(char **map);
void	finish_game(t_game *game);
int		move_charizard(t_game *game);
int		locate_charizard(t_game *game);
int		create_trgb(int t, int r, int g, int b);
void	win_game(t_game *game);
void	game_over(t_game *game);
int		locate_door(t_game *game);
void	print_moves(t_game *game);
void	smart_move(t_game *game);
int		move_char_up(t_game *game);
int		move_char_down(t_game *game);
int		move_char_left(t_game *game);
int		move_char_right(t_game *game);
//ft_printf
int		ft_printf(const char *str, ...);
char	*ft_itoa(long n);
int		ft_putnbr(int n);
int		ft_u_putnbr(unsigned int n);
int		ft_num_len(long num);
int		ft_hex_len(unsigned	long long num);
int		ft_putchar(int c);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t m, size_t dim);
void	ft_bzero(void *s, size_t n);
int		ft_putstr(const char *str);
int		c_write(int fd, const void *c, int n);
int		write_ptr(unsigned long long int n);
int		hex(unsigned int n, int switcher);
int		ft_u_putnbr(unsigned int n);
int		get_specifier(const char *str, va_list *args);

#endif
