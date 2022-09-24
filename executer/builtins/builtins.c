/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:29:03 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/06 17:23:49 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtin(t_shell *data, int num_cmd)
{
	if (data->cmd[num_cmd].cmd == NULL)
		return (0);
	if (ft_strncmp(data->cmd[num_cmd].cmd, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(data->cmd[num_cmd].cmd, "pwd", 3) == 0)
		return (2);
	else if (ft_strncmp(data->cmd[num_cmd].cmd, "PWD", 3) == 0)
		return (2);
	else if (ft_strncmp(data->cmd[num_cmd].cmd, "echo", 4) == 0)
		return (2);
	else if (ft_strncmp(data->cmd[num_cmd].cmd, "env", 3) == 0)
		return (2);
	else if (ft_strncmp(data->cmd[num_cmd].cmd, "ENV", 3) == 0)
		return (2);
	else if (ft_strncmp(data->cmd[num_cmd].cmd, "exit", 4) == 0)
		return (1);
	else if (ft_strncmp(data->cmd[num_cmd].cmd, "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(data->cmd[num_cmd].cmd, "export", 6) == 0)
		return (1);
	return (0);
}

int	execute_builtin(t_shell *data, int num_cmd)
{
	if (!ft_strncmp(data->cmd[num_cmd].args[0], "pwd", 3))
		ft_pwd(data);
	else if (!ft_strncmp(data->cmd[num_cmd].args[0], "PWD", 3))
		ft_pwd(data);
	else if (!ft_strncmp(data->cmd[num_cmd].args[0], "echo", 4))
		ft_echo(data, num_cmd);
	else if (!ft_strncmp(data->cmd[num_cmd].args[0], "cd", 2))
		ft_cd(data, num_cmd);
	else if (!ft_strncmp(data->cmd[num_cmd].args[0], "env", 3))
		ft_env(&data->envp_list);
	else if (!ft_strncmp(data->cmd[num_cmd].args[0], "ENV", 3))
		ft_env(&data->envp_list);
	else if (!ft_strncmp(data->cmd[num_cmd].args[0], "export", 6))
		ft_export(data, num_cmd);
	else if (!ft_strncmp(data->cmd[num_cmd].args[0], "unset", 5))
		ft_unset(data, num_cmd);
	else if (!ft_strncmp(data->cmd[num_cmd].args[0], "exit", 4))
		ft_exit(data, num_cmd);
	return (EXIT_SUCCESS);
}

static char	*ft_join_env(t_env *env)
{
	char	*str_env;
	char	*tmp;

	tmp = ft_strjoin(env->name, "=");
	str_env = ft_strjoin(tmp, env->value);
	free(tmp);
	return (str_env);
}

char	**get_envp(t_list *lst)
{
	int		i;
	int		size;
	char	**mass;
	t_env	*env;

	size = ft_lstsize(lst) + 1;
	mass = malloc(size * sizeof(char *));
	if (!mass)
		return (NULL);
	i = 0;
	while (lst && i < size)
	{
		env = (t_env *)lst->content;
		mass[i++] = ft_join_env(env);
		lst = lst->next;
	}
	mass[i] = NULL;
	return (mass);
}
