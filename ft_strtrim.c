/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:34:33 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/16 14:39:19 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	void	*substring;
	size_t	s1_len;
	size_t	set_len;
	size_t	i_s1;
	size_t	i_set;
	size_t	s1_start;
	size_t	s1_end;

	if (!s1 || !set)
		return (0);
	i_s1 = 0;
	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	substring = malloc(s1_len + 1);
	if (!substring)
		return (0);
	while (i_s1 < s1_len)
	{
		i_set = 0;
		while (i_set < set_len)
		{
			if (s1[i_s1] != set[i_set])
			{
				((char *) substring)[i_sub] = s1[i_s1];
				i_sub++;
			}
			i_set++;
		}
		i_s1++;
	}
	if (ft_strncmp(s1, set, set_len) == 0)
		s1_start = set_len;
	else
		s1_start = 0;
	if (ft_strncmp(&s1[s1_len - set_len], set, set_len) == 0)
		s1_end = set_len;
	else
		s1_end = 0;
	ft_memcpy(substring, (void *) (&s1[s1_start]), s1_len - (s1_start + s1_end));
	((char *) substring)[s1_len - (s1_start + s1_end)] = '\0';
	return ((char *) substring);
}
