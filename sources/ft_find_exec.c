/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:28:22 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/26 22:37:56 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "dispatcher.h"
#include "minishell.h"
#include "libft.h"

t_dispatcher		g_built_in[] =
{
	{"echo", &ft_echo},
	{"cd", ft_cd},
	{"env", &ft_env},
	{"setenv", ft_setenv},
	{"unsetenv", &ft_unsetenv},
	{"exit", &ft_exit},
	{NULL, NULL}
};

static int	ft_is_built_in(char *to_find, size_t *i)
{
	*i = 0;
	while (((g_built_in[*i]).name) && ft_strcmp((g_built_in[*i]).name, to_find))
		(*i)++;
	if ((g_built_in[*i]).name)
		return (1);
	return (0);
}

int		ft_built_in(t_env *env, char **av)
{
	size_t	i;

	if (ft_is_built_in(*av, &i))
		return ((g_built_in[i]).ft_(env, av));
	return (NOT_BI);
}

static	char	*ft_build_path(char *path, char *exec)
{
	size_t	len;
	size_t	slash;
	char	*res;

	slash = ft_strlen(path);
	len = ft_strlen(exec);
	if (!(res = (char*)malloc(len + slash + 2)))
		return (NULL);
	ft_memcpy(res, path, slash);
	res[slash] = '/';
	ft_memcpy(res + slash + 1, exec, len);
	res[slash + len + 1] = '\0';
	return (res);
}

char	*ft_find_exec(t_env *env, char *to_find)
{
	DIR				*dir;
	struct dirent	*dirdata;
	char			*exec;

	if ((exec = ft_strrchr(to_find, '/')))
	{
		*exec = '\0';
		exec++;
		if ((dir = opendir(to_find)))
		{
			while ((dirdata = readdir(dir)))
				if (!(ft_strcmp(dirdata->d_name, exec)))
				{
					closedir(dir);
					exec--;
					*exec = '/';
					return (to_find);
				}
		}
		closedir(dir);
	}
	else if ((exec = ft_find_exec_path(env, to_find)))
		return (ft_build_path(exec, to_find));
	return (NULL);
}
