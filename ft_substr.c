/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:12:02 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/21 10:07:01 by rkaufman         ###   ########.fr       */
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
		substring = malloc(s_len + 1);
	else
		substring = malloc(len + 1);
	if (!substring)
		return (NULL);
	if (start <= s_len)
	{
		ft_strlcpy((char *) substring, &s[start], len + 1);
		return ((char *) substring);
	}
	((char *) substring)[0] = '\0';
	return ((char *) substring);
}
