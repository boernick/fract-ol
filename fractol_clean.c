/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:24:56 by nboer             #+#    #+#             */
/*   Updated: 2024/09/11 16:29:58 by nboer            ###   ########.fr       */
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
