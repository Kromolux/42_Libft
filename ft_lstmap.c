/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:14:31 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/22 08:37:18 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_element;
	t_list	*first_element;

	if (!lst)
		return (NULL);
	new_element = ft_lstnew(f(lst->content));
	if (!new_element)
		return (NULL);
	first_element = new_element;
	while (lst->next)
	{
		lst = lst->next;
		new_element->next = ft_lstnew(f(lst->content));
		if (!(new_element->next))
		{
			ft_lstclear(&first_element, del);
			return (NULL);
		}
		new_element = new_element->next;
	}
	return (first_element);
}
