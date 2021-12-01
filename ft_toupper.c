/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:44:55 by rkaufman          #+#    #+#             */
/*   Updated: 2021/11/23 09:58:08 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	x;

	x = (unsigned char) c;
	if (x >= 'a' && x <= 'z')
	{
		return ((int)(x - (char) 32));
	}
	else
	{
		return (c);
	}
}
