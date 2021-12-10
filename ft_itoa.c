/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:17:16 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/10 12:44:38 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	static char	output[12];
	long		tmp;
	int			i;
	int			sign;

	output[11] = '\0';
	i = 10;
	sign = 1;
	if (n < 0)
		sign = -1;
	tmp = (long) n * sign;
	while (tmp > 9)
	{
		output[i] = (char)(tmp % 10) + '0';
		tmp = tmp / 10;
		i--;
	}
	output[i] = (char)(tmp % 10) + '0';
	if (sign == -1)
		output[i] = '-';
	else
		i++;
	ft_memmove((void *) &output[0], (void *) &output[i], 12 - i);
	return (&output[0]);
}
