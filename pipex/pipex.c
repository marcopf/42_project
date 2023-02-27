/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:31:08 by mpaterno          #+#    #+#             */
/*   Updated: 2023/02/24 10:25:02 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	sub_proc(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		return (-1);
	if (pipex->pid1 == 0)
	{
		close(pipex->pipe_fd[0]);
		dup2(pipex->pipe_fd[1], 1);
		dup2(pipex->infile_fd, 0);
		execve(pipex->cmd1[0], pipex->cmd1, NULL);
	}
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		return (-1);
	if (pipex->pid2 == 0)
	{
		dup2(pipex->pipe_fd[0], 0);
		dup2(pipex->outfile_fd, 1);
		close(pipex->pipe_fd[1]);
		execve(pipex->cmd2[0], pipex->cmd2, NULL);
	}
	return (1);
}

void	protect_space(char *strs)
{
	char	*str;
	int		i;

	str = ft_strchr(strs, '\'');
	if (str)
	{
		i += 1;
		while (str[++i] && str[i] != '\'')
			if (str[i] == ' ')
				str[i] = '#';
	}
}

void	convert(char **strs)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	while (strs[++i])
	{
		if (ft_strchr(strs[i], '#'))
		{
			str = ft_strchr(strs[i], '#');
			j = -1;
			while (str[++j] && str[j] != '\'')
			{
				if (str[j] == '#')
					str[j] = ' ';
			}
		}
	}
}

void	r_trim(t_pipex *pipex)
{
	int		i;
	char	*temp;

	i = -1;
	while (pipex->cmd1[++i])
	{
		if (ft_strchr(pipex->cmd1[i], '\''))
		{
			temp = ft_strtrim(pipex->cmd1[i], "\'");
			free(pipex->cmd1[i]);
			pipex->cmd1[i] = ft_strdup(temp);
			free(temp);
		}
	}
	i = -1;
	while (pipex->cmd2[++i])
	{
		if (ft_strchr(pipex->cmd2[i], '\''))
		{
			temp = ft_strtrim(pipex->cmd2[i], "\'");
			free(pipex->cmd2[i]);
			pipex->cmd2[i] = ft_strdup(temp);
			free(temp);
		}
	}	
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	char	*temp;

	if (argc < 5)
		return (0);
	if (pipe(pipex.pipe_fd) == -1)
		return (1);
	command_init(&pipex, argv, envp);
	if (sub_proc(&pipex) < 0)
		return (1);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_cmd_n_file(&pipex);
}
