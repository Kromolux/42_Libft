/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:43:22 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/16 10:54:15 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*substring;

	substring = (char *) malloc(ft_strlen(s) + 1);
	if (!s || !f || !substring)
		return (0);
	i = 0;
	while (s[i])
	{
		substring[i] = f(i, s[i]);
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
