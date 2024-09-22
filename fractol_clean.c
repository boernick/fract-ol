/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:24:56 by nboer             #+#    #+#             */
/*   Updated: 2024/09/22 17:27:56 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_clean(t_fractol *frac)
{
	mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
	mlx_destroy_image(frac->mlx_ptr, frac->img_ptr);
	mlx_destroy_display(frac->mlx_ptr);
	free(frac->mlx_ptr);
}

int	is_double(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == '.'
					&& str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (0);
		i++;
	}
	return (1);
}
