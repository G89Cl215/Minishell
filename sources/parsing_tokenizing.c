/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tokenizing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:23:48 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/13 20:37:26 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

static t_arglist	*ft_multiline_command(char flag)
{
	char			*line;
	t_arglist		*new_link;

	line = NULL;
	new_link = NULL;
	ft_display_prompt(flag);
	if ((get_next_line(0, &line)) > 0)
	{
		new_link = ft_tokenizing(line, flag);
		free(line);
	}
	return (new_link);
}

static t_arglist	*ft_next_token(char *cmd, size_t *i, char *flag)
{
	t_arglist		*new_link;

	new_link = NULL;
	while ((ft_isin(cmd[*i], IFS)) && (*flag == NO_DELIM || *flag == NEWLINE))
		(*i)++;
	if (*flag == QUOTES || (*flag != DQUOTES && cmd[*i] == '\'' && ++(*i)))
		return (ft_next_quoted_token(cmd + *i, i, flag));
	if (*flag == DQUOTES || (*flag != QUOTES && cmd[*i] == '\"' && ++(*i)))
		return (ft_next_dquoted_token(cmd + *i, i, flag));
	if ((cmd[*i]))
		return (ft_next_plain_token(cmd + *i, i, flag));
	return (NULL);
}

t_arglist			*ft_tokenizing(char *cmd, char flag)
{
	size_t			i;
	t_arglist		*arg_list;

	i = 0;
	arg_list = NULL;
	if (!(cmd[i]))
	{
		if (flag == QUOTES || flag == DQUOTES)
			ft_listadd_back(&arg_list, ft_listnewstr("\n", 0, flag));
		else if (flag == NEWLINE)
			flag = NO_DELIM;
	}
	while ((cmd[i]))
		ft_listadd_back(&arg_list, ft_next_token(cmd, &i, &flag));
	if (flag != NO_DELIM)
		ft_listadd_back(&arg_list, ft_multiline_command(flag));
	return (arg_list);
}
