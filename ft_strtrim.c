/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:34:33 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/07 13:58:18 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	void	*substring;
	size_t	s1_len;
	size_t	set_len;
	size_t	s1_start;
	size_t	s1_end;

	s1_len = ft_strlen(s1);

	substring = malloc(s1_len + 1);
	if (!substring)
		return (0);
	if (ft_strncmp(s1, set, set_len) == 0)
		s1_start = set_len + 1;
	else
		s1_start = 0;
	if (ft_strncmp(&s1[s1_len - set_len], set, set_len) == 0)
		s1_end = set_len;
	else
		s1_end = 0;

	ft_memcpy(substring, s1[s1_start], s1_len - (s1_start + s1_end));

	return ((char *) substring);
}
