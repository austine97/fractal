/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:51:47 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/04/04 19:39:28 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_fract
{
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	int		k;
	float	zoom;
	float	zoom_inc;
	float	zoom_x;
	float	zoom_y;
	float	tmp;
	int		bpp;
	int		s_l;
	float	iterations;
	float	X1;
	float	X2;
	float	Y1;
	float	Y2;
	float	JX1;
	float	JX2;
	float	JY1;
	float	JY2;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_string;
	float	distx;
	float	disty;
	float	deltai;
	float	deltaj;

}				t_fract;

int		ft_zoom_mouse(int button, int x, int y, t_fract *fract);
void	draw_mandelbrot(t_fract fract);
void	julia(t_fract fract);
float	draw_color(t_fract fract, int a, int i);

#endif
