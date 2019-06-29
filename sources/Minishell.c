/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:46:24 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/26 20:35:20 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "minishell.h"
#include "libft.h"


void	ft_display_prompt(char flag)
{
	if (flag == NEWLINE)
		ft_putstr("> ");
	else if (flag == QUOTES)
		ft_putstr("quotes> ");
	else if (flag == DQUOTES)
		ft_putstr("dquotes> ");
	else
		ft_putstr("Ceci n'est pas un prompt : ");
}

int		ft_fork_and_exec(t_env *env, char **av)
{
	pid_t		father;
	int			status;
	char		*execpath;
	if ((execpath = ft_find_exec(env, av[0])))
	{
		father = fork();
		if (father == 0)
			execve(execpath, av, env->value);
		if (father > 0)
			wait(&status);
		ft_set_env_var(env, "_", execpath);
		ft_tabfree(av);
	}
	else
		ft_display_err(av);
	return (1);
}

int		main(void)
{
	char		*line;
	char		**cmd_av;
	t_env		env;
	int			signal;

	ft_init_env(&env);
	line = NULL;
	while (1)
	{
		ft_display_prompt(0);
		if ((get_next_line(0, &line)) > 0)
		{
			signal = 0;
			if (!(cmd_av = ft_command_parsing(&env, line)))
				ft_display_err(cmd_av);
			
			{
				int			i;

				i = 0;
				while (cmd_av[i])
				{
					ft_printf("{%i} : |%s|\n", i, cmd_av[i]);
					i++;
				}
			}
			if (!(cmd_av[0]))
				continue ;
			signal = ft_built_in(&env, cmd_av);
			if (signal == EXIT_SIGNAL)
				break ;
			else if (signal == NOT_BI)
				ft_fork_and_exec(&env, cmd_av);
		}
		else
			break ;
	}
	return (0);
}
