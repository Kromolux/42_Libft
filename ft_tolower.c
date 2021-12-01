/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:52:44 by rkaufman          #+#    #+#             */
/*   Updated: 2021/11/23 09:58:18 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	x;

	x = (unsigned char) c;
	if (x >= 'A' && x <= 'Z')
	{
		return ((int)(x + (char) 32));
	}
	else
	{
		return (c);
	}
}
