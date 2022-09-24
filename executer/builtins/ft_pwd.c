/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nedebies <nedebies@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:36:57 by nedebies          #+#    #+#             */
/*   Updated: 2022/09/01 17:07:37 by nedebies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(t_shell *data)
{
	char	*str;
	t_list	**is_envp_list;

	is_envp_list = &data->envp_list;
	str = ft_getenv(*is_envp_list, "PWD");
	if (str)
	{
		write(STDOUT_FILENO, str, ft_strlen(str));
		write(STDOUT_FILENO, "\n", 1);
	}
	ft_print_error(data, NULL, 0);
}
