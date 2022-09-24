/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:38:59 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/06 14:06:27 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_namecmp(t_list *lst, char *str)
{
	t_env	*ptr;

	ptr = (t_env *)lst->content;
	if (!ft_strncmp(str, ptr->name, ft_strlen(ptr->name) + 1))
		return (1);
	return (0);
}

void	ft_del_var_env(void *lst)
{
	t_env	*ls_node_env;

	ls_node_env = (t_env *)(lst);
	if (ls_node_env->name)
		free(ls_node_env->name);
	if (ls_node_env->value)
		free(ls_node_env->value);
	free(ls_node_env);
}

void	ft_unset_var_env(t_list **is_envp_list, char *str)
{
	t_list	**ls_current;
	t_list	*ls_next;

	ls_current = is_envp_list;
	while (*ls_current)
	{
		if (ft_namecmp(*ls_current, str))
		{
			ls_next = (*ls_current)->next;
			ft_lstdelone(*ls_current, &ft_del_var_env);
			*ls_current = ls_next;
			break ;
		}
		ls_current = &(*ls_current)->next;
	}
}

static int	ft_is_valid_token_unset(char *s)
{
	while (s && *s)
	{
		if (!ft_isalnum(*s))
			return (0);
		s++;
	}
	return (1);
}

void	ft_unset(t_shell *data, int num_cmd)
{
	int	i;

	if (!data->cmd[num_cmd].args)
		return ;
	i = 1;
	while (data->cmd[num_cmd].args[i])
	{
		if (ft_is_valid_token_unset(data->cmd[num_cmd].args[i]))
			ft_unset_var_env(&data->envp_list, data->cmd[num_cmd].args[i++]);
		else
		{
			printf("not-bash: unset: `%s': ", data->cmd[num_cmd].args[i++]);
			printf("not a valid identifier\n");
		}
	}
	return ;
}
