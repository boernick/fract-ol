**GOOD COLORS FOR THESE***
Iterations: 290
Iterations: 500
Iterations: 440

**GOOD RESULTS FOR THESE**
make re && ./fract-ol julia -.79 .15
./fract-ol julia -.4 .6
./fract-ol julia 0.285 0.01
./fract-ol julia -0.70176 -0.3842
./fract-ol julia 0.355 0.355
./fract-ol julia 0.37 0.1
./fract-ol julia -0.7269 0.1889

**PRINTING PARAMETERS WITH THIS CODE**
paste this above the mlx_loop_end in the fractol_events.c to copy the parameters.
		#include <stdio.h>
		printf("\nfrac->zoom = %f", frac->zoom);
		printf("\nfrac->offset_x = %f", frac->offset_x);
		printf("\nfrac->offset_y = %f", frac->offset_y);
		printf("\nfrac->julia_x = %f", frac->offset_y); 
		printf("\nfrac->max_iterations = %d", frac->max_iterations);
