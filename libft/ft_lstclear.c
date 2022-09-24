/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:49:55 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/12 15:49:57 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst == 0 || del == 0)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		*lst = tmp;
		tmp = tmp->next;
		ft_lstdelone(*lst, del);
	}
	*lst = NULL;
}
