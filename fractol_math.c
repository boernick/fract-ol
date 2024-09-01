/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:33:36 by nboer             #+#    #+#             */
/*   Updated: 2024/09/01 15:37:30 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// The mandelbrot's visual exists between the values 2 and -2, therefore values
// in a screen of size RES_Y x RES_X need to be remapped accordingly. Function 
// takes a value in a set domain between min, max, and returns remapped value.
double	remap(double num, double new_min, double new_max, 
	double old_max)
{
	return (new_max - new_min) * (num - 0) / (old_max - 0) + new_min;
}

t_complex	sum_com(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.x = c1.x + c2.x;
	res.y = c1.y + c2.y;
	return (res);
}

// if you square the complex number you get z = (z^2 - y^2) + 2xyi
t_complex	square_com(t_complex c)
{
	t_complex	res;

	res.x = (c.x * c.x) - (c.y * c.y);
	res.y = 2 * c.x * c.y;
	return (res);
}
