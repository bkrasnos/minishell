/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:41:01 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/06 14:09:03 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static long int	ft_argtoi(char const *str)
{
	int						countneg;
	unsigned long long int	integ;

	countneg = 1;
	integ = 0;
	if (*str == '-')
	{
		countneg = -1;
		str++;
	}
	if (*str == '+' && countneg != -1)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (integ >= 922337203685477580 && *str > '7' && countneg == 1)
			return (-1);
		if (integ >= 922337203685477580 && *str > '8' && countneg == -1)
			return (1);
		integ *= 10;
		integ += (*str++ - 48);
	}
	return ((long int)integ * countneg);
}

static int	ft_isnumber(char *str)
{
	int				i;
	long long int	num;

	i = 0;
	if (str && (*str == '-' || *str == '+'))
		i++;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_argtoi(str);
	if ((num < 0 && *str != '-') || (num > 0 && *str == '-'))
		return (0);
	return (1);
}

static void	ft_return_error_isnum(t_shell *data, int num_cmd, int i)
{
	printf("exit\nnot-bash: exit: %s : ", data->cmd[num_cmd].args[i]);
	printf("numeric argument required\n");
	data->exit_code = 255;
	exit (255);
}

static void	ft_set_retcode(t_shell *data, int num_cmd)
{
	long long int	num;

	num = ft_argtoi(data->cmd[num_cmd].args[1]);
	ft_print_error(data, NULL, (unsigned char)num);
}

void	ft_exit(t_shell *data, int num_cmd)
{
	int	i;

	i = 1;
	while (data->cmd[num_cmd].args[i])
	{
		if (!ft_isnumber(data->cmd[num_cmd].args[i]))
		{
			ft_return_error_isnum(data, num_cmd, i);
			return ;
		}
		i++;
	}
	if ((i - 1) > 1)
	{
		printf("exit\nnot-bash: exit: too many arguments\n");
		ft_print_error(data, NULL, 1);
		return ;
	}
	if ((i - 1) == 1)
		ft_set_retcode(data, num_cmd);
	ft_putstr_fd("exit\n", 1);
	ft_exit_minishell(data);
}
