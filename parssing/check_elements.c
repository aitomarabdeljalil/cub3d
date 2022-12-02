/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:54:17 by mmessaou          #+#    #+#             */
/*   Updated: 2022/11/25 15:32:11 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*try_get_texture(char **content, char a, char b)
{
	int	i;

	i = -1;
	while (content[++i])
	{
		if (content[i][0] == a && content[i][1] == b)
			return (skip_spaces(content[i] + 2));
	}
	return (NULL);
}

char	*try_get_color(char **content, char a)
{
	int	i;

	i = -1;
	while (content[++i])
	{
		if (content[i][0] == a)
			return (skip_spaces(content[i] + 1));
	}
	return (NULL);
}

char	**try_get_map(char **content)
{
	char	**str;
	int		i;
	int		j;

	j = -1;
	i = 6;
	while (content[i])
		i++;

	str = malloc(sizeof(char *) * (i - 5));
	if (!str)
		return (NULL);
	i = 5;
	while (content[++i])
		str[++j] = content[i];
	str[++j] = 0;
	return (str);
}

int	get_line_nbr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
