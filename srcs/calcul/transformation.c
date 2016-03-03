/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:05:21 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/26 18:05:24 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void				rot_x(t_matrix *mat, int theta)
{
	mat->m[0] = 1;
	mat->m[5] = cos(theta);
	mat->m[6] = -sin(theta);
	mat->m[9] = sin(theta);
	mat->m[10] = cos(theta);
	mat->m[15] = 1;
}

void				rot_y(t_matrix *mat, int theta)
{
	mat->m[5] = 1;
	mat->m[0] = cos(theta);
	mat->m[8] = -sin(theta);
	mat->m[2] = sin(theta);
	mat->m[10] = cos(theta);
	mat->m[15] = 1;
}
