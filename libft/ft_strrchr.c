/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:39:46 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/28 21:55:07 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	int				i;
	unsigned char	my_c;

	my_c = (unsigned char)c;
	i = ft_strlen(str);
	while (i != -1)
	{
		if (str[i] == my_c)
			return ((char *)(&str[i]));
		i--;
	}
	return (NULL);
}
