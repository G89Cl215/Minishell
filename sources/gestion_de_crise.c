/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_de_crise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:41:39 by tgouedar          #+#    #+#             */
/*   Updated: 2019/05/20 16:08:05 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minishell.h"

void	ft_display_err(char **av)
{
	ft_printf("%s: command not found: %s.\n", NAME, *av);
//	ft_free_tab(av);
}
