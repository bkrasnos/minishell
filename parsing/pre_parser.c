/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdony <hdony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:16:40 by orandan           #+#    #+#             */
/*   Updated: 2022/09/23 11:07:29 by hdony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*print_quotes_er(char quotes)
{
	if (quotes == '\'')
		ft_putstr_fd("not-bash: unclosed single quote error\n", 2);
	else
		ft_putstr_fd("not bash: unclosed double quote error\n", 2);
	return (NULL);
}

static char	*print_er(char *error)
{
	ft_putstr_fd("not-bash: syntax error near unexpected token ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

/* check if line is empty or if line is only made up of spaces */
static	int	check_empty_line(char *line)
{
	if (!line)
	{
		free(line);
		return (1);
	}
	while ((*line == ' ' || *line == '\t') && *line)
		line++;
	if (*line == '|')
	{
		print_er("`|'");
		return (259);
	}
	if (!line)
		return (1);
	return (0);
}

static char	*ft_check_sign(char *line, char quotes,	int *cnt, t_shell *shell)
{
	if (*line == '\'' || *line == '\"')
	{
		quotes = *line;
		line++;
		while (*line != quotes && *line)
			line++;
		if (*line != quotes)
			return (print_quotes_er(quotes));
	}
	if (*line == '|')
	{
		(*cnt)++;
		line++;
		while (*line == ' ')
			line++;
		if (*line == '|')
		{
			print_er("`|'");
			shell->exit_code = 258;
			return (NULL);
		}
	}
	else
		line++;
	return (line);
}

int	pre_parse(char *line, t_shell *shell)
{
	char	quotes;
	int		count_cmd;
	int		err;

	count_cmd = 1;
	err = check_empty_line(line);
	if (err)
	{
		shell->exit_code = err - 1;
		return (-1);
	}
	while (*line)
	{
		quotes = '0';
		line = ft_check_sign(line, quotes, &count_cmd, shell);
		if (!line)
			return (-1);
	}
	if (*(line - 1) == '<' || *(line - 1) == '>')
	{
		print_er("`newline'");
		shell->exit_code = 258;
		return (-1);
	}
	return (count_cmd);
}
