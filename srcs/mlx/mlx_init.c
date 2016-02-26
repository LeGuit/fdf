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

void				mlx_start(t_data *data)
{
	t_mlx			mlx;

	(void)data;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, "fdf");
	ft_mlx_image_init(mlx.mlx_ptr, &mlx.screen, W_WIDTH, W_HEIGHT);
	init_views(&data->v_world, &mlx);
	draw(data, &mlx);
	mlx_key_hook(mlx.win_ptr, key_call, 0);
	mlx_loop(mlx.mlx_ptr);
}
