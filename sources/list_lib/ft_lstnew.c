/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:33:48 by baavril           #+#    #+#             */
/*   Updated: 2019/04/29 22:29:50 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

t_list		*ft_listnewstr(char const *arg)
{
	t_arglist *new;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	if (arg == NULL)
		new->arg = NULL;
	else if (!(new->arg = ft_strdup(arg)))
		return (NULL);
	new->next = NULL;
	return (new);
}

t_list		*ft_listnewword(char const *arg, size_t n)
{
	t_arglist *new;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	if (arg == NULL)
		new->arg = NULL;
	else if (!(new->arg = ft_strndup(arg, n)))
		return (NULL);
	new->next = NULL;
	return (new);
}
