/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:57:35 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/21 10:03:19 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned int	s_len;

	i = 0;
	s_len = ft_strlen(s) + 1;
	while (i < s_len)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
