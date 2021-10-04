/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:45 by mberne            #+#    #+#             */
/*   Updated: 2021/10/04 16:16:14 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_son_fork(t_struct *s, int pipefd[2], char **av)
{
	char	**cmd;

	if (close(pipefd[1]) == -1)
		ft_exit(s, "close", EXIT_FAILURE);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		ft_exit(s, "dup2", EXIT_FAILURE);
	if (dup2(s->fd_outfile, STDOUT_FILENO) == -1)
		ft_exit(s, "dup2", EXIT_FAILURE);
	if (close(pipefd[0]) == -1)
		ft_exit(s, "close", EXIT_FAILURE);
	cmd = ft_split(av[3], ' ');
	if (!cmd)
		ft_exit(s, "malloc", EXIT_FAILURE);
	if (execve(s->cmd_path[1], cmd, NULL) == -1)
		ft_exit(s, "execve", EXIT_FAILURE);
}

void	first_son_fork(t_struct *s, int pipefd[2], char **av)
{
	char	**cmd;

	if (close(pipefd[0]) == -1)
		ft_exit(s, "close", EXIT_FAILURE);
	if (dup2(s->fd_infile, STDIN_FILENO) == -1)
		ft_exit(s, "dup2", EXIT_FAILURE);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		ft_exit(s, "dup2", EXIT_FAILURE);
	if (close(pipefd[1]) == -1)
		ft_exit(s, "close", EXIT_FAILURE);
	cmd = ft_split(av[2], ' ');
	if (!cmd)
		ft_exit(s, "malloc", EXIT_FAILURE);
	if (execve(s->cmd_path[0], cmd, NULL) == -1)
		ft_exit(s, "execve", EXIT_FAILURE);
}

void	dad_fork(t_struct *s, int pipefd[2], char **av)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit(s, "fork", EXIT_FAILURE);
	else if (pid == 0)
		second_son_fork(s, pipefd, av);
	else
		wait(NULL);
}
