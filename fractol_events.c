/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:44:50 by nboer             #+#    #+#             */
/*   Updated: 2024/09/01 18:51:56 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

// int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
// int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
// int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
// int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
// int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

// register events with mlx_key_hook but in the function it just calls mlx_hook with the appropriate X11 event types
void	events_init(t_fractol *frac)
{
	mlx_key_hook(frac->win_ptr, events_keyboard, &frac);
}

int	events_keyboard(t_fractol *frac)
{
	mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
	return (0);
}
// Press escape to close the handler

// function that moves the screen up / down / left / right

// function that zooms in 
