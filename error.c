/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odan <odan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:09:45 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/07 12:16:14 by odan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*permission_error(char *cmd, t_shell *dt)
{
	printf("not-bash: %s: permission denied\n", cmd);
	dt->exit_code = 126;
	return (NULL);
}

int	ft_print_error(t_shell *data, const char *str, int nbr)
{
	if (str)
		perror(str);
	if (nbr < 0)
		nbr = EXIT_FAILURE;
	data->exit_code = nbr;
	return (nbr);
}

void	ft_print_err_export(char *str)
{
	ft_putstr_fd("export: \'", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\': not a valid identifier\n", 2);
}

int	ft_no_file_dir(int fd, char *name)
{
	if (fd == -1)
	{
		ft_putstr_fd("not-bash: ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	return (0);
}
