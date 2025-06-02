/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:10:42 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:06:29 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*create_word(char const *s, int start, int end)
{
	char	*word;
	int		x;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	x = 0;
	while (start < end)
		word[x++] = s[start++];
	word[x] = '\0';
	return (word);
}

static int	fill_words(char **res, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			res[k] = create_word(s, j, i);
			if (!res[k])
				return (0);
			k++;
		}
	}
	res[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	if (!fill_words(res, s, c))
		return (NULL);
	return (res);
}
