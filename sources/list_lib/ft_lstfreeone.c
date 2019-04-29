/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 01:47:36 by tgouedar          #+#    #+#             */
/*   Updated: 2019/04/29 22:29:45 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

void	ft_listfreeone(t_arglist **alst)
{
	if (alst && *alst)
	{
		free((*alst)->file_name);
		ft_memdel((void**)alst);
	}
}
