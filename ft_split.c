/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 08:54:11 by rkaufman          #+#    #+#             */
/*   Updated: 2021/12/18 21:49:02 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	analyze_str(char const *s, char c);
static void			ft_create_substrings(char const *s, char c, char **array);

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	array = (char **) malloc((analyze_str(s, c) + 1) * sizeof(char *));
	if (!array)
		return (0);
	ft_create_substrings(s, c, array);
	return (array);
}

static unsigned int	analyze_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			word_count++;
			i--;
		}
		i++;
	}
	return (word_count);
}

static void	ft_create_substrings(char const *s, char c, char **array)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			array[word_count] = ft_substr(s, start, i - start);
			word_count++;
			i--;
		}
		i++;
	}
	array[word_count] = NULL;
}

/*
#include <stdio.h>
int main(void)
{
	
	char *string = "      split       this for   me  !       ";
	char **result1 = ft_split(string, ' ');
	int i = 0;
	while (result1[i])
	{
		printf("%s\n", result1[i]);
		i++;
	}


//[crash]: your split does not work with one word
//Test code:
	int i;
	char *s1 = "                  olol";
	char **result2 = ft_split(s1, ' ');

	i = 0;
	while (result2[i])
	{
		printf("%s\n", result2[i]);
		i++;
	}


//[crash]: your split does not work with one word
//Test code:
	char *s2 = "olol                     ";
	char **result3 = ft_split(s2, ' ');

	i = 0;
	while (result3[i])
	{
		printf("%s\n", result3[i]);
		i++;
	}


//[crash]: your split will segfault in case --> *str="\0aa\0bbb" c='\0' 
//Test code:
	char **expected = ft_split("\0aa\0bbb", '\0');

	i = 0;
	while (expected[i])
	{
		printf("%s\n", expected[i]);
		i++;
	}


//[crash]: your split does not work with basic input
//Test code:
	char *s3 = "split  ||this|for|me|||||!|";
	char **result4 = ft_split(s3, '|');

	i = 0;
	while (result4[i])
	{
		printf("%s\n", result4[i]);
		i++;
	}

//[crash]: your split does not work with basic input
//Test code:
	char *s4 = "      split       this for   me  !       ";

	char **result5 = ft_split(s4, ' ');

	i = 0;
	while (result5[i])
	{
		printf("%s\n", result5[i]);
		i++;
	}
	return (0);
}
*/