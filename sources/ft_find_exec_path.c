/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_exec_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:28:36 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/24 16:34:33 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "libft.h"
#include "minishell.h"

char	*ft_find_exec_path(t_env *env, char *exec)
{
	DIR				*dir;
	struct dirent	*dirdata;
	size_t			i;
	char			**path;
	char			*res;

	if ((ft_get_env_var(env, "PATH")))
	{
		path = ft_strsplit(ft_get_env_var(env, "PATH"), ':');
		i = 0;
		while (path[i])
		{
			if ((dir = opendir(path[i])))
			{
				while ((dirdata = readdir(dir)))
					if (!(ft_strcmp(dirdata->d_name, exec)))
					{
						closedir(dir);
						res = ft_strdup(path[i]);
						ft_tabfree(path);
						return (res);
					}
				}
				i++;
				closedir(dir);
		}
		ft_tabfree(path);
	}
	return (NULL);
}
