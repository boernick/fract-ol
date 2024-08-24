/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:15 by nboer             #+#    #+#             */
/*   Updated: 2024/08/24 20:45:16 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// Setup MiniLibX.
// Create a window, image in MiniLibX.
// Iterate through every pixel of the window.
// For every pixel, calculate the complex number it represents and put it into the suite.
// If the suite diverges, color the pixel in white.
// If the suite converges, color the pixel in black.
#define RES_Y 1200
#define RES_X 800
#define MAX_ITERATION 10

void	fractol_calc(t_fractol *frac)
{
	ft_printf("calc fractol");

	int	pixel

	while (frac->num.y < RES_Y)
	{
		frac->num.y++;
		while(frac->num.x < RES_X)
		{
			frac->num.y * frac->num.y +  
			//calculate mandelbrot;
			//calculate colour based on iterations;
			z.x++;
		}
	}


}

void	fractol_init(int res_y, int res_x)
{
	void	*mlx;
	void	*win;
	void	*img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, res_y, res_x, "mandelbrot");
	if (win == NULL)
		ft_error();
	img = mlx_new_image(mlx, RES_Y, RES_X);
	mlx_pixel_put(mlx, win, RES_X / 2, RES_Y / 2, 0xFFFFFF);
	// eendimensionale array met alle coordinaten met mlx functie aanroepen
	// per pixel in de mandelbrot functie aanroepen en dan kleur toewijzen op basis van het aantal iteraties
	mlx_pixel_put(mlx, win, RES_X / 2 + 2, RES_Y / 2, 0xFFFFFF); // this is really slow so i need to use mlx_image_to_window()
	mlx_pixel_put(mlx, win, RES_X / 2 + 1, RES_Y / 2, 0xF000FF);
	fractol_calc();
	// mlx_put_image_to_window();
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_printf("Please enter command as: \n	- mendelbrot \n	- julia \n");
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10))
		{
			ft_printf("works");
			fractol_init(RES_Y, RES_X);
		}
	}
	return (0);
}
