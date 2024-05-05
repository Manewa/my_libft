/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:32:50 by namalier          #+#    #+#             */
/*   Updated: 2023/11/22 11:23:10 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;

	if (!lst || !f || !del)
		return (NULL);
	begin = ft_lstnew(f(lst->content));
	new = begin;
	while (lst && lst->next)
	{
		if (!new)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		new->next = ft_lstnew(f(lst->next->content));
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
