/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_expanding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:22:17 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/26 22:34:33 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

int			ft_is_escaped(char *str, int i)
{
	int		cnt;

	cnt = 1;
	while (str[-cnt] == '\\' && cnt <= i)
		cnt++;
	return ((cnt - 1) % 2);
}

char		*ft_construct_expansion(char *arg, char *expansion, size_t var_pos, size_t var_len)
{
	size_t		i;
	size_t		len;
	char		*res;

	i = 0;
	len = ft_strlen(expansion);
	if (!(res = (char*)malloc(len + ft_strlen(arg) - var_len + 1)))
		return (NULL);
	while (i < var_pos)
	{
		res[i] = arg[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		res[var_pos + i] = expansion[i];
		i++;
	}
	i = var_pos;
	while (arg[i + var_len])
	{
		res[i + len] = arg[i + var_len];
		i++;
	}
	res[len + i] = '\0';
	return (res);
}

static void	ft_dollar_expand(t_env *env, t_arglist *arg)
{
	size_t	i;
	char	*expansion;

	i = 0;
	while ((arg->arg)[i])
	{
		expansion = NULL;
		if ((arg->arg)[i] == '$' && !(ft_is_escaped(arg->arg + i, i)))
		{
			if (arg->arg[i + 1] == '-')
			{
				if ((expansion = ft_get_env_var(env, "OLDPWD")))
					expansion = ft_construct_expansion(arg->arg, expansion, i, 2);
				else
					ft_memmove(arg->arg + i, arg->arg + i + 2, ft_strlen(arg->arg + i + 2) + 1);
			}
			else if (arg->arg[i + 1] == '+')
			{
				if ((expansion = ft_get_env_var(env, "PWD")))
					expansion = ft_construct_expansion(arg->arg, expansion, i, 2);
				else
					ft_memmove(arg->arg + i, arg->arg + i + 2, ft_strlen(arg->arg + i + 2) + 1);
			}
			else
			{
				if ((expansion = ft_get_env_var(env, "HOME")))
					expansion = ft_construct_expansion(arg->arg, expansion, i, 1);
				else
					ft_memmove(arg->arg + i, arg->arg + i + 1, ft_strlen(arg->arg + i + 1) + 1);
			}
		}
		if (expansion)
		{
			free(arg->arg);
			arg->arg = expansion;
		}
		i++;
	}
}

static void	ft_tilde_expand(t_env *env, t_arglist *arg)
{
	size_t	i;
	char	*expansion;

	i = 0;
	while ((arg->arg)[i])
	{
		expansion = NULL;
		if ((arg->arg)[i] == '~' && !(ft_is_escaped(arg->arg + i, i)))
		{
			if (arg->arg[i + 1] == '-')
			{
				if ((expansion = ft_get_env_var(env, "OLDPWD")))
					expansion = ft_construct_expansion(arg->arg, expansion, i, 2);
				else
					ft_memmove(arg->arg + i, arg->arg + i + 2, ft_strlen(arg->arg + i + 2) + 1);
			}
			else if (arg->arg[i + 1] == '+')
			{
				if ((expansion = ft_get_env_var(env, "PWD")))
					expansion = ft_construct_expansion(arg->arg, expansion, i, 2);
				else
					ft_memmove(arg->arg + i, arg->arg + i + 2, ft_strlen(arg->arg + i + 2) + 1);
			}
			else
			{
				if ((expansion = ft_get_env_var(env, "HOME")))
					expansion = ft_construct_expansion(arg->arg, expansion, i, 1);
				else
					ft_memmove(arg->arg + i, arg->arg + i + 1, ft_strlen(arg->arg + i + 1) + 1);
			}
		}
		if (expansion)
		{
			free(arg->arg);
			arg->arg = expansion;
		}
		i++;
	}
}
/*
static void	ft_full_expand()
{
	
}

static void	ft_dquote_expand()
{

}
*/
void		ft_var_expanding(t_env *env, t_arglist *voyager)
{
/*	while (voyager)
	{
		if (voyager->delim == '\"')
			ft_dquote_expand(voyager, env);
		if (voyager->delim == ' ')
			ft_full_expand(voyager, env);
		voyager = voyager->next;
	}*/
	while (voyager)
	{
		ft_tilde_expand(env, voyager);
		if (voyager->delim == '$')
			ft_dollar_expand(env, voyager);
		voyager = voyager->next;
	}
}
