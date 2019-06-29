/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:06:38 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/24 18:22:39 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>

extern char		**environ;

static int		ft_def_env_gen(t_env *env)
{
	char	pwd[PATH_MAX];

	if (!(env->value = (char**)malloc(2 * sizeof(char*))))
		return (MALLOC_ERR);
	env->value[0] = NULL;
	env->value[1] = NULL;
	env->empty_lines = 1;
	getcwd(pwd, PATH_MAX);
	ft_set_env_var(env, "PWD", pwd);
	ft_set_env_var(env, "SHLVL", "1");
	return (0);
}

void			ft_init_env(t_env *env)
{
	char	*shlvl;

	env->empty_lines  = 0;
	if (!(environ[0]))
		ft_def_env_gen(env);
	else
	{
		env->value = ft_tabcpy(environ);
		if ((shlvl = ft_get_env_var(env, "SHLVL")))
		{
			shlvl = ft_itoa(ft_atoi(shlvl) + 1);
			ft_set_env_var(env, "SHLVL", shlvl);
			free(shlvl);
		}
	}
}
