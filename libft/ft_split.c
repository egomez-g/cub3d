/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:43:19 by sgil-moy          #+#    #+#             */
/*   Updated: 2024/01/29 16:06:14 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != '\0' && s[i] != c) && \
		(s[i + 1] == c || s[i + 1] == '\0'))
			++n;
		++i;
	}
	return (n);
}

static size_t	count_letters(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] == c)
		++i;
	while (s[i + n] != c && s[i + n] != '\0')
		++n;
	return (n + 1);
}

static void	freemem(int i, char **p)
{
	while (i >= 0)
	{
		free(p[i]);
		i--;
	}
	free(p);
}

static char	*cpyword(char const *s, size_t *j, char c)
{
	char	*word;
	size_t	k;

	word = (char *)malloc(sizeof(char) * count_letters(s + *j, c));
	if (word == NULL)
		return (NULL);
	while (s[*j] == c)
		++*j;
	k = 0;
	while (s[*j + k] != c && s[*j + k] != '\0')
	{
		word[k] = s[*j + k];
		++k;
	}
	word[k] = '\0';
	*j += k;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**p;
	char	*word;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (p == NULL)
		return (NULL);
	while (i < count_words(s, c))
	{
		word = cpyword(s, &j, c);
		if (word == NULL)
		{
			freemem(i - 1, p);
			return (NULL);
		}
		p[i] = word;
		++i;
	}
	p[i] = NULL;
	return (p);
}
