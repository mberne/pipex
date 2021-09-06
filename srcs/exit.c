/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:10:22 by mberne            #+#    #+#             */
/*   Updated: 2021/09/06 15:34:38 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
	free_tab(s->cmd_path);
	perror(error);
}
