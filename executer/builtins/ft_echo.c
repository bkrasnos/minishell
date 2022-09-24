/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:33:56 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/06 14:03:40 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_is_flag_echo(char *s)
{
	if (!s || *s != '-')
		return (0);
	s++;
	if (!(*s))
		return (0);
	while (*s)
	{
		if (*s != 'n')
			return (0);
		s++;
	}
	return (1);
}

static int	ft_add_flag(char **args)
{
	int	i;
	int	c;

	i = 2;
	c = 0;
	while (args[i])
	{
		if (ft_is_flag_echo(args[i]))
			c++;
		else
			break ;
		i++;
	}
	return (c);
}

static void	ft_echo_print2(char *s)
{
	write(STDOUT_FILENO, s, ft_strlen(s));
}

static void	ft_echo_print(char *s, int flag)
{
	if (!flag)
	{
		write(STDOUT_FILENO, s, ft_strlen(s));
		if (ft_strncmp(s, "$", 1))
			write(STDOUT_FILENO, " ", 1);
	}
	else
	{
		write(STDOUT_FILENO, s, ft_strlen(s));
		write(STDOUT_FILENO, " ", 1);
	}
}

void	ft_echo(t_shell *d, int num_cmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = ft_is_flag_echo(d->cmd[num_cmd].args[i]);
	if (flag)
		i += ft_add_flag(d->cmd[num_cmd].args) + 1;
	while (d->cmd[num_cmd].args[i])
	{
		if (ft_strlen(d->cmd[num_cmd].args[i]) != 0)
		{
			if (!ft_strncmp(d->cmd[num_cmd].args[i], "$?", 2))
				ft_putnbr_fd(d->exit_code, 1);
			else if (!d->cmd[num_cmd].args[i + 1])
				ft_echo_print2(d->cmd[num_cmd].args[i]);
			else if ((!flag && i > 1) || (flag && i > flag + 1))
				ft_echo_print(d->cmd[num_cmd].args[i], 1);
			else
				ft_echo_print(d->cmd[num_cmd].args[i], 0);
		}
		i++;
	}
	if (!flag)
		write(1, "\n", 1);
	ft_print_error(d, NULL, 0);
}
