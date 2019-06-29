/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 13:24:32 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/29 18:03:58 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <stdlib.h>

char	*ft_get_env_var(t_env *env, char *var)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(var);
	while ((env->value)[i])
	{
		if (!(ft_strncmp((env->value)[i], var, len))
		&& (env->value)[i][len] == '=')
			return (ft_strdup((env->value)[i] + len + 1));
		i++;
	}
	return (NULL);
}

int		ft_env_index(t_env *env, char *var_name)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(var_name);
	while (((env->value)[i]) && (ft_strncmp((env->value)[i], var_name, len)
	|| (env->value)[i][len] != '='))
		i++;
	return ((env->value[i]) ? i : -1);	
}

char	*ft_new_env(char *var_name, char *var_value)
{
	size_t	i;
	size_t	len;
	char	*new_var;

	i = ft_strlen(var_name);
	len = i + 1 + ((var_value) ? ft_strlen(var_value) : 0);
	if (!(new_var = (char*)malloc(len + 1)))
		return (NULL);
	ft_memcpy(new_var, var_name, i);
	new_var[i] = '=';
	new_var[len] = '\0';
	if (var_value)
		ft_memcpy(new_var + i + 1, var_value, ft_strlen(var_value));
	return (new_var);
}

int		ft_reallocate_env(t_env *env)
{
	size_t	i;
	size_t	len;
	char	**new_tab;

	i = 0;
	len = ft_tablen(env->value);
	if (!(new_tab = (char**)malloc(sizeof(char*) * (2 * len + 1))))
		return (MALLOC_ERR);
	while (i < len)
	{
		if (!(new_tab[i] = ft_strdup(env->value[i])))
			return (MALLOC_ERR);
		i++;
	}
	while (i < 2 * len + 1)
		new_tab[i++] = NULL;
	env->empty_lines = len;
	ft_tabfree(env->value);
	env->value = new_tab;
	return (1);
}

int		ft_set_env_var(t_env *env, char *var_name, char *var_value)
{
	int		i;
	char	*new_var;

	i = ft_env_index(env, var_name);
	if (!(new_var = ft_new_env(var_name, var_value)))
		return (MALLOC_ERR);
	if (i == -1)
	{
		i = 0;
		if (!(env->empty_lines) && ft_reallocate_env(env) == MALLOC_ERR)
			return (MALLOC_ERR);
		while ((env->value)[i])
			i++;
		env->empty_lines--;
	}
	else
		free((env->value)[i]);
	(env->value)[i] = new_var;
	return (1);
}

void	ft_unset_env_var(t_env *env, char *var_name)
{
	int		i;
	int		len;

	i = ft_env_index(env, var_name);
	if (i == -1)
		ft_printf("setenv: no such variable in environnement:%s", var_name);
	else
	{
		len = ft_tablen(env->value);
		ft_strdel(env->value + i);
		if (i < len)
		{
			env->value[i] = (env->value)[i + 1];
			i++;
		}
		env->empty_lines++;	
	}
}
