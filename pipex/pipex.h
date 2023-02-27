/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:31:49 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/24 10:15:34 by mpaterno         ###   ########.fr       */
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
# include <fcntl.h>
# include <stdio.h>

typedef struct e_pipex{
	int		pipe_fd[2];
	int		infile_fd;
	int		outfile_fd;
	int		pid1;
	int		pid2;
	char	**cmd1;
	char	**cmd2;
	int		cmd_i;
	char	**paths;

}	t_pipex;

void	free_cmd_n_file(t_pipex *pipex);
void	ft_free(char **strs);
char	**path_n_command(t_pipex *pipex, char **argv, int el, char **envp);
char	**get_line(char **envp);
void	command_init(t_pipex *pipex, char **argv, char **envp);
void	r_trim(t_pipex *pipex);
void	convert(char **strs);
void	protect_space(char *strs);

#endif