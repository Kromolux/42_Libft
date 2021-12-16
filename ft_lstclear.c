/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:30:33 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/11 20:32:37 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	int	i;

	i = ft_lstsize(lst[0]) - 1;
	while (i >= 0)
	{
		del(lst[0][i].content);
		free(lst[0][i].content);
		del(lst[0][i].next);
		free(lst[0][i].next);
		i--;
	}
	lst[0] = NULL;
}
