/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:54:17 by mmessaou          #+#    #+#             */
/*   Updated: 2022/12/20 20:58:42 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parss.h"

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

int	get_map_lenght(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_map_width(char **str)
{
	int	i;
	int	j;
	int	width;

	i = -1;
	width = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
			j++;
		if (j > width)
			width = j;
	}
	return (width);
}
