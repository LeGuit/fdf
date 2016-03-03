/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:02:41 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/26 18:03:01 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#define CAST(type, ptr)	((type)(ptr))
#define VPOS(i)			CAST(t_vertex *, ft_vect_at(&data->vertices, i))->pos	

void				matrix_calcul(t_data *data, t_matrix *mat)
{
	size_t			i;

	i = 0;
	while (i < data->vertices.size)
	{
		VPOS(i).x = mat->m[0] * VPOS(i).x + mat->m[1] * VPOS(i).y
					+ mat->m[2] * VPOS(i).z + mat->m[3] * VPOS(i).w;
		VPOS(i).y = mat->m[4] * VPOS(i).x + mat->m[5] * VPOS(i).y
					+ mat->m[6] * VPOS(i).z + mat->m[7] * VPOS(i).w;
		VPOS(i).z = mat->m[8] * VPOS(i).x + mat->m[9] * VPOS(i).y
					+ mat->m[10] * VPOS(i).z + mat->m[11] * VPOS(i).w;
		VPOS(i).w = mat->m[12] * VPOS(i).x + mat->m[13] * VPOS(i).y 
					+ mat->m[14] * VPOS(i).z + mat->m[15] * VPOS(i).w;
		i++;
	}
}
