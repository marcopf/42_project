/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:11:12 by marco             #+#    #+#             */
/*   Updated: 2023/04/22 22:11:30 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

void	pipex_init(t_pipex *pipex, char **argv, int argc)
{
	if (check_here_doc(pipex, argv, argc))
	{
		pipex->val = 4;
		pipex->out_mode = 1;
		pipex->outfile_fd = open(argv[argc - 1],
				O_WRONLY | O_APPEND | O_CREAT, 0644);
	}
	else if (!access(argv[1], F_OK))
	{
		pipex->old_pipe = open(argv[1], O_RDWR);
		if (pipex->old_pipe < 0)
			exit(1);
	}
	else
	{
		fd_printf(2, "%s: ", argv[1]);
		perror("");
		exit(1);
	}
	pipex->n_cmd = argc - pipex->val;
	if (!pipex->out_mode)
		pipex->outfile_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (pipex->outfile_fd < 0)
		exit(1);
}
