/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 13:33:11 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/29 19:19:59 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd.h"
#include "libft.h"
#include "minishell.h"
#include <unistd.h>
#include <stdlib.h>

static int		ft_update_pwd(t_env * env, char *new_pwd, char flag)
{
	char	*old_pwd;
	char	pwd[PATH_MAX];

	if (chdir(new_pwd) == -1)
	{
		if (!(flag))
			free(new_pwd);
		return (TARGET_NOT_FOUND);
	}
	old_pwd = ft_get_env_var(env, "PWD");
	ft_set_env_var(env, "OLDPWD", old_pwd);
	getcwd(pwd, PATH_MAX);
	ft_set_env_var(env, "PWD", pwd);
	if (!(flag))
	{
		ft_set_env_var(env, "_", "cd");
		free(new_pwd);
	}
	else
		ft_set_env_var(env, "_", new_pwd);
	free(old_pwd);
	return (EXEC_SUCCESS);
}


int				ft_cd_exec(t_env *env, char *new_pwd)
{
	char	*target;

	if (!(new_pwd))
	{
		if ((target = ft_get_env_var(env, "HOME")))
			return (ft_update_pwd(env, target, 0));
		else
			ft_printf("%s: cd: HOME not set\n", NAME);
			return (EXEC_FAILURE);
	}
	if (!(ft_strcmp(new_pwd, "-")))
	{
		if ((target = ft_get_env_var(env, "OLDPWD")))
			return (ft_update_pwd(env, target, 0));
		else
		{
			ft_printf("%s: cd: OLDPWD not set\n", NAME);
			return (EXEC_FAILURE);
		}
	}
	else
		return (ft_update_pwd(env, new_pwd, 1));
	return (EXEC_SUCCESS);
}

static int	ft_find_target(size_t *i, char **av)
{
	size_t	len;

	*i = 1;
	if ((len = ft_tablen(av)) == 1)
		return (TARGET_FOUND);
	while (*i < len)
	{
		if (av[*i][0] == '-' && ft_strlen(av[*i]) > 1
		&& av[*i][ft_strspn(av[*i] + 1, CD_OPT)] != '\0')
			return (INVALID_OPTION);
		(*i)++;
	}
	*i = 1;
	while (*i < len)
	{
		if (av[*i][0] != '-' || !(ft_strcmp(av[*i], "-")))
			break ;
		(*i)++;
	}
	return (TARGET_FOUND);
}

int			ft_cd(t_env *env, char **av)
{
	int		result;
	size_t	target_index;

	result = ft_find_target(&target_index, av);
	if (result == INVALID_OPTION)
		ft_printf("%s: cd: %s: invalid option\ncd: usage: cd [-L|-P] [dir]\n",
											NAME, av[target_index]);
	if (result != TARGET_FOUND)
		return (EXEC_FAILURE);
	result = ft_cd_exec(env, av[target_index]);
	if (result == TARGET_NOT_FOUND)
		ft_printf("%s: cd: %s: No such file or directory\n",
		NAME, (ft_strcmp(av[target_index], "-")) ? av[target_index] : "OLDPWD");
	return (result);
}
