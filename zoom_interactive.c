/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_interactive.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:17:22 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/04/05 17:41:25 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

void	ft_move_to_corner(t_fract *fract, int x, int y, int a)
{
	if (a == 1)
	{
		fract->zoom_x = fract->zoom / (fract->X2 - fract->X1);
		fract->zoom_y = fract->zoom / (fract->Y2 - fract->Y1);
		fract->X1 += x / fract->zoom_x;
		fract->X2 += x / fract->zoom_x;
		fract->Y1 += y / fract->zoom_y;
		fract->Y2 += y / fract->zoom_y;
	}
	else if (a == 2)
	{
		fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
		fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
		fract->JX1 += x / fract->zoom_x;
		fract->JX2 += x / fract->zoom_x;
		fract->JY1 += y / fract->zoom_y;
		fract->JY2 += y / fract->zoom_y;
	}
}

void	ft_move_from_corner(t_fract *fract, int x, int y, int a)
{
	if (a == 1)
	{
		fract->zoom_x = fract->zoom / (fract->X2 - fract->X1);
		fract->zoom_y = fract->zoom / (fract->Y2 - fract->Y1);
		fract->X1 -= x / fract->zoom_x;
		fract->X2 -= x / fract->zoom_x;
		fract->Y1 -= y / fract->zoom_y;
		fract->Y2 -= y / fract->zoom_y;
	}
	else if (a == 2)
	{
		fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
		fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
		fract->JX1 -= x / fract->zoom_x;
		fract->JX2 -= x / fract->zoom_x;
		fract->JY1 -= y / fract->zoom_y;
		fract->JY2 -= y / fract->zoom_y;
	}
}

int		ft_zoom_mouse(int button, int x, int y, t_fract *fract)
{
	if (button == 5)
	{
		ft_move_to_corner(fract, x, y, 2);
		fract->zoom += 40 * fract->zoom_inc;
		fract->zoom_inc *= 1.2;
		ft_move_from_corner(fract, x, y, 2);
	}
	if (button == 4)
	{
		if (fract->julia_change == 0)
		{
			ft_move_to_corner(fract, x, y, 2);
			fract->zoom_inc /= 1.2;
			fract->zoom -= 40 * fract->zoom_inc;
			ft_move_from_corner(fract, x, y, 2);
		}
		else
		{
			fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
			fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
			fract->c_r = fract->JX1 + x / fract->zoom_x;
			fract->c_i = fract->JY1 + y / fract->zoom_y;
		}
	}
	if (button == 1)
	{
		fract->julia_change = fract->julia_change == 1 ? 0 : 1;
		//	fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
		//	fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
		//	fract->c_r = fract->JX1 + x / fract->zoom_x;
		//	fract->c_i = fract->JY1 + y / fract->zoom_y;
	}
	/*if (fract->julia_change == 1)
	  {
	  ft_putendl("enters change");
	  fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
	  fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
	  fract->c_r = fract->JX1 + x / fract->zoom_x;
	  fract->c_i = fract->JY1 + y / fract->zoom_y;
	  }*/
	mlx_destroy_image(fract->mlx, fract->img);
	fract->img = mlx_new_image(fract->mlx, 1000, 1000);
	fract->img_string = (int*)mlx_get_data_addr(fract->img, &(fract->bpp), &(fract->s_l), &(fract->endian));

	mlx_clear_window(fract->mlx, fract->win);
	//draw_mandelbrot(*fract);
	julia(*fract);
	return (0);
}

