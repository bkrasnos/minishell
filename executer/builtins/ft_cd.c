/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:35:59 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/07 12:03:26 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_update_dir(t_shell *d)
{
	int		err;
	char	*new_pwd;
	t_list	**head;

	head = &d->envp_list;
	ft_print_error(d, NULL, 0);
	new_pwd = getcwd(NULL, 0);
	err = ft_putenv(head, "PWD", new_pwd);
	free(new_pwd);
	return (err);
}

static char	*ft_check_tilde(t_list **head, char *str)
{
	if (!ft_strlen(str) || *str != '~' || !ft_getenv(*head, "HOME"))
		return (ft_strdup(str));
	str++;
	return (ft_strjoin(ft_getenv(*head, "HOME"), str));
}

static int	no_home_err(t_shell *sh)
{
	ft_putstr_fd("bash: cd: HOME not set\n", 1);
	sh->exit_code = 1;
	return (sh->exit_code);
}

static int	check_no_home(t_shell *d, int num_cmd)
{
	if (ft_getenv(d->envp_list, "HOME"))
		ft_putenv(&d->envp_list, "OLDPWD", ft_getenv(d->envp_list, "PWD"));
	else if (!ft_getenv(d->envp_list, "HOME"))
	{
		if (!ft_strlen(d->cmd[num_cmd].args[1]))
			return (1);
		if (!ft_strncmp(d->cmd[num_cmd].args[1], "~", 1))
			return (1);
	}
	return (0);
}

int	ft_cd(t_shell *d, int num_cmd)
{
	int		err;
	char	*new_pwd;

	if (!d || !d->envp_list || !d->cmd[num_cmd].args[0])
		return (1);
	if (check_no_home(d, num_cmd))
		return (no_home_err(d));
	if (!ft_strlen(d->cmd[num_cmd].args[1]))
		err = chdir(ft_getenv(d->envp_list, "HOME"));
	else
	{
		new_pwd = ft_check_tilde(&d->envp_list, d->cmd[num_cmd].args[1]);
		err = chdir(new_pwd);
		if (new_pwd)
			free(new_pwd);
	}
	if (err)
		ft_print_error(d, d->cmd[num_cmd].args[1], 1);
	else
	{
		err = ft_update_dir(d);
		ft_print_error(d, NULL, 0);
	}
	return (err);
}
