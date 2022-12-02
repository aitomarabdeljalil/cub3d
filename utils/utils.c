/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:56:06 by mmessaou          #+#    #+#             */
/*   Updated: 2022/06/27 13:34:03 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stddef.h>

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

char	*skip_spaces(char *str)
{
	if (!str[0])
		return (NULL);
	while (ft_isspace(str[0]))
		str++;
	return (str);
}

char	*ft_strjoin_one(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	free(s1);
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	free(s2);
	return (str);
}

bool	ft_strchr_2(const char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

bool    ft_strspn(const char *s, const char *accept)
{
    size_t    i;

    i = -1;
    while (s[++i])
	 if (!ft_strchr_2(accept, s[i]))
        return (0);
    return (1);
}
