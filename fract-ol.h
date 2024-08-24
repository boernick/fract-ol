/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboer <nboer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:26:15 by nboer             #+#    #+#             */
/*   Updated: 2024/08/24 20:45:19 by nboer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "/home/nboer/git/fract-ol/includes/minilibx-linux/mlx.h"
#include "/home/nboer/git/fract-ol/includes/ft_printf/ft_printf.h"
#include "/home/nboer/git/fract-ol/includes/Libft/libft.h"

typedef struct	s_complex{
	double	y; //complex
	double	x; //real
}	t_complex;

typedef struct s_fractol
{
	t_complex	num;
	void	*mlx_win_ptr; // mlx_new_window
	void	*mlx_ptr;  //mlx_init
	void	*pix_ptr; // pointer to pixels
	void	*mlx_img_ptr; //pointer to image
	int		colour;
	double	max_iterations;
	

}	t_fractol;

void	ft_error(void);

