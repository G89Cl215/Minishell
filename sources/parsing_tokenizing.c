/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tokenizing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:23:48 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/29 12:55:44 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

static t_arglist	*ft_next_token(char *str, size_t *len, char *flag)
{
	size_t			i;
	t_arglist		*new_link;

	i = 0;
	*flag = 0;
	while ((str[i]) && str[i] != ' ' && str[i] != '\t'
		&& str[i] != '\'' && str[i] != '\"')
	{
		if (str[i++] == '\\' && !(str[i++]))
		{
			i--;
			*flag = NEWLINE;
			break ;
		}
	}
	new_link = ft_listnewword(str, i);
	if ((*flag))
		new_link->arg[i - 1] = '\0';
	new_link->delim = ' ';
	new_link->to_link = (str[i] == ' ' || str[i] == '\t'
										|| (str[i] == '\0' && !(*flag)));
	*len += i;
	return (new_link);
}

static t_arglist	*ft_next_quoted_token(char *str, size_t *len, char *flag)
{
	size_t			i;
	t_arglist		*new_link;

	i = 0;
	*flag = 0;
	while ((str[i]) && str[i] != '\'')
		i++;
	if (!(str[i]))
	{
		*flag = QUOTES;
		i++;
	}
	new_link = ft_listnewword(str, i);
	if ((*flag))
	{
		new_link->arg[i--] = '\0';
		new_link->arg[i--] = '\n';
	}
	new_link->delim = '\'';
	i++;
	new_link->to_link = (str[i] == ' ' || str[i] == '\t'
										|| (str[i] == '\0' && !(*flag)));
	*len += i;
	return (new_link);
}

static t_arglist	*ft_next_dquoted_token(char *str, size_t *len, char *flag)
{
	size_t			i;
	t_arglist		*new_link;

	i = 0;
	*flag = 0;
	while ((str[i]) && str[i] != '\"')
		i++;
	if (!(str[i]))
	{
		*flag = DQUOTES;
		i++;
	}
	new_link = ft_listnewword(str, i);
	if ((*flag))
	{
		new_link->arg[i--] = '\0';
		new_link->arg[i--] = '\n';
	}
	new_link->delim = '\"';
	i++;
	new_link->to_link = (str[i] == ' ' || str[i] == '\t'
										|| (str[i] == '\0' && !(*flag)));
	*len += i;
	return (new_link);
}

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

t_arglist			*ft_tokenizing(char *cmd, char flag)
{
	size_t			i;
	t_arglist		*arg_list;
	t_arglist		*new_link;

	i = 0;
	arg_list = NULL;
	if (!(cmd[i]) && (flag))
		ft_listadd_back(&arg_list, ft_listnewstr("\n"));
	while ((cmd[i]))
	{
		new_link = NULL;
		while ((cmd[i] == ' ' || cmd[i] == '\t')
			&& (flag == 0 || flag == NEWLINE))
			i++;
		if (flag == QUOTES || ((cmd[i] == '\'') && (++i)))
			new_link = ft_next_quoted_token(cmd + i, &i, &flag);
		else if (flag == DQUOTES || ((cmd[i] == '\"') && (++i)))
			new_link = ft_next_dquoted_token(cmd + i, &i, &flag);
		else if ((cmd[i]))
			new_link = ft_next_token(cmd + i, &i, &flag);
		ft_listadd_back(&arg_list, new_link);
	}
	if ((flag))
		ft_listadd_back(&arg_list, ft_multiline_command(flag));
	return (arg_list);
}
