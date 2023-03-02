/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:59:37 by febonaer          #+#    #+#             */
/*   Updated: 2023/02/27 13:03:03 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febonaer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:00:13 by febonaer          #+#    #+#             */
/*   Updated: 2023/02/21 16:57:53 by febonaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# define WIDTH 1000
# define LENGTH 1000
# define JULIA "julia"
# define MANDELBROT "mandelbrot"
# define IITERATION 400

typedef struct s_img
{
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	char	*addr;
}	t_img;

typedef struct s_complex
{
	float	pr;
	float	pi;
	float	cr;
	float	ci;
	float	left;
	float	top;
	float	xside;
	float	yside;
	float	zoom;
	int		iteration;
	int		color;
	int		set;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		c0;
	int		c1;
	int		c2;
	int		c3;
	int		c4;
	int		c5;
	int		c6;
	int		c7;
	int		c8;
	int		c9;
	int		c10;
	int		c11;
	int		c12;
	int		c13;
	int		c14;
	int		c15;
}	t_complex;

int		main(int argc, char **argv);
int		ft_strlen(char *str);
int		ft_close(int keycode, t_complex *mlx);
int		ft_closebis(int keycode, t_complex *mlx);
int		ft_scroll(int keycode, int x, int y, t_complex *comp);
int		ft_argchecker(int argc, char **argv, t_complex *comp);
float	ft_atof(char *str);
void	ft_getcolor(t_complex *comp);
void	ft_getcolorbis(t_complex *comp, int i);
void	my_mlx_pixel_put(t_complex *data, int x, int y, int color);
void	ft_printmande(t_complex *comp, int width, int length);
void	ft_printjulia(t_complex *comp, int width, int length);

#endif
