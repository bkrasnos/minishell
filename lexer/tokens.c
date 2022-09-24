/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odan <odan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:53:31 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/07 18:35:57 by odan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	len_quotes(char *line, int i)
{
	char	quotes;
	int		len;

	len = 0;
	quotes = line[i];
	len++;
	while (line[i + len] != quotes)
		len++;
	return (len + 1);
}

/* check the len of tokens (< or <<, len of words between quotes) */
static int	len_token(char *line, int i)
{
	int	len;

	len = 0;
	if (line[i] == '<' || line[i] == '>')
	{
		i++;
		if (line[i] == '<' || line[i] == '>')
			return (2);
		return (1);
	}
	if (line[i] == '|')
		return (1);
	if (line[i] == '\"' || line[i] == '\'')
		return (len_quotes(line, i));
	while (line[i + len])
	{
		if (line[i + len] == ' ' || line[i + len] == '\t')
			return (len);
		if (line[i + len] == '<' || line[i + len] == '>')
			return (len);
		if (line[i + len] == '|')
			return (len);
		len++;
	}
	return (len);
}

t_list	*get_tokens(char *line, t_list *token)
{
	int		len;
	int		i;
	char	*tmp;

	len = 0;
	i = 0;
	while (line[i])
	{
		while ((line[i] == ' ' || line[i] == '\t') && line[i])
			i++;
		len = len_token(line, i);
		tmp = ft_substr(line, i, len);
		ft_lstadd_back(&token, ft_lstnew(tmp));
		i += len;
	}
	free (line);
	return (token);
}
