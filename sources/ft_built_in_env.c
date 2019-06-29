/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:31:48 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/29 19:20:14 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "dispatcher.h"

static int	ft_create_all_var(t_env *env, char **av)
{
	size_t	i;
	char	*var_value;

	i = 0;
	while (av[++i])
	{
		var_value = ft_strchr(av[i], '=');
		*var_value = '\0';
		var_value++;
		ft_set_env_var(env, av[i], var_value);
	}
	return (EXEC_SUCCESS);
}

static int	ft_all_args_are_var(char **av)
{
	size_t	i;

	i = 0;
	while (av[++i])
		if (!(ft_strchr(av[i], '=')))
			break ;
	return (!(av[i]));
}

int		ft_setenv(t_env *env, char **av)
{
	size_t	len;

	len = ft_tablen(av);
	if (len == 1)
		return (ft_env(env, av));
	if (ft_all_args_are_var(av))
		return (ft_create_all_var(env, av));
	if	(ft_strchr(av[1], '='))
		ft_printf("%s: setenv: No '=' allowed in variable name\n", NAME);
	else if (len < 4)
	{
		ft_set_env_var(env, av[1], (len == 3) ? av[2] : NULL);
		return (EXEC_SUCCESS);
	}
	else
	{
		ft_printf("%s: setenv: wrong number of arg\n", NAME); 
		ft_putendl("setenv: usage: setenv VAR [VALUE]");
	}
	return (EXEC_FAILURE);
}

int		ft_unsetenv(t_env *env, char **av)
{
	if (ft_tablen(av) == 2)
	{
		ft_unset_env_var(env, av[1]);
		return (EXEC_SUCCESS);
	}
	return (EXEC_FAILURE);
}
