#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct s_fd
{
	int		fd_infile;
	int		fd_outfile;
	char	**paths;
}	t_fd;

int		main(int ac, char **av, char **envp);
void	take_arguments(t_fd *fd, int ac, char **av);
void	son_fork(t_fd *fd, int pipefd[2]);
void	dad_fork(t_fd *fd, int pipefd[2]);

#endif