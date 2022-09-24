/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:33:12 by nedebies          #+#    #+#             */
/*   Updated: 2021/04/29 19:35:37 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isovermaxmin(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(char const *str)
{
	int		i;
	int		sign;
	long	result;
	int		cpt;

	result = 0;
	i = 0;
	sign = 1;
	cpt = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		if (result < 0 || ++cpt > 19)
			return (ft_isovermaxmin(sign));
		i++;
	}
	return ((int)(sign * result));
}
