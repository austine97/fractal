/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:16:53 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/03/31 18:46:50 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia(t_fract fract)
{
	int i;
	int j;

	i = -1;
	fract.zoom_x = fract.zoom / (fract.JX2 - fract.JX1);
	fract.zoom_y = fract.zoom / (fract.JY2 - fract.JY1);
	while (++i < 1000)
	{
		j = -1;
		while (++j < 1000)
		{
			fract.c_r = 0.285;
			fract.c_i = 0.01;
			fract.z_r = i / fract.zoom + fract.JX1;
			fract.z_i = j / fract.zoom + fract.JY1;
			fract.k = 0;
			while (fract.z_r * fract.z_r + fract.z_i * fract.z_i <= 4 && fract.k < fract.iterations)
			{
				fract.tmp = fract.z_r * fract.z_r - fract.z_i * fract.z_i + fract.c_r;
				fract.z_i = 2 * fract.z_r * fract.z_i + fract.c_i;
				fract.z_r = fract.tmp;
				++fract.k;
			}
			if (fract.k >= fract.iterations)
				fract.img_string[j * 1000 + i] = 0xFFFFFF;
			/*else if (fract.k * 100 / fract.iterations < 50)
				fract.img_string[j * 1000 + i] = draw_color(fract, 0, fract.k);
			else
				fract.img_string[j * 1000 + i] = draw_color(fract, 1, fract.k);
		*/}
	}
	mlx_put_image_to_window(fract.mlx, fract.win, fract.img, 0, 0);
}
