/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:36:03 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/21 10:03:56 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	s_len;
	char			*ptr;

	s_len = ft_strlen(s) + 1;
	ptr = (char *) malloc(s_len);
	if (ptr)
	{
		ft_strlcpy(ptr, s, s_len);
		return (ptr);
	}
	return (NULL);
}
