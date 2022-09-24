/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executer_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:52:21 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/23 11:06:49 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	set_exit_status(int exit_status)
{
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
	{
		if (WTERMSIG(exit_status) == SIGQUIT)
			write(1, "Quit: 3\n", 8);
		exit_status = 128 + WTERMSIG(exit_status);
	}
	return (exit_status);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*error_path(t_shell *dt, char *command, char *tmp, char *cmd)
{
	dt->exit_code = 127;
	ft_putstr_fd("not-bash: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
	free(command);
	free(tmp);
	free(cmd);
	return (NULL);
}

static char	*pre_join_path(char *cmd, t_shell *dt)
{
	if (!cmd)
	{
		dt->exit_code = 127;
		ft_putstr_fd("not-bash: ", 2);
		ft_putstr_fd("command not found\n", 2);
		return (NULL);
	}
	if (access(cmd, X_OK) != 0 && access(cmd, F_OK) == 0 && ft_strchr(cmd, '/'))
		return (permission_error(cmd, dt));
	if (access(cmd, F_OK) != 0 && ft_strchr(cmd, '/'))
	{
		ft_no_file_dir(-1, cmd);
		dt->exit_code = 127;
		return (NULL);
	}
	return (cmd);
}

char	*join_path(char *cmd, char **path, t_shell *dt)
{
	int		i;
	char	*tmp;
	char	*command;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	if (!pre_join_path(cmd, dt))
		return (NULL);
	command = ft_strdup(cmd);
	tmp = ft_strjoin("/", cmd);
	free(cmd);
	cmd = ft_strjoin(path[i], tmp);
	while (path[i] && access(cmd, X_OK) != 0)
	{
		free(cmd);
		cmd = ft_strjoin(path[i++], tmp);
	}
	if (path[i] == NULL)
		return (error_path(dt, command, tmp, cmd));
	free(command);
	free(tmp);
	return (cmd);
}
