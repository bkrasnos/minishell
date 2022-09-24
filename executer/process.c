/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:47:01 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/07 17:15:55 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	process(t_shell *data, char **envp, int i, int **fd)
{
	signal(SIGQUIT, SIG_DFL);
	if (ft_redir(&data->cmd[i], data->cmd->redir, i))
		exit(EXIT_FAILURE);
	ft_dup_fd(i, fd, data);
	if (is_builtin(data, i))
		execute_builtin(data, i);
	else if (execve(data->cmd[i].cmd, data->cmd[i].args, envp) == -1)
		exit(data->exit_code);
	exit(data->exit_code);
}

int	ft_create_pipe(int **fd, t_shell *data)
{
	int	i;

	i = 0;
	while (i < data->count_cmd - 1)
	{
		if (pipe(fd[i]) == -1)
		{
			ft_putstr_fd("error in pipe\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	ft_wait_process(pid_t	*id, t_shell *data)
{
	int		i;
	int		ret;

	i = 0;
	while (i < data->count_cmd)
	{
		waitpid(id[i], &ret, 0);
		ret = set_exit_status(ret);
		ft_print_error(data, NULL, ret);
		i++;
	}
}

static int	**ft_malloc_fd(t_shell *data, int i)
{
	int	**fd;

	fd = malloc(sizeof(int *) * (data->count_cmd - 1));
	if (!fd)
		return (0);
	while (++i < data->count_cmd - 1)
	{
		fd[i] = malloc(sizeof(int ) * 2);
		if (!fd[i])
			return (0);
	}
	if ((ft_create_pipe(fd, data)) || !fd)
		return (0);
	return (fd);
}

int	ft_process_manager(pid_t	*id, t_shell *data, char **envp, int i)
{
	int		**fd;

	if (is_builtin(data, 0) == 1 && data->count_cmd == 1)
	{
		execute_builtin(data, 0);
		return (0);
	}
	fd = ft_malloc_fd(data, i);
	if (!fd)
		return (1);
	i = -1;
	while (++i < data->count_cmd)
	{
		id[i] = fork();
		if (id[i] == -1)
			exit(EXIT_FAILURE);
		if (id[i] == 0)
			process(data, envp, i, fd);
	}
	ft_close_fd(fd, data);
	ft_wait_process(id, data);
	return (0);
}
