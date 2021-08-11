#include "pipex.h"

void	dad_fork(t_struct *s, int pipefd[2])
{
	(void)s;
	(void)pipefd;
	return ;
}

void	son_fork(t_struct *s, int pipefd[2])
{
	(void)s;
	(void)pipefd;
	return ;
	//dup2
}
