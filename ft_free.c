/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:15:13 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/06 16:06:21 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_delete_env(void *lst)
{
	t_env	*ls_env_node;

	ls_env_node = (t_env *)(lst);
	if (ls_env_node->name)
		free(ls_env_node->name);
	if (ls_env_node->value)
		free(ls_env_node->value);
	free(ls_env_node);
}

void	ft_free_env(t_list **is_head)
{
	t_list	**ls_current;
	t_list	*ls_next;

	ls_current = is_head;
	while (*ls_current)
	{
		ls_next = (*ls_current)->next;
		ft_lstdelone(*ls_current, &ft_delete_env);
		*ls_current = ls_next;
	}
	if (*is_head != NULL)
		free(is_head);
}

void	free_redir(t_cmnd *cmd)
{
	t_redir	*redir;
	t_list	*start;

	start = cmd->redir;
	while (cmd->redir)
	{
		redir = cmd->redir->content;
		free(redir->name);
		cmd->redir = cmd->redir->next;
	}
	ft_lstclear(&start, free);
}

void	free_cmd(t_cmnd *cmd)
{
	int		i;

	i = 0;
	while (cmd->args && cmd->args[i])
	{
		free (cmd->args[i]);
		i++;
	}
	i = 0;
	if (cmd->args)
		free(cmd->args);
	if (cmd->in_file)
		close(cmd->in_file);
	if (cmd->out_file)
		close(cmd->out_file);
	if (cmd->cmd)
		free(cmd->cmd);
	free_redir(cmd);
}

void	free_shell(t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->count_cmd)
	{
		free_cmd(shell->cmd + i);
		i++;
	}
	shell->count_cmd = 0;
	free(shell->cmd);
	shell->cmd = NULL;
}
