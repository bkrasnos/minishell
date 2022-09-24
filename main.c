/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:27:18 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/23 17:59:30 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_excep(t_list *lst, int i)
{
	t_redir	*redir;
	int		j;

	j = 1;
	while (lst)
	{
		redir = lst->content;
		if (j == i && redir->mode == 4)
			return (1);
		lst = lst->next;
		j++;
	}
	return (0);
}

int	args_counter(t_list *lst)
{
	int		count;
	char	*token;

	count = 0;
	while (lst)
	{
		token = lst->content;
		if (*token == '<' || *token == '>')
			count = count - 1;
		if (*token == '|')
			break ;
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ft_exit_minishell(t_shell *data)
{
	if (data->envp_list)
		ft_free_env(&data->envp_list);
	if (data->cmd && data->count_cmd > 0)
		free_shell(data);
	exit(data->exit_code);
}

static void	ft_prompt(int ac, t_shell *shell)
{
	char	*str;

	while (ac > 0)
	{
		set_input_signals();
		str = readline("not-bash> ");
		str = ft_strtrim(str, " ");
		signal(SIGINT, &signal_handler2);
		if (!str)
		{
			ft_putstr_fd("exit\n", 1);
			free(str);
			ft_exit_minishell(shell);
		}
		if (ft_strlen(str))
		{
			if (!parser(str, shell))
			{
				ft_executer(shell);
				free_shell(shell);
			}
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_shell	shell;

	(void)av;
	shell.exit_code = 0;
	if (ac > 1)
	{
		printf("No arguments allowed\n");
		exit (127);
	}
	shell.envp_list = ft_init_env(&shell, envp);
	if (!shell.envp_list)
		return (0);
	shell.exit_code = 0;
	ft_prompt(ac, &shell);
	return (0);
}
