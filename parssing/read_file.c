/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:45:03 by mmessaou          #+#    #+#             */
/*   Updated: 2022/11/25 15:34:27 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>
char	*rmv_nl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			s[i] = 0;
	return (s);
}

int	file_lines(char *file)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(file, O_RDWR);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

bool	check_elements(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == '\n')
				i++;
	while (str[i])
	{
		if (str[i] == '\n' && j < 6 && ++j)
			while (str[i] == '\n')
				i++;
		if (j == 6)
			if (str[i] == '\n'
				&& (!str[i + 1] || str[i + 1] == '\n'))
				return (0);
		i++;
	}
	return (1);
}

char	**first_read(char *file, t_data *data)
{
	char	**content;
	char	*str;
	int		fd;
	int		i;
	int		len;

	i = 0;
	fd = open(file, O_RDWR);
	if (fd == -1)
		return (close(fd),
			ft_exit("file doesn't exist or permission denied", data), NULL);
	len = file_lines(file);
	str = get_next_line(fd);
	if (!str)
		return (close(fd), ft_exit("empty file!!", data), NULL);
	while (++i < len)
		str = ft_strjoin_one(str, get_next_line(fd));
	close(fd);
	if (!check_elements(str))
		ft_exit("invalid elements", data);
	content = ft_split(str, '\n');
	i = 0;
	free(str);
	return (content);
}
