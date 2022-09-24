/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:37:51 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/05 22:21:39 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int c)
{
	char	my_c;

	my_c = (char)c;
	while (*str)
	{
		if (*str == my_c)
			return ((char *)str);
		str++;
	}
	if (my_c == 0)
		return ((char *)str);
	return (NULL);
}
