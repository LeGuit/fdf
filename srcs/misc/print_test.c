/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:24:22 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/23 16:52:14 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void			print_vertex(t_vertex const *vertex)
{
	print_vec4(&vertex->pos);
}

void			print_vec4(t_vec4 const *vec)
{
	printf("%f %f %f %f\n", (vec->x), (vec->y), (vec->z), vec->w);
}
