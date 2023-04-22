/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:09:04 by marco             #+#    #+#             */
/*   Updated: 2023/04/22 22:19:54 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../pipex.h"

int	ft_here_doc(char *limiter)
{
	char	*temp;
	int		file;

	file = open(".here_doc",
			O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file == -1)
		exit(1);
	while (42)
	{
		write(1, "heredoc> ", 9);
		temp = get_next_line(0);
		if (!temp || (!ft_strncmp(temp, limiter, ft_strlen(limiter))
				&& ft_strlen(temp) == ft_strlen(limiter) + 1))
			break ;
		write(file, temp, ft_strlen(temp));
		ft_free((void **)&temp);
	}
	ft_free((void **) &temp);
	close(file);
	return (1);
}

int	check_here_doc(t_pipex *pipex, char **argv, int argc)
{
	if (!ft_strncmp("here_doc", argv[1], 8)
		&& ft_strlen(argv[1]) == 8 && argc > 5)
	{
		ft_here_doc(argv[2]);
		pipex->old_pipe = open(".here_doc", O_RDWR);
		if (pipex->old_pipe == -1)
			exit(1);
		return (1);
	}
	return (0);
}
