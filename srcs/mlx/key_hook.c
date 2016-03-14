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
		&& key != ESC && key != RETURN)
		return (1);
	return (0);
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

int					mouse_hook(int button, int x, int y, void *data)
{
	if (button == M_PLUS)
		key_zoom_in((t_data *)data);
	else if (button == M_MINUS)
		key_zoom_out((t_data *)data);
	else if (button == M_RETURN)
		key_return((t_data *)data);
	else if (button == L_CLICK && x < W_WIDTH / 3
		&& y > W_HEIGHT / 3 && y < W_HEIGHT * 2 / 3)
		key_trans(LARROW, (t_data *)data);
	else if (button == L_CLICK && x > W_WIDTH * 2 / 3
		&& y > W_HEIGHT / 3 && y < W_HEIGHT * 2 / 3)
		key_trans(RARROW, (t_data *)data);
	else if (button == L_CLICK && y < W_HEIGHT / 3
		&& x > W_WIDTH / 3 && x < W_WIDTH * 2 / 3)
		key_trans(UARROW, (t_data *)data);
	else if (button == L_CLICK && y > W_HEIGHT * 2 / 3
		&& x > W_WIDTH / 3 && x < W_WIDTH * 2 / 3)
		key_trans(DARROW, (t_data *)data);
	else if (button == L_CLICK && x < W_WIDTH / 3 && y < W_HEIGHT / 3)
	{
		key_trans(LARROW, (t_data *)data);
		key_trans(UARROW, (t_data *)data);
	}
	else if (button == L_CLICK && x > W_WIDTH * 2 / 3 && y < W_HEIGHT / 3)
	{
		key_trans(RARROW, (t_data *)data);
		key_trans(UARROW, (t_data *)data);
	}
	else if (button == L_CLICK && x > W_WIDTH * 2 / 3 && y > W_HEIGHT * 2 / 3)
	{
		key_trans(RARROW, (t_data *)data);
		key_trans(DARROW, (t_data *)data);
	}
	else if (button == L_CLICK && x < W_WIDTH / 3 && y > W_HEIGHT * 2 / 3)
	{
		key_trans(LARROW, (t_data *)data);
		key_trans(DARROW, (t_data *)data);
	}
	return (1);
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
	return (1);
}
