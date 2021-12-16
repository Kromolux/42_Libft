/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:02:49 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/16 11:24:51 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	int				result;
	size_t			i;

	ptr_s1 = (unsigned char *) s1;
	ptr_s2 = (unsigned char *) s2;
	i = 0;
	result = 2;
	while (result == 2 && i < n)
	{
		if (ptr_s1[i] < ptr_s2[i])
			return (ptr_s1[i] - ptr_s2[i]);
		else if (ptr_s1[i] > ptr_s2[i])
			return (ptr_s1[i] - ptr_s2[i]);
		i++;
	}
	if (result == 2)
		result = 0;
	return (result);
}
