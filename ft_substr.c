/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:12:02 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/20 19:08:39 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	void	*substring;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		substring = ft_calloc(1, s_len + 1);
	else
		substring = ft_calloc(1, len + 1);
	if (!substring)
		return (NULL);
	if (start <= s_len)
	{
		ft_memcpy(substring, (const void *) &s[start], len);
		((char *) substring)[len] = '\0';
		return ((char *) substring);
	}
	return ((char *) substring);
}
