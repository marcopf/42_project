/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_n_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaterno <mpaterno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:41:00 by marco             #+#    #+#             */
/*   Updated: 2023/02/24 10:14:45 by mpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_line(char **envp)
{
	int		i;
	int		flag;
	char	**ret;

	flag = 0;
	i = -1;
	ret = 0;
	while (envp[++i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			flag = 1;
			break ;
		}
	}
	if (flag)
		ret = ft_split((envp[i] + 5), ':');
	return (ret);
}

char	*path_checker(t_pipex *pipex)
{
	int	flag;
	int	i;

	flag = 0;
	i = -1;
	while (pipex->paths[++i] != 0)
	{
		if (!access(pipex->paths[i], 0))
		{
			flag = 1;
			break ;
		}	
	}
	if (flag)
		return (pipex->paths[i]);
	else
		ft_printf("%s: comando non trovato\n",
			ft_strrchr(pipex->paths[0], '/') + 1);
	return (0);
}

char	**path_n_command(t_pipex *pipex, char **argv, int el, char **envp)
{
	char	*temp;
	char	**command;

	pipex->paths = get_line(envp);
	pipex->cmd_i = -1;
	command = ft_split(argv[el], ' ');
	while (pipex->paths[++pipex->cmd_i])
	{
		temp = ft_strdup(pipex->paths[pipex->cmd_i]);
		free(pipex->paths[pipex->cmd_i]);
		pipex->paths[pipex->cmd_i] = ft_strjoin(temp, "/");
		free(temp);
		temp = ft_strdup(pipex->paths[pipex->cmd_i]);
		free(pipex->paths[pipex->cmd_i]);
		pipex->paths[pipex->cmd_i] = ft_strjoin(temp, command[0]);
		free(temp);
	}
	free(command[0]);
	temp = path_checker(pipex);
	if (!temp)
		command[0] = 0;
	else
		command[0] = ft_strdup(temp);
	ft_free(pipex->paths);
	return (command);
}

void	command_init(t_pipex *pipex, char **argv, char **envp)
{
	protect_space(argv[2]);
	protect_space(argv[3]);
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd <= 0)
	{
		ft_printf("%s: %s: file o directory inesistente\n", argv[1], argv[2]);
		exit(1);
	}
	pipex->outfile_fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR);
	pipex->cmd1 = path_n_command(pipex, argv, 2, envp);
	pipex->cmd2 = path_n_command(pipex, argv, 3, envp);
	convert(pipex->cmd1);
	convert(pipex->cmd2);
	r_trim(pipex);
}
