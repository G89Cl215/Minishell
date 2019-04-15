/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:46:24 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/06 14:07:09 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "../../Ma_Libft/libft.h"


int		main(int ac, char **av)
{
	pid_t		father;
	char		*line;
	int			status;

	(void)ac;
	ft_putstr("Ceci n'est pas un prompt : ");
	while (1)
	{
		if ((get_next_line(0, &line)) > 0)
		{
			if (ft_strcmp(line, "exit") && ft_strcmp(line, "quit"))
			{
				father = fork();
				if (father == 0)
					execve("/bin/ls", av, NULL);
				if (father > 0)
				{
					wait(&status);
					ft_putendl(line);
					ft_putstr("Ceci n'est pas un prompt : ");
				}

			}
			else
				break ;
		}
	}
}
