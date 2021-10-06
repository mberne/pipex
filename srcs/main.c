/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:38 by mberne            #+#    #+#             */
/*   Updated: 2021/10/06 15:13:14 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(t_struct *s, char *error, int exit_status)
{
	free_tab(s->paths, 0);
	free_tab(s->cmd, s->num_cmd);
	free_tab(s->cmd_path, s->num_cmd);
	free(s->pid);
	if (exit_status == EXIT_FAILURE)
		perror(error);
	exit(exit_status);
}

pid_t	launch_command(t_struct *s, int in, int out, int i)
{
	char	**cmd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit(s, "fork", EXIT_FAILURE);
	else if (pid == 0)
	{
		if (in != 0 && dup2(in, STDIN_FILENO) == -1)
			ft_exit(s, "dup2", EXIT_FAILURE);
		if (out != 1 && dup2(out, STDOUT_FILENO) == -1)
			ft_exit(s, "dup2", EXIT_FAILURE);
		if (close(in) == -1 || close(out) == -1)
			ft_exit(s, "close", EXIT_FAILURE);
		cmd = ft_split(s->cmd[i], ' ');
		if (!cmd)
			ft_exit(s, "malloc", EXIT_FAILURE);
		if (execve(s->cmd_path[i], cmd, NULL) == -1)
			ft_exit(s, "execve", EXIT_FAILURE);
	}
	if (close(in) == -1 || close(out) == -1)
		ft_exit(s, "close", EXIT_FAILURE);
	return (pid);
}

void	pipex(t_struct *s)
{
	int			pipefd[2];
	int			in;
	int			i;

	in = s->fd_infile;
	i = 0;
	while (i < s->num_cmd - 1)
	{
		if (pipe(pipefd) == -1)
			ft_exit(s, "pipe", EXIT_FAILURE);
		s->pid[i] = launch_command(s, in, pipefd[WRITE], i);
		in = pipefd[READ];
		i++;
	}
	s->pid[i] = launch_command(s, in, s->fd_outfile, i);
	i = 0;
	while (i < s->num_cmd)
	{
		waitpid(s->pid[i], NULL, 1);
		i++;
	}
}

void	take_arguments(t_struct *s, int ac, char **av)
{
	int	i;

	ft_bzero(s, sizeof(t_struct));
	if (ac < 5)
		exit(EXIT_FAILURE);
	s->num_cmd = ac - 3;
	s->fd_infile = open(av[1], O_RDONLY);
	s->fd_outfile = open(av[ac - 1], O_WRONLY | O_TRUNC);
	if (s->fd_infile == -1 || s->fd_outfile == -1)
		ft_exit(s, "open", EXIT_FAILURE);
	s->cmd = malloc(sizeof(char *) * (s->num_cmd + 1));
	s->cmd_path = malloc(sizeof(char *) * (s->num_cmd + 1));
	i = 0;
	while (i < s->num_cmd)
	{
		s->cmd_path[i] = NULL;
		i++;
	}
	if (!s->cmd || !s->cmd_path)
		ft_exit(s, "malloc", EXIT_FAILURE);
	s->pid = malloc(sizeof(pid_t) * s->num_cmd);
}

int	main(int ac, char **av, char **envp)
{
	t_struct	s;

	take_arguments(&s, ac, av);
	find_commands_paths(&s, envp);
	find_good_path(&s, av);
	pipex(&s);
	ft_exit(&s, "", EXIT_SUCCESS);
}
