/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:21:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/29 22:29:37 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_listadd_back(t_arglist **alst, t_arglist *new_back)
{
	t_argflist	*voyager;

	if (!alst)
		return ;
	if (!(*alst))
		*alst = new_back;
	else
	{
		voyager = *alst;
		while (voyager->next)
			voyager = voyager->next;
		voyager->next = new_back;
	}
}
