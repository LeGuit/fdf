/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:12:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/03/03 16:12:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			need_reset(int key)
{
	if (key != PLUS && key != MINUS && key != LARROW
		&& key != UARROW && key != DARROW && key != RARROW
		&& key != A_KEY && key != S_KEY && key != W_KEY
		&& key != D_KEY && key != ESC && key != RETURN)
		return (1);
	return (0);
}

static void			key_rot(int key, t_data *data)
{
	t_matrix		mat;

	ft_bzero(&mat, 16);
	if (key == D_KEY)
		rot_proj(&mat, 30);
	else if (key == A_KEY)
		rot_proj(&mat, -30);
	else if (key == W_KEY)
		rot_norm(&mat, 30);
	else if (key == S_KEY)
		rot_norm(&mat, -30);
	matrix_calcul(data, &mat);
}

static void			key_trans(int key, t_data *data)
{
	if (key == LARROW)
		key_larrow(data);
	if (key == RARROW)
		key_rarrow(data);
	if (key == UARROW)
		key_uarrow(data);
	if (key == DARROW)
		key_darrow(data);
}

int					key_hook(int key, void *data)
{
	if (need_reset(key))
		return (0);
	if (key == PLUS)
		key_zoom_in((t_data *)data);
	else if (key == MINUS)
		key_zoom_out((t_data *)data);
	else if (key == ESC)
		key_esc();
	else if (key == RETURN)
		key_return((t_data *)data);
	else if (key == LARROW || key == RARROW || key == DARROW || key == UARROW)
		key_trans(key, (t_data *)data);
	else if (key == D_KEY || key == A_KEY || key == W_KEY || key == S_KEY)
		key_rot(key, (t_data *)data);
	return (1);
}
