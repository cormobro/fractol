/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:29:07 by febonaer          #+#    #+#             */
/*   Updated: 2023/02/27 15:29:31 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static void	ft_julia(t_complex *comp)
{
	float	tmp;

	while ((comp->pr * comp->pr + comp->pi * comp->pi < 4)
		&& (comp->iteration > 1))
	{
		tmp = comp->pr * comp->pr - comp->pi * comp->pi + comp->cr;
		comp->pi = 2 * comp->pr * comp->pi + comp->ci;
		comp->pr = tmp;
		comp->iteration--;
	}
}

static void	ft_printjuliabis(t_complex *comp, t_complex *img, int x, int y)
{
	while (x <= WIDTH - 1)
	{
		y = 0;
		while (y <= LENGTH - 1)
		{
			comp->iteration = IITERATION;
			comp->pr = 1.5 * (x - WIDTH / 2)
				/ (0.5 * comp->zoom * WIDTH) + comp->left;
			comp->pi = 1.5 * (y - LENGTH / 2)
				/ (0.5 * comp->zoom * LENGTH) + comp->top;
			ft_julia(comp);
			ft_getcolor(comp);
			my_mlx_pixel_put(img, WIDTH - x, y, comp->color);
			y++;
		}
		x++;
	}
}

void	ft_printjulia(t_complex *comp, int width, int length)
{
	int			x;
	int			y;
	t_complex	img;

	x = 0;
	y = 0;
	img.img = mlx_new_image(comp->mlx, width, length);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	ft_printjuliabis(comp, &img, x, y);
	comp->img = img.img;
	mlx_put_image_to_window(comp->mlx, comp->mlx_win, comp->img, 0, 0);
}
