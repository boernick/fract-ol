/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nick <nick@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:26:15 by nboer             #+#    #+#             */
/*   Updated: 2024/08/25 16:57:30 by nick             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESKTOP: /home/nick/42Berlin/fract-ol/includes/
// PC 42: 	/home/nboer/git/fract-ol/includes/

#include <unistd.h>
#include <stdlib.h>
#include "/home/nick/42Berlin/fract-ol/includes/minilibx-linux/mlx.h"
#include "/home/nick/42Berlin/fract-ol/includes/ft_printf/ft_printf.h"
#include "/home/nick/42Berlin/fract-ol/includes/Libft/libft.h"

typedef struct	s_complex{
	double	y; //complex
	double	x; //real
}	t_complex;

typedef struct s_fractol
{
	t_complex	num;
	void	*win_ptr; // mlx_new_window
	void	*mlx_ptr;  //mlx_init
	void	*pix_ptr; // pointer to pixels
	void	*img_ptr; //pointer to image
	int		colour;
	double	max_iterations;
	

}	t_fractol;

void	ft_error(void);
double	scale(double num, double n_min, double n_max, double o_min, double o_max);

