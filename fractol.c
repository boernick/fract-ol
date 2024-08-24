/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:15 by nboer             #+#    #+#             */
/*   Updated: 2024/08/24 14:53:53 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// Setup MiniLibX.
// Create a window, image in MiniLibX.
// Iterate through every pixel of the window.
// For every pixel, calculate the complex number it represents and put it into the suite.
// If the suite diverges, color the pixel in white.
// If the suite converges, color the pixel in black.
#  define RES_Y 1200;
#  define RES_X 800;

void init_screen(int res_y, int res_x)
{
	void	*mlx;
	mlx = mlx_init();
	mlx_new_window(res_y, res_x);
}


int	main(void)
{
	init_screen(RES_Y, RES_X);
	return (0);
}
