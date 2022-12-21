/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:59:14 by mmessaou          #+#    #+#             */
/*   Updated: 2022/12/20 20:58:49 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parss.h"

int	map_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			if (str[i + 1] == 'c' && str[i + 2] == 'u'
				&& str[i + 3] == 'b' && !str[i + 4])
				return (1);
		i++;
	}
	return (0);
}

bool	check_its_valide(char **content)
{
	char	*str;
	int		i;

	i = 0;
	while (content[i] && i < 6)
	{
		str = skip_spaces(content[i]);
		if ((str[0] != 'N' && str[1] != 'O') && (str[0] != 'S' && str[1] != 'O')
			&& (str[0] != 'W' && str[1] != 'E') && (str[0] != 'E'
				&& str[1] != 'A') && (str[0] != 'C') && (str[0] != 'F'))
			return (0);
		i++;
	}
	while (content[i])
	{
		str = skip_spaces(content[i]);
		if (str[0] != '1')
			return (0);
		i++;
	}
	if (i < 6)
		return (0);
	return (1);
}
