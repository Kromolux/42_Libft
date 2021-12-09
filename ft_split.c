/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:54:11 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/09 11:18:07 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int analyze_str(char const *s, char c);
static void			split_str(char const *s, char c, char **array);

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	entries;
	char			**array;

	i = 0;
	entries = 0;
	size = analyze_str(s,c, &entries);
	array = (char **) malloc(entries + 1);
	while (i < entries)
	{
		array[i] = (char *) malloc(size);
		i++;
	}
	if (!array)
		return(0);
	array[entries][0] = NULL;
	split_str(s, c, array);
	return (array);
}

static unsigned int analyze_str(char const *s, char c, unsigned int *entries)
{
	unsigned int	i;
	unsigned int	count;
	unsigned int	max;

	i = 0;
	count = 0;
	max = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (count > max)
				max = count;
			count = 0;
			*entries++;
		}
		i++;
		count++;
	}
	return (max + 1);
}

static void			split_str(char const *s, char c, char **array)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	entry;

	i = 0;
	start = 0;
	entry = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			ft_strlcpy(array[entry], s[start], start - i);
			start = i;
			entry++;
		}
		i++;
	}
	ft_strlcpy(array[entry], s[start], ft_strlen(s) - start);
}
