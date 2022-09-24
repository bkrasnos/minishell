/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:39:17 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/29 00:23:11 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] && (j + i + 1) < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (!src[j])
		dest[i + j] = '\0';
	tmp = j;
	j = ft_strlen(src);
	if (n == 0)
		return (j);
	if (i < n)
	{
		dest[tmp + i] = '\0';
		return (i + j);
	}
	else
		return (n + j);
	return (n);
}
