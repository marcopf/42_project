/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 08:58:42 by marco             #+#    #+#             */
/*   Updated: 2023/04/22 22:14:50 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(t_pipex *pipex, int *fd, int id)
{
	if (id - (pipex->val - 1) != pipex->n_cmd - 1)
	{
		close(pipex->old_pipe);
		pipex->old_pipe = fd[0];
		close(fd[1]);
	}
	else
	{
		close(pipex->old_pipe);
		while (waitpid(-1, 0, 0) != -1)
			;
	}
}

int	child_proc(t_pipex *pipex, char **argv, int id, char **envp)
{
	int		pid;
	int		fd[2];
	char	**cmd;

	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (!pid)
	{
		if (id - (pipex->val - 1) != pipex->n_cmd - 1)
			dup2(fd[1], 1);
		else
			dup2(pipex->outfile_fd, 1);
		close(fd[1]);
		close(fd[0]);
		dup2(pipex->old_pipe, 0);
		close(pipex->old_pipe);
		cmd = get_cmd(pipex, argv, id, envp);
		execve(cmd[0], cmd, envp);
	}
	else
		parent(pipex, fd, id);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	if (argc < 5)
		return (fd_printf(2, "to few arguments\n"));
	pipex.val = 3;
	pipex.out_mode = 0;
	pipex_init(&pipex, argv, argc);
	i = -1;
	while (++i < pipex.n_cmd)
		child_proc(&pipex, argv, i + pipex.val - 1, envp);
	unlink(".here_doc");
	return (0);
}
