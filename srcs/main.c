/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:38 by mberne            #+#    #+#             */
/*   Updated: 2021/10/04 17:53:12 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	take_arguments(t_struct *s, int ac, char **av)
{
	ft_bzero(s, sizeof(t_struct));
	if (ac < 5)
		exit(EXIT_FAILURE);
	s->num_pipes = ac - 3;
	s->fd_infile = open(av[1], O_RDONLY);
	s->fd_outfile = open(av[ac - 1], O_WRONLY | O_TRUNC);
	if (s->fd_infile == -1 || s->fd_outfile == -1)
		ft_exit(s, "open", EXIT_FAILURE);
}

int	main(int ac, char **av, char **envp)
{
	t_struct	s;
	pid_t		pid;
	int			pipefd[2];

	take_arguments(&s, ac, av);
	find_commands_paths(&s, envp);
	find_good_path(&s, av);
	if (pipe(pipefd) == 1)
		ft_exit(&s, "pipe", EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_exit(&s, "fork", EXIT_FAILURE);
	else if (pid == 0)
		first_son_fork(&s, pipefd, av);
	else
	{
		// wait(NULL);
		dad_fork(&s, pipefd, av);
	}
	if (close(pipefd[0]) == -1 || close(pipefd[1]) == -1)
		ft_exit(&s, "close", EXIT_FAILURE);
	if (close(s.fd_infile) == -1 || close(s.fd_outfile) == -1)
		ft_exit(&s, "close", EXIT_FAILURE);
	ft_exit(&s, "", EXIT_SUCCESS);
}
