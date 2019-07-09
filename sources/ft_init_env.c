/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:06:38 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/04 20:00:45 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>

static int		ft_def_env_gen(t_env *env)
{
	char	pwd[PATH_MAX];

	if (!(env->value = (char**)malloc(2 * sizeof(char*))))
		ft_crisis_exit(MALLOC_ERR);
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
	extern char		**environ;
	char			*shlvl;
	int				lvl;

	env->empty_lines = 0;
	if (!(environ[0]))
		ft_def_env_gen(env);
	else
	{
		if (!(env->value = ft_tabcpy(environ)))
			ft_crisis_exit(MALLOC_ERR);
		if ((shlvl = ft_get_env_var(env, "SHLVL")))
		{
			lvl = ft_atoi(shlvl) + 1;
			free(shlvl);
			shlvl = ft_itoa(lvl);
			ft_set_env_var(env, "SHLVL", shlvl);
			free(shlvl);
		}
		else
			ft_set_env_var(env, "SHLVL", "1");
	}
}
