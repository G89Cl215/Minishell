/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:21:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/05/06 18:14:04 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_listadd_back(t_arglist **alst, t_arglist *new_back)
{
	t_arglist	*voyager;

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
