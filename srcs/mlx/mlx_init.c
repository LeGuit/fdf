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

void				mlx_start(t_data *data)
{
	t_mlx			mlx;

	(void)data;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W_WIDTH, W_HEIGHT, "fdf");
	ft_mlx_image_init(mlx.mlx_ptr, &mlx.screen, I_WIDTH, I_HEIGHT);
	try_draw(&mlx.screen, &data->vertices, data);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.screen.ptr, 50, 50);
	mlx_key_hook(mlx.win_ptr, key_call, 0);
	mlx_loop(mlx.mlx_ptr);
}
