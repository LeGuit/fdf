/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:03:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/24 10:43:13 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>

#include <stdio.h>

void				init_views(t_view *v_world, t_mlx *mlx)
{
	v_world->xmin = -20;
	v_world->xmax = 20;
	v_world->ymin = -20;
	v_world->ymax = 20;
	mlx->v_screen.xmin = 0.f;
	mlx->v_screen.xmax = (float)mlx->screen.width;
	mlx->v_screen.ymin = 0.f;
	mlx->v_screen.ymax = (float)mlx->screen.height;
}

int				fdf_loop(t_data *data)
{
	ft_bzero(data->mlx->screen.data, data->mlx->screen.width * data->mlx->screen.height * 4);
	draw(data, data->mlx);
	return (0);
}

void				mlx_start(t_data *data)
{
	t_mlx			mlx;

	data->mlx = &mlx;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, "fdf");
	ft_mlx_image_init(mlx.mlx_ptr, &mlx.screen, W_WIDTH, W_HEIGHT);
	init_views(&data->v_world, &mlx);
	mlx_key_hook(mlx.win_ptr, key_call, data);
	// printf("xmin: %f\t xmax: %f\t ymin: %f\tymax: %f\n", 
	// 	data->v_world.xmin, data->v_world.xmax, data->v_world.ymin, data->v_world.ymax);
	mlx_loop_hook(mlx.mlx_ptr, fdf_loop, data);
	mlx_loop(mlx.mlx_ptr);
}
