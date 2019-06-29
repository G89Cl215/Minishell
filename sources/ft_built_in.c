/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 11:14:55 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/29 19:21:19 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <unistd.h> 
#include <stdlib.h> 

int		ft_exit(t_env *env, char **av)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_tablen(av);
	if (len == 2)
	{
		if (ft_strisnum(av[1]))
			i = ft_atoi(av[1]);
		else
		{
			ft_printf("%s: exit: %s: numeric argument required\n", NAME, av[1]);
			return (EXEC_FAILURE);
		}	
	}
	else if (len > 2) 
	{
		ft_printf("%s: exit: too many arguments\n", NAME);
		return (EXEC_FAILURE);
	}
	ft_tabfree(env->value);
	return (EXIT_SIGNAL);
}

int		ft_echo(t_env *env, char **av)
{
	size_t		i;

	i = 1;
	(void)env;
	while (av[i])
	{
		ft_putstr(av[i]);
		if (av[++i])
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (EXEC_SUCCESS);
}

int		ft_env(t_env *env, char **av)
{
	int		i;

	i = 0;
	if (ft_tablen(av) == 1)
		while ((env->value)[i])
			ft_putendl((env->value)[i++]);
	return (EXEC_SUCCESS);
}
