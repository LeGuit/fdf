/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:39:35 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/24 13:39:37 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void				try_draw(void *mlx_ptr, t_image *image, t_vect *vertices, t_data *data)
{
	size_t i = 0;
	size_t j = 0;
	(void)mlx_ptr;
	int color1 = mlx_get_color_value(mlx_ptr, 0x00ff7f50);
	int color2 = mlx_get_color_value(mlx_ptr, 0x00ffffff);
	ft_printf("col1: %d\tcol2: %d\n", color1, color2);
	while (j < vertices->size)
	{
		image->data[j + i] = color1;
		image->data[j + i] = color1;
		image->data[j + i] = color1;
		j++;
		if (j % data->nrow == 0)
			i += (image->size_line - j);
	}
}
