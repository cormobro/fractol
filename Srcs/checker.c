/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:53:25 by febonaer          #+#    #+#             */
/*   Updated: 2023/02/27 15:06:51 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static int	is_digit(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
		j++;
	if (str[i] == '-')
		i++;
	while (str[i] <= 57 && str[i] >= 48)
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] <= 57 && str[i] >= 48)
		i++;
	if (i == j && str[i - 1] != '-')
		return (1);
	return (0);
}

static int	ft_setchecker(char **argv, t_complex *comp)
{
	int	i;

	i = 0;
	while (argv[1][i] && argv[1][i] == JULIA[i])
		i++;
	if (i == 5 && !argv[1][i])
	{
		comp->set = 1;
		return (1);
	}
	i = 0;
	while (argv[1][i] && argv[1][i] == MANDELBROT[i])
		i++;
	if (i == 10 && !argv[1][i])
	{
		comp->set = 2;
		return (2);
	}
	return (0);
}

static int	ft_multiargscheck(char **argv, t_complex *comp)
{
	int	i;

	i = 2;
	while (argv[i])
	{
		if (!is_digit(argv[i]))
			return (0);
		i++;
	}
	if (!ft_setchecker(argv, comp))
		return (0);
	comp->left = ft_atof(argv[2]);
	comp->top = ft_atof(argv[3]);
	comp->xside = ft_atof(argv[4]);
	comp->yside = ft_atof(argv[5]);
	comp->cr = ft_atof(argv[4]);
	comp->ci = ft_atof(argv[5]);
	if (comp->left > 10000 || comp->top > 10000
		|| comp->xside > 10000 || comp->yside > 10000)
		return (0);
	if (comp->left < -10000 || comp->top < -10000
		|| comp->xside < -10000 || comp->yside < -10000)
		return (0);
	return (1);
}

int	ft_argchecker(int argc, char **argv, t_complex *comp)
{
	if (argc == 2)
	{
		if (!ft_setchecker(argv, comp))
			return (0);
		comp->left = 0;
		comp->top = 0;
		comp->xside = 1.5;
		comp->yside = 1.5;
		comp->cr = -0.7;
		comp->ci = 0.27015;
		if (ft_setchecker(argv, comp) == 2)
		{
			comp->left = -2.2;
			comp->top = 1.6;
			comp->xside = 3.2;
			comp->yside = -3.2;
		}
		return (1);
	}
	else if (argc == 6)
		return (ft_multiargscheck(argv, comp));
	else
		return (0);
}
