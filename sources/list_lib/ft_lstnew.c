/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:33:48 by baavril           #+#    #+#             */
/*   Updated: 2019/06/25 13:40:12 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

t_arglist		*ft_listnewstr(char const *arg)
{
	t_arglist *new;

	if (!(new = (t_arglist*)malloc(sizeof(*new))))
		return (NULL);
	if (arg == NULL)
		new->arg = NULL;
	else if (!(new->arg = ft_strdup(arg)))
		return (NULL);
	new->next = NULL;
	return (new);
}

t_arglist		*ft_listnewword(char const *arg, size_t n)
{
	t_arglist *new;

	if (!(new = (t_arglist*)malloc(sizeof(*new))))
		return (NULL);
	if (arg == NULL)
		new->arg = NULL;
	else if (!(new->arg = ft_strndup(arg, n)))
		return (NULL);
	new->next = NULL;
	return (new);
}
