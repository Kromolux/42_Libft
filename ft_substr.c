/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:12:02 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/17 11:42:07 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	void	*substring;

	substring = malloc(len + 1);
	if (!substring || !s)
		return (0);
	if (start <= ft_strlen(s))
	{
		ft_memcpy(substring, (const void *) &s[start], len);
		((char *) substring)[len] = '\0';
		return ((char *) substring);
	}
	return ((char *) substring);
}
