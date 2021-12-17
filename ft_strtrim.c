/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:34:33 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/17 13:03:49 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_c_will_stay(char const c, char const *set);
static char	const	*ft_find_start(char const *s1, char const *set);
static char	const	*ft_find_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*substring;
	char const	*sub_start;
	char const	*sub_end;
	size_t		sub_size;

	if (!s1 || !set)
		return (0);
	sub_start = ft_find_start(s1, set);
	sub_end = ft_find_end(s1, set);
	sub_size = (size_t)(sub_end - sub_start) + 1;
	substring = malloc(sub_size);
	if (!substring)
		return (0);
	ft_strlcpy(substring, &s1[(size_t) (sub_start - s1)], sub_size);
	return (substring);
}

static int	ft_c_will_stay(char const c, char const *set)
{
	size_t	i_set;
	
	i_set = 0;
	while (set[i_set])
	{
		if (c == set[i_set])
			return (0);
		i_set++;
	}
	return (1);
}

static char const	*ft_find_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_c_will_stay(s1[i], set))
			return (&s1[i]);
		i++;
	}
	return (&s1[i]);
}

static char	const *ft_find_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_c_will_stay(s1[i], set))
			return (&s1[i]);
		i--;
	}
	return (&s1[i]);
}
