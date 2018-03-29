/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:51:47 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/03/29 21:28:51 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define ITERATION_MAX 100
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
	int		zoom;
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
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_string;

}				t_fract;

#endif
