/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine1 <amine1@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:53:35 by mmessaou          #+#    #+#             */
/*   Updated: 2022/07/20 16:05:02 by amine1           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "../cub3d.h"

char	*ft_substr(char *s, size_t start, size_t len)
{
	char			*str;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (start < len)
		while (s[start] && len--)
			str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static char	*ft_strword(char **s, char sep)
{
	char	*word;
	char	*start;
	size_t	len;

	if (*s == NULL)
		return (NULL);
	word = NULL;
	start = *s;
	len = 0;
	while (*start && *start == sep)
		start++;
	while (start[len] && start[len] != sep)
		len++;
	if (len != 0)
		word = ft_substr(start, 0, len);
	if (start[len] == '\0')
		*s = NULL;
	else
		*s = start + len + 1;
	return (word);
}

static size_t	ft_strwc(const char *s, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == sep)
			i++;
		else
		{
			j++;
			while (s[i] != sep && s[i] != '\0')
				i++;
		}
	}
	return (j);
}

static void	ft_free_words(char	**words)
{
	char	**alias;

	alias = words;
	while (*alias)
		free(*alias++);
	free(words);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	word_count;
	char	**words;

	if (s == NULL)
		return (NULL);
	word_count = ft_strwc(s, c);
	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL)
		return (NULL);
	i = 0;
	words[i] = ft_strword(&s, c);
	while (words[i])
		words[++i] = ft_strword(&s, c);
	if (i == word_count)
		return (words);
	ft_free_words(words);
	return (NULL);
}
