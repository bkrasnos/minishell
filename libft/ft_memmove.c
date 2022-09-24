/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:36:42 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/24 14:36:54 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*setret(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (src < dest)
	{
		i = n;
		while (i > 0 && (dest != NULL || src != NULL))
		{
			i--;
			d[i] = s[i];
		}
	}
	else if (src > dest)
	{
		while (i < n && (dest != NULL || src != NULL))
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src == dest)
		return (dest);
	return ((char *)setret(dest, src, n));
}
