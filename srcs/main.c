#include "pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
		while (--i >= 0)
			free(tab[i]);
		free(tab);
	}
}

void	ft_exit(t_struct *s, char *error)
{
	if (s->fd_infile >= 0)
		close(s->fd_infile);
	if (s->fd_outfile >= 0)
		close(s->fd_outfile);
	free_tab(s->paths);
	perror(error);
	exit(EXIT_FAILURE);
}

void	find_command_path(t_struct *s, char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i]);
			if (!path)
				ft_exit(s, "malloc");
		}
		i++;
	}
	path += 5;
	s->paths = ft_split(path, ':');
	path -= 5;
	free(path);
	if (!s->paths)
		ft_exit(s, "malloc");
}

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

	take_arguments(&s, ac, av);
	find_command_path(&s, envp);
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
	return EXIT_SUCCESS;
}
