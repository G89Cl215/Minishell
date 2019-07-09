/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:45:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/07/08 16:48:54 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t	ft_listlen(t_arglist *voyager)
{
	size_t	i;

	i = 0;
	while (voyager)
	{
		i++;
		voyager = voyager->next;
	}
	return (i);
}
