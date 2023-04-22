/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:31:49 by mpaterno          #+#    #+#             */
/*   Updated: 2023/04/22 22:16:07 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "ft_printf/libftprintf.h"
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct e_pipex{
	int		pipe_fd[2];
	int		n_cmd;
	int		val;
	int		old_pipe;
	int		out_mode;
	int		outfile_fd;
	int		cmd_i;
	char	**paths;

}	t_pipex;

void	pipex_init(t_pipex *pipex, char **argv, int argc);
int		check_here_doc(t_pipex *pipex, char **argv, int argc);
int		fd_printf(int fd, const char *str, ...);
char	*get_next_line(int fd);
char	*gnl_join(const char *s1, const char *s2);
char	**final_parser(char *str);
int		prepare_strs(char **strs);
char	**line_filter(char **strs);
void	*ft_realloc(void *p, size_t size, int dim, int new_dim);
int		ft_quotes_check(char *line, int	*i);
int		ft_checks(char *line, int *i);
int		ft_end_op(char *line, char **parsed);
char	**ft_extract_word(char **parsed, int *dim, int *i, char **line);
int		ft_in(char c, char *set);
int		ft_strlen_until(char *str, char *set);
void	ft_free(void **ptr_addr);
void	ft_free_mat(void ***ptr_addr);
char	**ft_parser(char *line, char *set);
void	free_cmd_n_file(t_pipex *pipex);
char	**get_cmd(t_pipex *pipex, char **argv, int el, char **envp);
char	**get_line(char **envp);
void	command_init(t_pipex *pipex, char **argv, char **envp);
void	r_trim(t_pipex *pipex);
void	convert(char **strs);
void	protect_space(char *strs);

#endif