/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:57:58 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/10 15:42:54 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (n > 0)
	{
		i = 0;
		if (dest < src)
		{
			while (i < n)
			{
				((char *) dest)[i] = ((const char *) src)[i];
				i++;
			}
		}
		else
		{
			while (i < n)
			{
				((char *) dest)[n - i] = ((const char *) src)[n - i];
				i++;
			}
		}
	}
	return (dest);
}
