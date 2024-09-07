/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:44:50 by nboer             #+#    #+#             */
/*   Updated: 2024/09/07 15:44:17 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	events_init(t_fractol *frac)
{
	mlx_key_hook(frac->win_ptr, events_keyboard, frac);
	mlx_mouse_hook(frac->win_ptr, events_mouse, frac);
}

int	events_mouse(int button, int x, int y, t_fractol *frac)
{
	if (button == Button3)
	{
		frac->name = "julia";
		frac->julia_x = remap((double)x, -2, 2, RES_X);
		frac->julia_y = remap((double)y, -2, 2, RES_Y);
	}
	render_screen(frac);
	return (0);
}

int	events_keyboard(int keycode, t_fractol *frac)
{
	if (keycode == XK_Escape)
		mlx_loop_end(frac->mlx_ptr);
	if (keycode == XK_plus || keycode == XK_equal) // + or =
		frac->zoom *= 0.9; 
	if (keycode == XK_minus) // -
		frac->zoom /= 0.9;
	if (keycode == XK_Up)
		frac->offset_x += 0.10;
	if (keycode == XK_Down)
		frac->offset_x -= 0.10;
	if (keycode == XK_Left)
		frac->offset_y -= 0.10;
	if (keycode == XK_Right)
		frac->offset_y += 0.10;
	if (keycode == XK_comma || keycode == XK_less)
		frac->max_iterations -= 10;
	if (keycode == XK_period || keycode == XK_greater)
		frac->max_iterations += 10;
	if (keycode == XK_m)
		frac->name = "mandelbrot";
	render_screen(frac);
	return (0);
}
