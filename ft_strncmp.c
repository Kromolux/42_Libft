/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:22:52 by rkaufman          #+#    #+#             */
/*   Updated: 2021/11/30 15:35:24 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		result;
	size_t	i;

	i = 0;
	result = 2;
	while (result == 2 && i < n)
	{
		if (s1[i] < s2[i])
		{
			result = s1[i] - s2[i];
		}
		else if (s1[i] > s2[i])
		{
			result = s1[i] - s2[i];
		}
		else if (s1[i] == '\0' && s2[i] == '\0')
		{
			result = 0;
		}
		i++;
	}
	if (result == 2)
		result = 0;
	return (result);
}
