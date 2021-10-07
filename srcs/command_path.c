/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:47:21 by mberne            #+#    #+#             */
/*   Updated: 2021/10/07 14:13:01 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	test_path(t_struct *s, char **tmp_cmd, int i)
{
	int		j;
	char	*tmp_path;

	j = 0;
	while (s->paths[j])
	{
		tmp_path = ft_strjoin(s->paths[j], tmp_cmd[0]);
		if (!tmp_path)
		{
			free_tab(tmp_cmd, 0);
			ft_exit(s, "malloc", EXIT_FAILURE);
		}
		if (open(tmp_path, O_RDONLY) != -1)
		{
			s->cmd_path[i] = ft_strdup(tmp_path);
			if (!s->cmd_path[i])
			{
				free_tab(tmp_cmd, 0);
				free(tmp_path);
				ft_exit(s, "malloc", EXIT_FAILURE);
			}
		}
		free(tmp_path);
		j++;
	}
}

void	find_good_path(t_struct *s, char **av)
{
	int		i;
	char	**tmp_cmd;

	i = 0;
	while (i < s->num_cmd)
	{
		s->cmd[i] = ft_strdup(av[i + 2]);
		if (!s->cmd[i])
			ft_exit(s, "malloc", EXIT_FAILURE);
		tmp_cmd = ft_split(s->cmd[i], ' ');
		if (!tmp_cmd)
			ft_exit(s, "malloc", EXIT_FAILURE);
		test_path(s, tmp_cmd, i);
		free_tab(tmp_cmd, 0);
		i++;
	}
	s->cmd_path[i] = 0;
	s->cmd[i] = 0;
}

void	set_paths(t_struct *s)
{
	int	i;

	i = 0;
	while (s->paths[i])
	{
		s->paths[i] = ft_strjoin_free_s1(s->paths[i], "/");
		if (!s->paths[i])
			ft_exit(s, "malloc", EXIT_FAILURE);
		i++;
	}
}

void	find_commands_paths(t_struct *s, char **envp)
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
				ft_exit(s, "malloc", EXIT_FAILURE);
		}
		i++;
	}
	s->paths = ft_split(path + 5, ':');
	free(path);
	if (!s->paths)
		ft_exit(s, "malloc", EXIT_FAILURE);
	set_paths(s);
}
