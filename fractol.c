/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:15 by nboer             #+#    #+#             */
/*   Updated: 2024/08/31 21:02:09 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

#define RES_Y 800
#define RES_X 800
#define MAX_ITERATION 42

static void	my_pixel_put(int x, int y, t_fractol *frac, int color)
{
	int	offset;

	offset = (y * frac->line_len) + (x * (frac->pixel_bits / 8));
	*(unsigned int *)(frac->buff + offset) = color; // the color is right
}

static void fractol_calc_pix(int x, int y, t_fractol *frac)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0;
	z.y = 0;
	c.x = remap(x, -2, 2, RES_X);
	c.y = remap(y, 2, -2, RES_Y);

	while (i < frac->max_iterations)
	{
		z = sum_com(square_com(z), c);
		if ((z.x * z.x) + (z.y * z.y) > frac->max_hypotenuse)
		{
			color = remap(i, WHITE, BLACK, frac->max_iterations);
			my_pixel_put(x, y, frac, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, frac, BLACK);
}

void	render_screen(t_fractol *frac) // works
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < frac->res_y)
	{
		j++;
		while (i < frac->res_x)
		{
			fractol_calc_pix(i, j, frac);
			i++;
		}
		i = 0;
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->img_ptr,
		0, 0);
}

void	fractol_init(int res_y, int res_x, t_fractol *frac)
{
	frac->res_y = res_y;
	frac->res_x = res_x;
	frac->mlx_ptr = mlx_init();
	if (frac->mlx_ptr == NULL)
		ft_error();
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, RES_X, RES_Y, "mandelbrot");
	if (frac->win_ptr == NULL)
		ft_error();
	frac->img_ptr = mlx_new_image(frac->mlx_ptr, RES_X, RES_Y);
	frac->buff = mlx_get_data_addr(frac->img_ptr, &frac->pixel_bits,
			&frac->line_len, &frac->endian);
	frac->max_hypotenuse = 4;
	frac->max_iterations = 215;
	frac->shift_x = 0.0;
	frac->shift_y = 0.0;
}

#include <stdio.h>
int	main(int argc, char **argv) // CHECK INPUTS! IT WORKS SOMEHOW WITH ./frac-tol mandelb
{
	t_fractol	frac;

	if (argc == 1)
		ft_printf("Please enter command as: \n	- mendelbrot \n	- julia \n");
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			fractol_init(RES_Y, RES_X, &frac);
		else
			ft_error();
	}
	render_screen(&frac);
	mlx_loop(frac.mlx_ptr);
	return (0);
}
