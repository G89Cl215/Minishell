/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:06:55 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/26 20:35:38 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>


/*
static size_t	ft_wordlen(char *str)
{
	size_t	len;
	char	delim;

	len = 0;
	delim = (*str =='\'' || *str == '\"') ? *str : ' ';
	if (*str =='\'' || *str == '\"')
	   str++;
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
			delim = str[len];
			ft_memmove(str + len, str + len + 1, ft_strlen(str + len));
			len--;
		//	printf("new_delim : %c\n", delim);
		}
		len++;
	}
	if (delim != ' ' && !(str[len]))
		faire intervenir les foctions dquotes et quotes
	return (len);
}*/



static size_t	ft_count_args(t_arglist *arg_list)
{
	size_t	ac;

	ac = 0;
	while (arg_list)
	{
		ac += arg_list->to_link;
		arg_list = arg_list->next;
	}
	return (ac);
}

static char		**ft_make_args(t_arglist *arg_list)
{
	size_t		i;
	size_t		ac;
	char		**av;
	t_arglist	*voyager;

	i = 0;
	ac = ft_count_args(arg_list);
	voyager = arg_list;
	if (!(av = (char**)malloc(sizeof(char*) * (ac + 1))))
		return (NULL);
//	ft_putendl("malloc_ok");
	while (voyager && i < ac)
	{
		if (!(av[i] = ft_strdup(voyager->arg)))
			return (NULL);
//		printf("testword[0]parsed : |%s|\n", av[0]);
		while (!(voyager->to_link))
		{
			voyager = voyager->next;
			if (!(ft_strappend(&(av[i]), &(voyager->arg))))
				return (NULL);
		}
		voyager = voyager->next;
		
//		printf("word[%zu]parsed : |%s|\n", i, av[i]);
		
		i++;
	}
//	printf("before: |%p|, i = %zu\n", av[0], i);
//	printf("testword[0]parsed : |%s|\n", av[0]);
//	printf("%p\n", av[i]);
	av[i] = NULL;
//	printf("testword[0]parsed : |%s|\n", av[0]);
//	printf("testword[0]parsed : |%p|, i = %zu\n", av[0], i);
//	ft_putendl("arg_v fini");
//	ft_listfree(&arg_list); //double free avec le strappend ?
	return (av);
}
/*
void			ft_print_list(t_arglist *list)
{
	while (list)
	{
		printf("|%s|\n", list->arg);
		ft_putnbr(list->to_link);
		ft_putendl("\n");
		list = list->next;
	}
}
*/

char			**ft_command_parsing(t_env *env, char *cmd)
{
	t_arglist		*arg_list;

	arg_list = ft_tokenizing(cmd, 0);
	ft_var_expanding(env, arg_list);
	return (ft_make_args(arg_list));	
}
