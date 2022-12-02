/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalizeangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:54:53 by aait-oma          #+#    #+#             */
/*   Updated: 2022/11/21 21:54:53 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double normalizeangle(double angle)
{
    angle =  fmod(angle, 2 * M_PI) ;
    if (angle < 0)
        angle = (2 * M_PI) + angle;
    return angle;
}