/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:46:35 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/28 12:35:26 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *tofind, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(tofind);
	if (j == 0)
		return ((char *)str);
	if (ft_strlen(str) == 0)
		return (NULL);
	while (i < n)
	{
		if (ft_strncmp((char *)&str[i], tofind, j) == 0)
		{
			if (i + j > n)
				return (NULL);
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
