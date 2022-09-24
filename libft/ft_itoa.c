/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:34:44 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/02 13:23:19 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intsize(int n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	if (n == -2147483648)
		n = n + 1;
	if (n < 0)
	{
		n = n * (-1);
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static int	ft_setnegative(int n)
{
	if (n == -2147483648)
		n = n + 1;
	if (n < 0)
		n = n * (-1);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		len;
	char	tmp;
	int		t;

	t = n;
	len = ft_intsize(n);
	nb = malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (0);
	nb[len] = '\0';
	n = ft_setnegative(n);
	while (len-- > 0)
	{
		tmp = n % 10 + '0';
		n = n / 10;
		nb[len] = tmp;
	}
	if (t < 0)
		nb[0] = '-';
	if (t == -2147483648)
		nb[ft_intsize(t) - 1] = nb[ft_intsize(t) - 1] + 1;
	return (nb);
}
