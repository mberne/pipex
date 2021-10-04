/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:50 by mberne            #+#    #+#             */
/*   Updated: 2021/10/04 16:29:23 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct s_struct
{
	int		fd_infile;
	int		fd_outfile;
	int		num_pipes;
	char	**paths;
	char	**cmd_path;
}	t_struct;

int		main(int ac, char **av, char **envp);
void	take_arguments(t_struct *fd, int ac, char **av);

void	find_commands_paths(t_struct *s, char **envp);
void	set_paths(t_struct *s);
void	find_good_path(t_struct *s, char **av);
void	test_path(t_struct *s, char **tmp_cmd, char *tmp_path, int i);

void	first_son_fork(t_struct *fd, int pipefd[2], char **av);
void	second_son_fork(t_struct *fd, int pipefd[2], char **av);
void	dad_fork(t_struct *fd, int pipefd[2], char **av);

void	free_tab(char **tab);
void	ft_exit(t_struct *s, char *error, int exit_status);

#endif