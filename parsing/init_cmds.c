/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:55:36 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/23 11:18:09 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**set_args(int count_args)
{
	char	**args;

	args = NULL;
	args = malloc((sizeof(char *) * count_args) + 1);
	if (!args)
		return (NULL);
	ft_memset(args, '\0', sizeof(char *) * count_args + 1);
	args[count_args] = NULL;
	return (args);
}

static char	**init_cmd_args(t_list **lst, t_shell *data, int idx, int j)
{
	int		count_args;
	char	**args;
	char	*token;

	count_args = args_counter(*lst);
	args = set_args(count_args);
	if (!args)
		return (NULL);
	while (count_args-- > 0)
	{
		token = (*lst)->content;
		if (*token == '<' || *token == '>')
		{
			ft_init_file(*lst, data->cmd, data, idx);
			(*lst) = (*lst)->next->next;
		}
		else
		{
			(*lst)->content = parse_line((*lst)->content, data, -1);
			args[j++] = ft_strdup((*lst)->content);
			(*lst) = (*lst)->next;
		}
	}
	return (args);
}

static int	is_builtin_ll(char *token)
{
	if (token == NULL)
		return (0);
	if (ft_strncmp(token, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(token, "pwd", 3) == 0)
		return (2);
	else if (ft_strncmp(token, "PWD", 3) == 0)
		return (2);
	else if (ft_strncmp(token, "echo", 4) == 0)
		return (2);
	else if (ft_strncmp(token, "env", 3) == 0)
		return (2);
	else if (ft_strncmp(token, "ENV", 3) == 0)
		return (2);
	else if (ft_strncmp(token, "exit", 4) == 0)
		return (1);
	else if (ft_strncmp(token, "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(token, "export", 6) == 0)
		return (1);
	return (0);
}

static char	*find_cmd(t_list *lst)
{
	char	*token;

	while (lst != NULL)
	{
		token = lst->content;
		if (is_builtin_ll(token) != 0)
			return (token);
		lst = lst->next;
	}
	return (NULL);
}

void	init_each_command(t_list **lst, t_shell *data, int i)
{
	if (!ft_strncmp((*lst)->content, ">", 1)
		|| !ft_strncmp((*lst)->content, "<", 1))
	{
		data->cmd[i].cmd = ft_strdup(find_cmd(*lst));
		data->cmd[i].cmd = parse_line(data->cmd[i].cmd, data, -1);
		data->cmd[i].args = init_cmd_args(lst, data, i, 0);
	}
	else
	{
		data->cmd[i].cmd = ft_strdup((*lst)->content);
		data->cmd[i].cmd = parse_line(data->cmd[i].cmd, data, -1);
		data->cmd[i].args = init_cmd_args(lst, data, i, 0);
	}
}
