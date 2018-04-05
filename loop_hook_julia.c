/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_julia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:06:18 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/04/05 17:25:56 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_loop_julia(t_fract *fract)
{
	if (fract->julia_change == 1)
	{
		fract->zoom_x = fract->zoom / (fract->JX2 - fract->JX1);
		fract->zoom_y = fract->zoom / (fract->JY2 - fract->JY1);
		fract->c_r = fract->JX1 + fract->mousex / fract->zoom_x;
		fract->c_i = fract->JY1 + fract->mousey / fract->zoom_y;
	}
	mlx_destroy_image(fract->mlx, fract->img);
	fract->img = mlx_new_image(fract->mlx, 1000, 1000);
	fract->img_string = (int*)mlx_get_data_addr(fract->img, &(fract->bpp), &(fract->s_l), &(fract->endian));

	mlx_clear_window(fract->mlx, fract->win);
	julia(*fract);
	return (0);
}
