/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:44:50 by nboer             #+#    #+#             */
/*   Updated: 2024/09/07 21:02:06 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	events_init(t_fractol *frac)
{
	mlx_hook(frac->win_ptr, DestroyNotify, 0, close_window, frac);
	mlx_key_hook(frac->win_ptr, events_keyboard, frac);
	mlx_mouse_hook(frac->win_ptr, events_mouse_press, frac);
}

int	close_window(t_fractol *frac)
{
	mlx_loop_end(frac->mlx_ptr);
	return (0);
}

int	events_mouse_press(int button, int x, int y, t_fractol *frac)
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
	handle_mods(keycode, frac);
	handle_hotspots(keycode, frac);
	handle_view(keycode, frac);
	if (keycode == XK_m)
	{
		frac->zoom = 1;
		frac->name = "mandelbrot";
	}
	if (keycode == XK_Escape)
		mlx_loop_end(frac->mlx_ptr);
	render_screen(frac);
	return (0);
}
int	handle_mods(int keycode, t_fractol *frac)
{
	if (keycode == XK_comma || keycode == XK_less)
		frac->max_iterations -= 10;
	if (keycode == XK_period || keycode == XK_greater)
		frac->max_iterations += 10;
	return (0);
}

int	handle_view(int keycode, t_fractol *frac)
{
	if (keycode == XK_plus || keycode == XK_equal)
		frac->zoom *= 0.9; 
	if (keycode == XK_minus)
		frac->zoom /= 0.9;
	if (keycode == XK_Up)
		frac->offset_x += 0.5 * frac->zoom;
	if (keycode == XK_Down)
		frac->offset_x -= 0.5 * frac->zoom;
	if (keycode == XK_Left)
		frac->offset_y -= 0.5 * frac->zoom;
	if (keycode == XK_Right)
		frac->offset_y += 0.5 * frac->zoom;
	if (keycode == XK_w)
		frac->julia_y += 0.01;
	if (keycode == XK_s)
		frac->julia_y -= 0.01;
	if (keycode == XK_a)
		frac->julia_x += 0.01;
	if (keycode == XK_d)
		frac->julia_x -= 0.01;
	return (0);
}

int	handle_hotspots(int keycode, t_fractol *frac)
{
	if (keycode == XK_1)
	{
		frac->zoom = 0.008728;
		frac->offset_x = -0.262731;
		frac->offset_y = -1.146751;
		frac->julia_x = -1.146751;
		frac->max_iterations = 270;
	}
	if (keycode == XK_2)
	{
		frac->zoom = 0.006363;
		frac->offset_x = 0.103844;
		frac->offset_y = -0.416734;
		frac->julia_x = -0.416734;
	}
	if (keycode == XK_3)
	{
		frac->zoom = 0.098477;
		frac->offset_x = 0.250292;
		frac->offset_y = 0.434960;
		frac->julia_x = 0.434960;
	}
	return (0);
}
