/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:51:06 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/12 15:51:08 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*dest;

	dest = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new)
			ft_lstadd_back(&dest, new);
		else
		{
			ft_lstclear(&dest, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (dest);
}
