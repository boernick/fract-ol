/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:00:12 by nboer             #+#    #+#             */
/*   Updated: 2024/09/04 19:52:56 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	fractoltype(t_fractol *frac, t_complex *z, t_complex *c)
{
	if (!ft_strncmp(frac->name, "julia", 5))
	{
		c->y = frac->julia_y;
		c->x = frac->julia_x;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

double	check_fractional(const char *nptr, int i, double num, double fac)
{
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = 10 * num + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '.')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		fac /= 10.0;
		num += (nptr[i] - '0') * fac;
		i++;
	}
	return (num);
}

double	ft_atod(const char *nptr)
{
	int		i;
	int		is_neg;
	double	num;
	double	factor;

	i = 0;
	is_neg = 1;
	num = 0;
	factor = 1;

	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg = -1;
		i++;
	}
	num = check_fractional(nptr, i, num, factor);
	return (is_neg * num);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
