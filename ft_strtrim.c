/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:34:33 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/18 21:24:24 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	const	*ft_find_start(char const *s1, char const *set);
static char	const	*ft_find_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*substring;
	char const	*sub_start;
	char const	*sub_end;
	int			sub_size;

	if (!s1 || !set)
		return (0);
	sub_start = ft_find_start(s1, set);
	sub_end = ft_find_end(s1, set);
	sub_size = (int)(sub_end - sub_start) + 2;
	if (sub_size <= 0)
		sub_size = 1;
	substring = malloc(sub_size);
	if (!substring)
		return (0);
	ft_strlcpy(substring, sub_start, sub_size);
	return (substring);
}

static char const	*ft_find_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == 0)
			return (&s1[i]);
		i++;
	}
	return (&s1[i]);
}

static char const	*ft_find_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_strchr(set, s1[i]) == 0)
			return (&s1[i]);
		i--;
	}
	return (&s1[i]);
}
