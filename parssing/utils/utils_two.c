/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmessaou <mmessaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:24:54 by mmessaou          #+#    #+#             */
/*   Updated: 2022/12/20 21:09:09 by mmessaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parss.h"

int	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			if (ft_strlen(str) - i == 4
				&& str[i + 1] == 'c' && str[i + 2] == 'u'
				&& str[i + 3] == 'b' && !str[i + 4])
				return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	result;

	neg = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * neg);
}
