/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:41:10 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/07 14:47:48 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	if (s1 == NULL || set == NULL)
		return ((char *)s1);
	while (char_in_set(s1[i], (char *)set) && s1[i])
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (char_in_set(s1[i], (char *)set) && i > start)
		i--;
	end = i;
	i = 0;
	str = malloc(sizeof(char) * (end - start + 2));
	if (str == NULL)
		return (str);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = 0;
	free ((char *)s1);
	return (str);
}
