/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:40:50 by mberne            #+#    #+#             */
/*   Updated: 2021/10/07 14:12:26 by mberne           ###   ########lyon.fr   */
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
	int		num_cmd;
	char	**paths;
	char	**cmd;
	char	**cmd_path;
	pid_t	*pid;
}	t_struct;

int		main(int ac, char **av, char **envp);
void	take_arguments(t_struct *fd, int ac, char **av);
void	pipex(t_struct *s);
pid_t	launch_command(t_struct *s, int in, int out, int i);
void	ft_exit(t_struct *s, char *error, int exit_status);

void	find_commands_paths(t_struct *s, char **envp);
void	set_paths(t_struct *s);
void	find_good_path(t_struct *s, char **av);
void	test_path(t_struct *s, char **tmp_cmd, int i);

#endif