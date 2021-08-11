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

void	ft_exit(t_fd *fd, char *error)
{
	int	i;

	i = 0;
	if (fd->fd_infile >= 0)
		close(fd->fd_infile);
	if (fd->fd_outfile >= 0)
		close(fd->fd_outfile);
	free_tab(fd->paths);
	perror(error);
	exit(EXIT_FAILURE);
}

void	find_command_path(t_fd *fd, char **envp)
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
				ft_exit(fd, "malloc");
		}
		i++;
	}
	path += 5;
	fd->paths = ft_split(path, ':');
	path -= 5;
	free(path);
	if (!fd->paths)
		ft_exit(fd, "malloc");
}

void	take_arguments(t_fd *fd, int ac, char **av)
{
	if (ac != 5)
		exit(EXIT_FAILURE);
	fd->fd_infile = open(av[1], O_RDONLY);
	if (fd->fd_infile == -1)
		ft_exit(fd, "open");
	fd->fd_outfile = open(av[4], O_WRONLY);
	if (fd->fd_outfile == -1)
		ft_exit(fd, "open");
}

int	main(int ac, char **av, char **envp)
{
	t_fd	fd;
	pid_t	pid;
	int		pipefd[2];

	take_arguments(&fd, ac, av);
	find_command_path(&fd, envp);
	if (pipe(pipefd) == 1)
		ft_exit(&fd, "pipe");
	pid = fork();
	if (pid == -1)
		ft_exit(&fd, "fork");
	else if (pid == 0)
		son_fork(&fd, pipefd);
	else
	{
		dad_fork(&fd, pipefd);
		wait(NULL);
	}
	close(fd.fd_infile);
	close(fd.fd_outfile);
	return EXIT_SUCCESS;
}
