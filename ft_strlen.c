/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:57:45 by rkaufman          #+#    #+#             */
/*   Updated: 2021/11/18 16:44:38 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	char	*teststring = {"How awsome is this VirtualBox!?!"};
	printf("return value of ft_strlen(\"%s\") = %i\n", teststring, ft_strlen(teststring));
	return	(0);
}
