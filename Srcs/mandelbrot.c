/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:34:23 by febonaer          #+#    #+#             */
/*   Updated: 2023/02/27 14:56:54 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static	void	ft_mandelbrot(t_complex *comp)
{
	float	tmp;

	while ((comp->pr * comp->pr + comp->pi * comp->pi < 4)
		&& (comp->iteration < IITERATION))
	{
		tmp = comp->pr * comp->pr - comp->pi * comp->pi + comp->cr;
		comp->pi = 2 * comp->pi * comp->pr + comp->ci;
		comp->pr = tmp;
		comp->iteration++;
	}
}

static void	ft_printmandebis(t_complex *comp, t_complex *img, int j, int i)
{
	while (i <= LENGTH - 1)
	{
		j = 0;
		while (j <= WIDTH - 1)
		{
			comp->pr = 0;
			comp->pi = 0;
			comp->iteration = 0;
			comp->cr = (j * (comp->xside / WIDTH) + comp->left) * comp->zoom;
			comp->ci = (i * (comp->yside / LENGTH) + comp->top) * comp->zoom;
			ft_mandelbrot(comp);
			ft_getcolor(comp);
			my_mlx_pixel_put(img, j, i, comp->color);
			j++;
		}
		i++;
	}
}

void	ft_printmande(t_complex *comp, int width, int length)
{
	int			i;
	int			j;
	t_complex	img;

	j = 0;
	i = 0;
	img.img = mlx_new_image(comp->mlx, width, length);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	ft_printmandebis(comp, &img, j, i);
	comp->img = img.img;
	mlx_put_image_to_window(comp->mlx, comp->mlx_win, comp->img, 0, 0);
}
