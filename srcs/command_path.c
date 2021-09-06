/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:47:21 by mberne            #+#    #+#             */
/*   Updated: 2021/09/06 15:37:06 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	test_path(t_struct *s, char **tmp_cmd, char *tmp_path, int i)
{
	if (open(tmp_path, O_RDONLY) != -1)
	{
		s->cmd_path[i] = ft_strdup(tmp_path);
		if (!s->cmd_path[i])
		{
			free_tab(tmp_cmd);
			free(tmp_path);
			ft_exit(s, "malloc");
			exit(EXIT_FAILURE);
		}
		free(tmp_path);
	}
	else
		free(tmp_path);
}

void	find_good_path(t_struct *s, char **av)
{
	int		i;
	int		j;
	char	*tmp_path;
	char	**tmp_cmd;

	i = -1;
	s->cmd_path = malloc(sizeof(char *) * (2 + 1));
	while (++i < 2)
	{
		j = -1;
		tmp_cmd = ft_split(av[i + 2], ' ');
		if (!tmp_cmd)
		{
			ft_exit(s, "malloc");
			exit(EXIT_FAILURE);
		}
		while (s->paths[++j])
		{
			tmp_path = ft_strjoin(s->paths[j], tmp_cmd[0]);
			if (!tmp_path)
			{
				free_tab(tmp_cmd);
				ft_exit(s, "malloc");
				exit(EXIT_FAILURE);
			}
			test_path(s, tmp_cmd, tmp_path, i);
		}
		free(tmp_cmd);
	}
}

void	set_paths(t_struct *s)
{
	int	i;

	i = 0;
	while (s->paths[i])
	{
		s->paths[i] = ft_strjoin(s->paths[i], "/");
		if (!s->paths[i])
		{
			ft_exit(s, "malloc");
			exit(EXIT_FAILURE);
		}
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
			{
				ft_exit(s, "malloc");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	path += 5;
	s->paths = ft_split(path, ':');
	path -= 5;
	free(path);
	if (!s->paths)
	{
		ft_exit(s, "malloc");
		exit(EXIT_FAILURE);
	}
	set_paths(s);
}
