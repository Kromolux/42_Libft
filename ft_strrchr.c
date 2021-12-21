/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 10:38:01 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/21 10:05:28 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	x;
	char			*ptr;

	i = ft_strlen(s);
	x = (unsigned char) c;
	while (i >= 0)
	{
		if (s[i] == x)
		{
			ptr = (char *) &s[i];
			return (ptr);
		}
		i--;
	}
	return (NULL);
}
