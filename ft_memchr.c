/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:00 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/21 10:02:15 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*ptr;

	i = 0;
	x = (unsigned char) c;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		if (ptr[i] == x)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
