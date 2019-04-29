/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:06:55 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/29 22:39:07 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordlen(char *str, char delim)
{
	size_t	len;

	len = 1;
	while ((str[len]) && str[len] != delim)
	{
		if (str[len] == '\\')
		{
			ft_memmove(str + len, str + len + 1, ft_strlen(str + len));
			len++;
			continue ;
		}
		if (delim == ' ' && (str[len] == '\'' || str[len] == '\"'))
		{
			ft_memmove(str + len, str + len + 1, ft_strlen(str + len));
			delim = str[len];
		}
		len++;
	}
/*	if (delim != ' ' && !(str[len]))
		faire intervenir les foctions dquotes et quotes */
	return (len - 1);
}

static size_t	ft_count_args(t_arglist *arg_list)
{
	size_t	ac;
	while (arg_list->next)
	{
		ac += arg_list->to_link;
		arg_list = arg_list->next;
	}
	return (ac);
}

static char		**ft_make_args(t_arglist *arg_list)
{
	size_t	i;
	size_t	ac;
	char	**av;
	t_arglist	*voyager;

	i = 0;
	ac = ft_count_args(arg_list);
	voyager = arg_list;
	if (!(av = (char**)malloc(sizeof(char*) * (ac + 1))))
		return (NULL);
	while (voyager)
	{
		if (!(av[i] = ft_strdup(voyager->arg)))
			return (NULL);
		while (!(voyager->to_link))
		{
			voyager = voyager->next;
			if (!(ft_strappend(&(av[i]), &(voyager->arg))))
				return (NULL);
		}
		voyager = voyager->next;
		i++;
	}
	av[i] = NULL;
	ft_listfree(&arg_list); //double free avec le strappend ?
	return (av);
}

char			**ft_command_parsing(char *cmd)
{
	size_t		i;
	size_t		len;
	int			flag;
	t_arglist		*arg_list;
	t_arglist		*new_link;

	len = ft_wordlen(cmd, ' ');
	ft_listadd_back(&arg_list, ft_listnewword(cmd, len));
	i += len + 1;
	while (cmd[i])
	{
		while (cmd[i] == ' ' && cmd[i + 1] == ' ')
			i++;
		if (cmd[i] == '\'' || cmd[i] == '\"' || cmd[i] == ' ')
		{
			len = ft_wordlen(cmd + i, cmd[i]);
			new_link = ft_listnewword(cmd + i + 1, len);
			i += len + 1;
			new_link->to_link = (cmd[i + 1] == ' ');
			ft_listadd_back(&arg_list, new_link);
		}
		i++;
	}
	return (ft_make_args(arg_list));
}
