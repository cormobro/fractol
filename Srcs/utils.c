/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:24:19 by febonaer          #+#    #+#             */
/*   Updated: 2023/02/27 14:18:08 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fract_ol.h"

static	float	ft_atofbis(int i, char *str)
{
	float	res;
	float	comma;

	res = 0;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] && str[i++] == '.')
	{
		comma = 10;
		while (str[i] && str[i] <= '9' && str[i] >= '0')
		{
			res = res + ((str[i] - '0') / comma);
			comma *= 10;
			i++;
		}
	}
	if (res > 10000)
		return (0);
	return (res);
}

float	ft_atof(char *str)
{
	int		i;
	float	sign;

	if (!str)
		return (0);
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9)))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		return (0);
	return (sign * ft_atofbis(i, str));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_getcolor(t_complex *comp)
{
	int	i;

	i = comp->iteration % 16;
	if (i == 0)
		comp->color = comp->c0;
	else if (i == 1)
		comp->color = comp->c1;
	else if (i == 2)
		comp->color = comp->c2;
	else if (i == 3)
		comp->color = comp->c3;
	else if (i == 4)
		comp->color = comp->c4;
	else if (i == 5)
		comp->color = comp->c5;
	else if (i == 6)
		comp->color = comp->c6;
	else if (i == 7)
		comp->color = comp->c7;
	else if (i == 8)
		comp->color = comp->c8;
	else if (i == 9)
		comp->color = comp->c9;
	else
		ft_getcolorbis(comp, i);
}

void	ft_getcolorbis(t_complex *comp, int i)
{
	if (i == 10)
		comp->color = comp->c10;
	else if (i == 11)
		comp->color = comp->c11;
	else if (i == 12)
		comp->color = comp->c12;
	else if (i == 13)
		comp->color = comp->c13;
	else if (i == 14)
		comp->color = comp->c14;
	else if (i == 15)
		comp->color = comp->c15;
}
