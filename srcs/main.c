/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:38 by mberne            #+#    #+#             */
/*   Updated: 2021/08/25 11:50:45 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	take_arguments(t_struct *s, int ac, char **av)
{
	if (ac != 5)
		exit(EXIT_FAILURE);
	s->fd_infile = open(av[1], O_RDONLY);
	if (s->fd_infile == -1)
		ft_exit(s, "open");
	s->fd_outfile = open(av[4], O_WRONLY);
	if (s->fd_outfile == -1)
		ft_exit(s, "open");
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
		ft_exit(&s, "fork");
	else if (pid == 0)
		son_fork(&s, pipefd);
	else
	{
		dad_fork(&s, pipefd);
		wait(NULL);
	}
	close(s.fd_infile);
	close(s.fd_outfile);
	free_tab(s.paths);
	return (EXIT_SUCCESS);
}
