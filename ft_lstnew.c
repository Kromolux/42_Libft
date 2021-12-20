/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:03:05 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/18 22:21:06 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;
	size_t	size;
	
	size = ft_strlen((char *) content) + 1;
	new_element = (t_list *) malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	new_element->content = (char *) malloc(sizeof(char *) * size);
	if (!new_element->content)
		return (NULL);
	ft_memcpy(new_element->content, content, size);
	new_element->next = NULL;
	return (new_element);
}
