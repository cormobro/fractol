/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:58:53 by febonaer          #+#    #+#             */
/*   Updated: 2023/02/27 16:08:23 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void	ft_error(void)
{
	write(1, "Voici les parametres disponibles:\n\
			./fractol julia\n\
			./fractol julia [left] [top] [CReel] [CImag]\n\
			./fractol mandelbrot\n\
			./fractol mandelbrot [left] [top] [Xside] [Yside]\n\
			Valeurs limites: -10000 -> 10000\n", 214);
	exit(0);
}

void	my_mlx_pixel_put(t_complex *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

//comp->cr = -0.7;
//comp->ci = 0.27015;
//comp->cr = -0.75;
//comp->ci = 0.11;

static void	ft_init_complex(t_complex *comp)
{
	comp->zoom = 1;
	comp->pr = 0;
	comp->pi = 0;
	comp->iteration = 0;
	comp->c0 = 0x00421E0F;
	comp->c1 = 0x0019071A;
	comp->c2 = 0x0009012F;
	comp->c3 = 0x00040449;
	comp->c4 = 0x00000764;
	comp->c5 = 0x000C2C8A;
	comp->c6 = 0x001852B1;
	comp->c7 = 0x00397DD1;
	comp->c8 = 0x0086B5E5;
	comp->c9 = 0x00D3ECF8;
	comp->c10 = 0x00F1E9BF;
	comp->c11 = 0x00F8C95F;
	comp->c12 = 0x00FFAA00;
	comp->c13 = 0x00CC8000;
	comp->c14 = 0x00995700;
	comp->c15 = 0x006A3403;
}

int	main(int argc, char **argv)
{
	t_complex	comp;

	if (!ft_argchecker(argc, argv, &comp))
		ft_error();
	ft_init_complex(&comp);
	comp.mlx = mlx_init();
	if (comp.mlx == NULL)
	{
		(void)comp;
		exit(0);
	}
	comp.mlx_win = mlx_new_window(comp.mlx, WIDTH, LENGTH, argv[1]);
	comp.img = mlx_new_image(comp.mlx, WIDTH, LENGTH);
	comp.addr = mlx_get_data_addr(comp.img, &comp.bits_per_pixel,
			&comp.line_length, &comp.endian);
	if (comp.set == 1)
		ft_printjulia(&comp, (float)WIDTH, (float)LENGTH);
	else
		ft_printmande(&comp, (float)WIDTH, (float)LENGTH);
	mlx_mouse_hook(comp.mlx_win, ft_scroll, &comp);
	mlx_hook(comp.mlx_win, 17, 0, ft_closebis, &comp);
	mlx_key_hook(comp.mlx_win, ft_close, &comp);
	mlx_loop(comp.mlx);
	return (0);
}
