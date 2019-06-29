/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:08:10 by tgouedar          #+#    #+#             */
/*   Updated: 2019/06/25 14:06:57 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stddef.h>

typedef struct				s_arglist
{
	char					*arg;
	char					to_link;
	char					delim;
	struct s_arglist		*next;
}							t_arglist;

t_arglist				*ft_listnewstr(char const *content);
t_arglist				*ft_listnewword(char const *content, size_t n);
void					ft_listadd(t_arglist **alst, t_arglist *new_nod);
void					ft_listadd_back(t_arglist **alst, t_arglist *new_back);
void					ft_listfree(t_arglist **alst);
void					ft_listfreeone(t_arglist **alst);

#endif
