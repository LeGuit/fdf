/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:29:31 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/03 10:29:31 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

#define GET_R(color)			(((color) & 0xFF0000) >> 16)
#define GET_G(color)			(((color) & 0x00FF00) >> 8)
#define GET_B(color)			((color) & 0x0000FF)

#define SET_R(dst, src)			(dst) |= (((src) & 0xFF) << 16)
#define SET_G(dst, src)			(dst) |= (((src) & 0xFF) << 8)
#define SET_B(dst, src)			(dst) |= ((src) & 0xFF)

static int			mix_int(int a, int b, float lambda)
{
	return ((float)a * (1.f - lambda) + (float)b * lambda);
}

int					mix_color(int c1, int c2, float lambda)
{
	int				res;

	res = 0;
	SET_R(res, mix_int(GET_R(c1), GET_R(c2), lambda));
	SET_G(res, mix_int(GET_G(c1), GET_G(c2), lambda));
	SET_B(res, mix_int(GET_B(c1), GET_B(c2), lambda));
	return (res);
}
