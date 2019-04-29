/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 01:47:34 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/29 22:29:41 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_flistfree(t_arglist **alst)
{
	t_arglist	*next;

	while (alst && *alst)
	{
		next = (*alst)->next;
		ft_flistfreeone(alst);
		(*alst) = next;
	}
}
