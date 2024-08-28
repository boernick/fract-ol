/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:15 by nboer             #+#    #+#             */
/*   Updated: 2024/08/28 09:37:29 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// For every pixel, calculate the complex number it represents and put it into the suite.
// If the suite diverges, color the pixel in white.
// If the suite converges, color the pixel in black.
#define RES_Y 800
#define RES_X 1200
#define MAX_ITERATION 10

// The mandelbrot's visual exists between the values 2 and -2, therefore values
// in a screen of size RES_Y x RES_X need to be remapped accordingly. Function 
// takes a value in a set domain between min, max, and returns remapped value.
double	remap(double num, double n_min, double n_max, double o_min, double o_max)
{
	return (n_max - n_min) * (num - o_min) / (o_max - o_min) + n_min;
}

// if you square the complex number you get z = (z^2 - y^2) + 2xyi
t_complex	square_com(t_complex z)
{
	t_complex	res;
	
	res.x = (z.x * z.x) - (z.y - z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

t_complex	sum_com(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);	
}

double	hypotenuse(double a, double b)
{
	return (square_root(sum(square(a), square(b))));
}
void	fractol_calc_pix(int x, int y, t_fractol *frac)
{
	ft_printf("calculating mandelbrot...");
	t_complex	z;
	t_complex	w;
	int	i;

	//first iteration
	z.x = 0;
	z.y = 0;

	w.x = remap(x, -2, 2, 0, RES_X)
	w.y = remap(x, 2, -2, 0, RES_Y);
	// voor elke pixel moet ik checken of hij binnen of buiten de hypotenuse valt.
	// wat is hij? de oplossing van de mandelbrot formule voor een specifiek punt in de grafiek waarin (x,y) = (real number, complex number)
	// totdat de waarde van hypotenuse groter dan 2 wordt, ga kan als "binnen" de fractol gekleurd worden 
	frac = sum_com(square_com(z), w);

	while(i < MAX_ITERATION)

	while (hypotenuse(frac->num.y, frac->num.x) < 2)
		//	roep de calculation aan


// dit hier beneden loopt door alle pixel in het scherm, hierboven moet gebeuren per pixel
	while (frac->num.y < RES_Y)
	{
		frac->num.y++;
		while (frac->num.x < RES_X)
		{
			//calculate mandelbrot;
			//calculate colour based on iterations;
			frac->num.x++;
		}
	}

}
// function takes XY size of screen as input and 
void	fractol_init(int res_y, int res_x, t_fractol *frac)
{
	int	pixel_bits;
	int	endian;
	int line_bytes;

	frac->mlx_ptr = mlx_init();
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, res_y, res_x, "mandelbrot");
	if (frac->win_ptr == NULL)
		ft_error();
	frac->img_ptr = mlx_new_image(frac->mlx_ptr, RES_Y, RES_X);
	
	// eendimensionale array met alle coordinaten met mlx functie aanroepen
	frac->buff = mlx_get_data_addr(frac->img_ptr, &pixel_bits, &line_bytes, &endian);
	frac->hypotenuse = 4; // 2 x 2 
	frac->max_iterations = 40;

	
	// per pixel in de mandelbrot functie aanroepen en dan kleur toewijzen op basis van het aantal iteraties
	fractol_calc();
	// mlx_put_image_to_window();
}

int	main(int argc, char **argv)
{
	t_fractol	frac;

	if (argc == 1)
		ft_printf("Please enter command as: \n	- mendelbrot \n	- julia \n");
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10))
		{
			ft_printf("works");
			fractol_init(RES_Y, RES_X, &frac);
		}
	}
	return (0);
}
