/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:28:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/29 17:54:49 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

# include <stddef.h>
# include "env.h"

typedef struct		s_dispatcher
{
	char			*name;
	int				(*ft_)(t_env *env, char **av);//ptr sur built_in
}					t_dispatcher;

int		ft_echo(t_env *env, char **av);
int		ft_cd(t_env *env, char **av);
int		ft_env(t_env *env, char **av);
int		ft_setenv(t_env *env, char **av);
int		ft_unsetenv(t_env *env, char **av);
int		ft_exit(t_env *env, char **av);

#endif
