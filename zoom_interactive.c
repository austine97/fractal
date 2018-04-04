/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_interactive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:17:22 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/04/04 22:06:09 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

void	ft_move_to_corner(t_fract *fract, int x, int y)
{
	fract->zoom_x = fract->zoom / (fract->X2 - fract->X1);
	fract->zoom_y = fract->zoom / (fract->Y2 - fract->Y1);
	fract->X1 += x / fract->zoom_x;
	fract->X2 += x / fract->zoom_x;
	fract->Y1 += y / fract->zoom_y;
	fract->Y2 += y / fract->zoom_y;
	printf("X1: %f, X2: %f, Y1; %f, Y2 %f\n", fract->X1, fract->X2, fract->Y1, fract->Y2);
}

void	ft_move_from_corner(t_fract *fract, int x, int y)
{
	fract->zoom_x = fract->zoom / (fract->X2 - fract->X1);
	fract->zoom_y = fract->zoom / (fract->Y2 - fract->Y1);
	fract->X1 -= x / fract->zoom_x;
	fract->X2 -= x / fract->zoom_x;
	fract->Y1 -= y / fract->zoom_y;
	fract->Y2 -= y / fract->zoom_y;
}

int		ft_zoom_mouse(int button, int x, int y, t_fract *fract)
{
	ft_putnbr(button);
		if (button == 5)
		{
			ft_move_to_corner(fract, x, y);
			fract->zoom += 40 * fract->zoom_inc;
			fract->zoom_inc *= 1.2;
			ft_move_from_corner(fract, x, y);
		/*	mlx_destroy_image(fract->mlx, fract->img);
			fract->img = mlx_new_image(fract->mlx, 1000, 1000);
			fract->img_string = (int*)mlx_get_data_addr(fract->img, &(fract->bpp), &(fract->s_l), &(fract->endian));
			mlx_clear_window(fract->mlx, fract->win);
			draw_mandelbrot(*fract);*/
			//return (0);
		}
	if (button == 4)
	{
		ft_move_to_corner(fract, x, y);
		fract->zoom_inc /= 1.2;
		fract->zoom -= 40 * fract->zoom_inc;
		ft_move_from_corner(fract, x, y);
	}
	mlx_destroy_image(fract->mlx, fract->img);
	fract->img = mlx_new_image(fract->mlx, 1000, 1000);
	fract->img_string = (int*)mlx_get_data_addr(fract->img, &(fract->bpp), &(fract->s_l), &(fract->endian));

	mlx_clear_window(fract->mlx, fract->win);
	draw_mandelbrot(*fract);
	return (0);
}

