/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:47:24 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/03/31 18:36:02 by ybouzgao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

float		draw_color(t_fract fract, int a, int i)
{
	float color;
	
	if (a == 0)
		color =  ((i*255/(fract.iterations*0.75)) * 1000000) +  i*255/(fract.iterations*0.75);
	else
		color =  255000000 +  (i*255/fract.iterations) * 1000; 
	return (color);
}

void	draw_mandelbrot(t_fract fract)
{
	int i;
	int j;

	i = -1;
	fract.zoom_x = fract.zoom / (fract.X2 - fract.X1); 
	fract.zoom_y = fract.zoom / (fract.Y2 - fract.Y1);
	while (++i < 1000)
	{
		j = -1;	
		while (++j < 1000)
		{
			fract.c_r = i / fract.zoom_x + fract.X1;
			fract.c_i = j / fract.zoom_y + fract.Y1;
			fract.z_r = 0;
			fract.z_i = 0;
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
			else if (fract.k * 100 / fract.iterations < 50)
				fract.img_string[j * 1000 + i] = draw_color(fract, 0, fract.k);
			else 
				fract.img_string[j * 1000 + i] = draw_color(fract, 1, fract.k);
		}
	}
	mlx_put_image_to_window(fract.mlx, fract.win, fract.img, 0, 0);
}

int		ft_interactions2(int keycode, t_fract *fract)
{
	if (keycode == 124)
	{
		fract->X1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		fract->X2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
	}
	if (keycode == 125)
	{
		fract->Y1 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		fract->Y2 += 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
	}
	if (keycode == 126)
	{
		fract->Y1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		fract->Y2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
	}
	if (keycode == 123)
	{
		fract->X1 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
		fract->X2 -= 0.2 / pow(sqrt(fract->zoom_inc), 1.5);
	}
	if (keycode == 91)
	{
		fract->iterations += 10;
	}
	if (keycode == 84)
		fract->iterations -= 10;

	mlx_destroy_image(fract->mlx, fract->img);
	fract->img = mlx_new_image(fract->mlx, 1000, 1000);
	fract->img_string = (int*)mlx_get_data_addr(fract->img, &(fract->bpp), &(fract->s_l), &(fract->endian));
	mlx_clear_window(fract->mlx, fract->win);
	draw_mandelbrot(*fract);
	return (0);
}

int		ft_interactions(int keycode, t_fract *fract)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	ft_interactions2(keycode, fract);
	if (keycode == 53)
		exit(0);
	return (0);
}



int		main(void)
{
	t_fract fract;

	fract.iterations = 150;	
	fract.zoom = 100;
	fract.X1 = -2.1;
	fract.X2 = 0.6;
	fract.zoom_inc = 1;
	fract.Y1 = -1.2;
	fract.Y2 = 1.2;
	fract.JX1 = -1;
	fract.JX2 = 1;
	fract.JY1 = -1.2;
	fract.JY2 = 1.2;
	fract.mlx = mlx_init();
	fract.win = mlx_new_window(fract.mlx, 1000, 1000, "Fractal_Mandelbrot");
	fract.img = mlx_new_image(fract.mlx, 1000, 1000);	
	fract.img_string = (int*)mlx_get_data_addr(fract.img, &(fract.bpp), &(fract.s_l), &(fract.endian));
//	draw_mandelbrot(fract);
	julia(fract);
	mlx_hook(fract.win,2, (1L << 0), ft_interactions, (void *)&fract);
	mlx_mouse_hook(fract.win, ft_zoom_mouse, (void *)&fract);
	mlx_loop(fract.mlx);
	return (0);
}
