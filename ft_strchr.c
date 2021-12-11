/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:57:35 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/10 15:37:05 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	s_len;
	char			x;
	char			*ptr;

	i = 0;
	s_len = ft_strlen(s);
	x = (char) c;
	while (i <= s_len)
	{
		if (s[i] == x)
		{
			ptr = (char *) &s[i];
			return (ptr);
		}
		i++;
	}
	return (0);
}
