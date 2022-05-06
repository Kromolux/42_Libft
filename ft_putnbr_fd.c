/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:25:04 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/17 13:29:09 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	output[12];
	long	tmp;
	int		i;
	int		sign;

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
	{
		i--;
		output[i] = '-';
	}
	ft_putstr_fd(&output[i], fd);
}
