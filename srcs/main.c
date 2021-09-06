/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:38 by mberne            #+#    #+#             */
/*   Updated: 2021/09/06 15:38:23 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	take_arguments(t_struct *s, int ac, char **av)
{
	if (ac != 5)
		exit(EXIT_FAILURE);
	s->fd_infile = open(av[1], O_RDONLY);
	if (s->fd_infile == -1)
	{
		ft_exit(s, "open");
		exit(EXIT_FAILURE);
	}
	s->fd_outfile = open(av[4], O_WRONLY | O_TRUNC);
	if (s->fd_outfile == -1)
	{
		ft_exit(s, "open");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_struct	s;
	pid_t		pid;
	int			pipefd[2];

	ft_bzero(&s, sizeof(t_struct));
	take_arguments(&s, ac, av);
	find_commands_paths(&s, envp);
	find_good_path(&s, av);
	if (pipe(pipefd) == 1)
		ft_exit(&s, "pipe");
	pid = fork();
	if (pid == -1)
	{
		ft_exit(&s, "fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		first_son_fork(&s, pipefd, av);
	else
	{
		// wait(NULL);
		dad_fork(&s, pipefd, av);
	}
	if (close(pipefd[0]) == -1 || close(pipefd[1]) == -1)
	{
		ft_exit(&s, "close");
		exit(EXIT_FAILURE);
	}
	if (close(s.fd_infile) == -1 || close(s.fd_outfile) == -1)
	{
		ft_exit(&s, "close");
		exit(EXIT_FAILURE);
	}
	free_tab(s.paths);
	free_tab(s.cmd_path);
	return (EXIT_SUCCESS);
}
