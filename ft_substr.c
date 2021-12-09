/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:12:02 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/07 13:23:30 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	void	*substring;

	substring = malloc(len);
	if (!substring)
		return (0);
	ft_memcpy(substring, (const void *) &s[start], len);
	return ((char *) substring);
}
