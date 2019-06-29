/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:17:05 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/29 19:11:47 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "list.h"
# include "env.h"

# define NAME "minishell"
# define NOT_BI			-1
# define EXIT_SIGNAL	-2
# define EXEC_SUCCESS	0
# define EXEC_FAILURE	1
# define MALLOC_ERR		-5
# define PATH_MAX		4096
# define NEWLINE		1
# define DQUOTE_EXPAND	""
# define QUOTES			2
# define DQUOTES		3

void		ft_display_err(char **av);
void		ft_display_prompt(char flag);
char		**ft_command_parsing(t_env *env, char *cmd);
void		ft_init_env(t_env *env);
char		*ft_find_exec_path(t_env *env, char *exec);
int			ft_built_in(t_env *env, char **av);
char		*ft_find_exec(t_env *env, char *to_find);
char		*ft_get_env_var(t_env *env, char *var);
int			ft_set_env_var(t_env *env, char *var_name, char *var_value);
void		ft_unset_env_var(t_env *env, char *var_name);
t_arglist	*ft_tokenizing(char *cmd, char flag);
void		ft_var_expanding(t_env *env, t_arglist *voyager);

#endif
