/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:46:24 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/29 22:37:54 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"


char	**ft_command_parsing(char *cmd);

void	ft_display_prompt(void)
{
	ft_putstr("Ceci n'est pas un prompt : ");
}


int		ft_fork_and_exec(char **av)
{
	pid_t		father;
	int			status;

	if (!(ft_strcmp(*av, "exit")) || !(ft_strcmp(*av, "quit")))
		return 0; // (EXIT_SIGNAL);
	father = fork();
	if (father == 0)
		execve("/bin/ls", av, NULL);
	if (father > 0)
	{
		wait(&status);
		ft_putendl(*av);
	}
//	ft_free_tab(av);
	return (1);
}

int		main(void)
{
	char		*line;
	char		**cmd_av;
//	env; /*quelle forme ?*/

//	ft_init_env(env);
	while (1)
	{
	ft_display_prompt();
		if ((get_next_line(0, &line)) > 0)
		{
			if (!(cmd_av = ft_command_parsing(line)))
				ft_display_err(cmd_av);
			else if (ft_fork_and_exec(cmd_av) == 0)// EXIT_SIGNAL)
				break ;
		}
	}
	return (0);
}
