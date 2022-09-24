/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:37:44 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/28 21:54:46 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_free_my_split(size_t j, char **split)
{
	while (j != 0)
		free(split[--j]);
	free(split);
	return (NULL);
}

static int	ft_words_count(char const *str, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			wc++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (wc);
}

static char	*ft_add_word(char const *str, char c)
{
	size_t	i;
	char	*lstr;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	lstr = malloc(sizeof(char) * i + 1);
	if (lstr == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		lstr[i] = str[i];
		i++;
	}
	lstr[i] = '\0';
	return (lstr);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	char	**split;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_words_count(str, c) + 1));
	if (!split)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
		{
			split[j] = ft_add_word(&str[i], c);
			if (!split[j++])
				return (ft_free_my_split(--j, split));
			while (str[i + 1] && str[i + 1] != c)
				i++;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
