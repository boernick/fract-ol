/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:15 by nboer             #+#    #+#             */
/*   Updated: 2024/09/11 11:38:50 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

static void	my_pixel_put(int x, int y, t_fractol *frac, int color)
{
	int	offset;

	offset = (y * frac->line_len) + (x * (frac->pixel_bits / 8));
	*(unsigned int *)(frac->buff + offset) = color;
}

static void	fractol_calc_pix(int x, int y, t_fractol *frac)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (remap(x, -2, 2, RES_X) * frac->zoom) + frac->offset_y;
	z.y = (remap(y, 2, -2, RES_Y) * frac->zoom) + frac->offset_x;
	fractoltype(frac, &z, &c);
	while (i < frac->max_iterations)
	{
		z = sum_com(square_com(z), c);
		if ((z.x * z.x) + (z.y * z.y) > frac->max_hypotenuse)
		{
			if (i < 5)
				color = remap(5, WHITE, BLACK, frac->max_iterations);
			else
				color = remap(i, WHITE, BLACK, frac->max_iterations);
			my_pixel_put(x, y, frac, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, frac, BLACK);
}

void	render_screen(t_fractol *frac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(frac->mlx_ptr, frac->win_ptr);
	while (j < RES_Y)
	{
		i = 0;
		while (i < RES_X)
		{
			fractol_calc_pix(i, j, frac);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->img_ptr,
		0, 0);
}

void	fractol_init(t_fractol *frac)
{
	frac->mlx_ptr = mlx_init();
	if (frac->mlx_ptr == NULL)
		ft_error();
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, RES_X, RES_Y, "mandelbrot");
	if (frac->win_ptr == NULL)
	{
		mlx_destroy_display(frac->mlx_ptr);
		free(frac->mlx_ptr);
		ft_error();
	}
	frac->img_ptr = mlx_new_image(frac->mlx_ptr, RES_X, RES_Y);
	if (frac->img_ptr == NULL)
	{
		mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
		mlx_destroy_display(frac->mlx_ptr);
		free(frac->mlx_ptr);
		ft_error();
	}
	frac->buff = mlx_get_data_addr(frac->img_ptr, &frac->pixel_bits,
			&frac->line_len, &frac->endian);
	frac->max_hypotenuse = 4;
	frac->max_iterations = MAX_ITERATIONS;
	frac->offset_x = 0;
	frac->offset_y = 0;
	frac->zoom = 1.0;
}

int	main(int argc, char **argv)
{
	t_fractol	frac;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		frac.name = argv[1];
		ft_printf("Calculating %s...", frac.name);
		if (!ft_strncmp(frac.name, "julia", 5))
		{
			frac.julia_x = (ft_atod(argv[2]));
			frac.julia_y = (ft_atod(argv[3]));
		}
		fractol_init(&frac);
		events_init(&frac);
		render_screen(&frac);		
		mlx_loop(frac.mlx_ptr);
		mlx_destroy_window(frac.mlx_ptr, frac.win_ptr);
		free(frac.mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	ft_printf("Please enter command: \n	- mendelbrot \n	- julia <r> <i>\n");
	ft_error();
	return (0);
}
