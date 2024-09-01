/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:26:15 by nboer             #+#    #+#             */
/*   Updated: 2024/09/01 15:38:54 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESKTOP: /home/nick/42Berlin/fract-ol/includes/
// PC 42: 	/home/nboer/git/fract-ol/includes/

#include <unistd.h>
#include <stdlib.h>
#include "/home/nboer/git/fract-ol/includes/minilibx-linux/mlx.h"
#include "/home/nboer/git/fract-ol/includes/ft_printf/ft_printf.h"
#include "/home/nboer/git/fract-ol/includes/Libft/libft.h"

#define BLACK             0x000000  // RGB(0, 0, 0)
#define WHITE             0xFFFFFF  // RGB(255, 255, 255)
#define PASTEL_PINK       0xFFD1DC  // A soft pink
#define PASTEL_BLUE       0xAEC6CF  // A gentle blue
#define PASTEL_GREEN      0x77DD77  // A light green
#define PASTEL_YELLOW     0xFDFD96  // A pale yellow
#define PASTEL_PURPLE     0xCBAACB  // A delicate purple
#define PASTEL_ORANGE     0xFFB347  // A soft orange
#define PASTEL_PEACH      0xFFE5B4  // A light peach
#define PASTEL_LAVENDER   0xE6E6FA  // A soft lavender

#define RES_Y 1040
#define RES_X 1040

typedef struct	s_complex{
	double	y;
	double	x;
}	t_complex;

typedef struct s_fractol
{
	char		*name;
	void		*win_ptr;
	void		*mlx_ptr; 
	char		*buff;
	void		*img_ptr;
	int			colour;
	double		max_hypotenuse;
	int			max_iterations;
	int			bpp;
	int			endian;
	int			line_len;
	int			pixel_bits;
	double		shift_x;
	double		shift_y;
}	t_fractol;

void		ft_error(void);
double		remap(double num, double new_min, double new_max, 
			double old_max);
t_complex	square_com(t_complex c);
t_complex	sum_com(t_complex c1, t_complex c2);
