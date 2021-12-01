/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:20:26 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/01 16:35:45 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	count_minus;
	int	sign;
	int	i;

	i = *i_str;
	count_minus = 0;
	sign = 0;
	while (sign == 0)
	{
		if (str[i] == '-')
			count_minus++;
		else if (str[i] != '+')
		{
			count_minus = count_minus % 2;
			if (count_minus == 0)
				sign = 1;
			else
				sign = -1;
		}
		i++;
	}
	*i_str = --i;
	return (sign);
}
