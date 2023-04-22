/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:41:00 by marco             #+#    #+#             */
/*   Updated: 2023/04/22 21:47:27 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

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
		fd_printf(2, "%s: command not found\n",
			ft_strrchr(pipex->paths[0], '/') + 1);
	return (0);
}

char	**get_cmd(t_pipex *pipex, char **argv, int el, char **envp)
{
	char	*temp;
	char	**command;

	pipex->paths = get_line(envp);
	pipex->cmd_i = -1;
	command = final_parser(argv[el]);
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
	ft_free_mat((void ***)&pipex->paths);
	return (command);
}
