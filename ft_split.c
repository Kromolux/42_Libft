/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:54:11 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/17 16:43:55 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static unsigned int	analyze_str(char const *s, char c, unsigned int *sub_len);
static void			split_str(char const *s, char c, char **array);

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	size;
	unsigned int	c_count;
	char			**array;

	if (!s)
		return (0);
	i = 0;
	c_count = 0;
	size = analyze_str(s, c, &c_count) + 1;
	printf("size = %u\n", size);
	printf("result of c_count = %u\n", c_count);
	array = (char **) malloc(size * sizeof(char *));
	if (!array)
		return (0);
	while (i < size)
	{
		array[i] = (char *) malloc(c_count + 1);
		i++;
	}
	//if (!array)
	//	return (0);
	array[size - 1][0] = 0;
	split_str(s, c, array);
	return (array);
}

static unsigned int	analyze_str(char const *s, char c, unsigned int *sub_len)
{
	unsigned int	i;
	unsigned int	c_count;
	unsigned int	c_max;
	unsigned int	word_count;
	unsigned int	word_flag;

	i = 0;
	c_count = 0;
	c_max = 0;
	word_count = 0;
	word_flag = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			c_count++;
			if (word_flag == 0)
			{
				word_flag = 1;
				word_count++;
			}
		}
		else
		{
			if (c_count > c_max)
				c_max = c_count;
			c_count = 0;
			word_flag = 0;
		}
		i++;
	}
	*sub_len = c_max;
	return (word_count);
}

static void	split_str(char const *s, char c, char **array)
{
	unsigned int	i_s;
	unsigned int	i_word_array;
	unsigned int	i_char;
	unsigned int	word_flag;

	i_s = 0;
	i_word_array = 0;
	i_char = 0;
	word_flag = 0;
	while (s[i_s])
	{
		if (s[i_s] != c)
		{
			array[i_word_array][i_char] = s[i_s];
			word_flag = 1;
			i_char++;
		}
		else
		{
			if (word_flag)
			{
				array[i_word_array][i_char] = '\0';
				i_word_array++;
				i_char = 0;
			}
			word_flag = 0;
		}
		i_s++;
	}
}

int	main(void)
{
	char **expected = ft_split("\0aa\0bbb", '\0');
	
	printf("%s\n", *expected);

	char *s = "split  ||this|for|me|||||!|";
	int i = 0;
	char **result = ft_split(s, '|');
	while (*result)
	{
		printf("%s\n", result[i]);
		i++;
	}
	
	return (0);
}