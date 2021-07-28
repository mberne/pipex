/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:15:11 by mberne            #+#    #+#             */
/*   Updated: 2020/12/01 09:36:51 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = *lst;
	if (!*lst)
		return ;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = tmp;
	}
	*lst = NULL;
}
