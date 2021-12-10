/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:24:52 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/10 12:14:14 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	void	*substring;
	char	*sub_pos;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	substring = malloc(s1_len + s2_len + 1);
	if (!substring)
		return (0);
	ft_memcpy(substring, (const void *) s1, s1_len);
	sub_pos = &(((char *) substring)[s1_len + 1]);
	ft_memcpy((void *)sub_pos, (const void *) s2, s2_len + 1);
	return ((char *) substring);
}
