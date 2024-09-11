/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:26:15 by nboer             #+#    #+#             */
/*   Updated: 2024/09/11 11:30:10 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESKTOP: /home/nick/42Berlin/fract-ol/includes/
// PC 42: 	/home/nboer/git/fract-ol/includes/

#include <unistd.h>
#include <stdlib.h>
#include "/home/nboer/git/fract-ol/includes/minilibx-linux/mlx.h"
#include "/home/nboer/git/fract-ol/includes/ft_printf/ft_printf.h"
#include "/home/nboer/git/fract-ol/includes/Libft/libft.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

#define BLACK             0x000000  // RGB(0, 0, 0)
#define WHITE             0xFFFFFF  // RGB(255, 255, 255)

#define RES_Y 1000
#define RES_X 1000
#define MAX_ITERATIONS 30

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
	double		max_hypotenuse;
	int			max_iterations;
	int			bpp;
	int			endian;
	int			line_len;
	int			pixel_bits;
	double		offset_x;
	double		offset_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}	t_fractol;

void		ft_error(void);
double		remap(double num, double new_min, double new_max, 
				double old_max);
t_complex	square_com(t_complex c);
t_complex	sum_com(t_complex c1, t_complex c2);
void		events_init(t_fractol *frac);
double		ft_atod(const char *nptr);
void		fractoltype(t_fractol *frac, t_complex *z, t_complex *c);
double		check_fractional(const char *nptr, int i, double num, double fac);
void		render_screen(t_fractol *frac);
int			events_keyboard(int keycode, t_fractol *frac);
int			handle_mods(int keycode, t_fractol *frac);
int			handle_view(int keycode, t_fractol *frac);
int			handle_hotspots(int keycode, t_fractol *frac);
int			events_mouse_press(int button, int x, int y, t_fractol *frac);
int			close_window(t_fractol *frac);

