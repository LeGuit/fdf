/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:59:04 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 17:59:05 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int				ft_mlx_image_init(void *mlx_ptr, t_image *image, int width,
				int height)
{
	image->ptr = mlx_new_image(mlx_ptr, width, height);
	image->data = mlx_get_data_addr(image->ptr, &image->bpp, &image->size_line,
									&image->endian);
	return (0);
}
