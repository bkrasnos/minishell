/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:33:35 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/28 12:30:12 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (n == 0 || size == 0)
	{
		n = 1;
		size = 1;
	}
	ptr = malloc(n * size);
	if (ptr == NULL)
		return (0);
	while (i < (n * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
