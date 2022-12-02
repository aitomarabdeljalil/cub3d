/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:21:30 by aait-oma          #+#    #+#             */
/*   Updated: 2022/11/21 21:21:30 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>

double ft_distance(int xa, int ya, int xb, int yb)
{
    return (sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya)));
}