/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:30:33 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/21 14:31:26 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*first_element;
	t_list	*next_element;

	if (lst && del)
	{
		next_element = *lst;
		while (next_element)
		{
			first_element = next_element;
			next_element = next_element->next;
			del(first_element->content);
			free(first_element);
		}
		*lst = NULL;
	}
}
