/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:20:26 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/20 15:53:07 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_whitespace(const char *str);
static int	check_sign(const char *str, int *i_str);

int	ft_atoi(const char *nptr)
{
	int	output;
	int	sign;
	int	i;

	output = 0;
	i = check_whitespace(nptr);
	sign = check_sign(nptr, &i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		output *= 10;
		output += nptr[i] - '0';
		i++;
	}
	return (output * sign);
}

static int	check_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	return (i);
}

static int	check_sign(const char *str, int *i_str)
{
	int	sign;
	int	i;

	i = *i_str;
	sign = 0;
	if (str[i] == '-')
		sign = -1;
	else if (str[i] == '+')
		sign = 1;
	else if (str[i] >= '0' && str[i] <= '9')
		sign = 1;
	else
		sign = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	*i_str = i;
	return (sign);
}
