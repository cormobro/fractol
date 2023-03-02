/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:54:58 by febonaer          #+#    #+#             */
/*   Updated: 2023/02/27 15:06:43 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

int	ft_close(int keycode, t_complex *mlx)
{
	if (keycode == 53 && mlx->mlx)
	{
		(void)mlx;
		exit(0);
	}
	else if (keycode == 124)
		mlx->left += 0.1 / mlx->zoom;
	else if (keycode == 123)
		mlx->left -= 0.1 / mlx->zoom;
	else if (keycode == 126)
		mlx->top += 0.1 / mlx->zoom;
	else if (keycode == 125)
		mlx->top -= 0.1 / mlx->zoom;
	else if (keycode == 78)
		mlx->cr += 0.032;
	else if (keycode == 69)
		mlx->cr -= 0.032;
	if (mlx->set == 1)
		ft_printjulia(mlx, (float)WIDTH, (float)LENGTH);
	else
		ft_printmande(mlx, (float)WIDTH, (float)LENGTH);
	return (0);
}

int	ft_closebis(int keycode, t_complex *mlx)
{
	if (keycode && mlx->mlx)
	{
		(void)mlx;
		exit(0);
	}
	return (0);
}

static void	ft_reset(t_complex *comp)
{
	comp->zoom = 1;
	if (comp->set == 1)
	{
		comp->left = 0;
		comp->top = 0;
		comp->xside = 1.5;
		comp->yside = 1.5;
		comp->cr = -0.7;
		comp->ci = 0.27015;
		ft_printjulia(comp, (float)WIDTH, (float)LENGTH);
	}
	else
	{
		comp->left = -2.2;
		comp->top = 1.6;
		comp->xside = 3.2;
		comp->yside = -3.2;
		comp->cr = -0.7;
		comp->ci = 0.27015;
		ft_printmande(comp, (float)WIDTH, (float)LENGTH);
	}
}

static void	ft_scrollup(t_complex *comp)
{
	if (comp->set == 1)
		comp->zoom = comp->zoom * 1.2;
	else
		comp->zoom = comp->zoom * 1.2;
	if (comp->set == 1)
		ft_printjulia(comp, (float)WIDTH, (float)LENGTH);
	else
		ft_printmande(comp, (float)WIDTH, (float)LENGTH);
}

int	ft_scroll(int keycode, int x, int y, t_complex *comp)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		ft_scrollup(comp);
	else if (keycode == 5)
	{
		if (comp->set == 1)
			comp->zoom = comp->zoom * 0.8;
		else
			comp->zoom = comp->zoom * 0.8;
		if (comp->set == 1)
			ft_printjulia(comp, (float)WIDTH, (float)LENGTH);
		else
			ft_printmande(comp, (float)WIDTH, (float)LENGTH);
	}
	else if (keycode == 2)
		ft_reset(comp);
	return (0);
}
