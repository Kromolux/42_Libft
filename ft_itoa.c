/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:17:16 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/09 08:50:19 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(int number);

char	*ft_itoa(int n)
{
	char	*substring;
	long	tmp;
	int		i;
	int		sign;

	substring = (char *) malloc(12);
	if (!substring)
		return (0);
	substring[11] = '\0';
	i = 10;
	sign = check_sign(n);
	tmp = (long) n * sign;
	if (tmp == 0)
		substring[i] = '0';
	while (tmp > 0)
	{
		substring[i] = (tmp % 10) + '0';
		tmp = tmp / 10;
		i--;
	}
	if (sign == -1)
		substring[i] = '-';
	else
		i++;
	ft_memmove(&substring[0], &substring[i], 12 - i)
	return (substring);
}

static int	check_sign(int number)
{
	if (number < 0)
		return (-1);
	else
		return (1);
}
