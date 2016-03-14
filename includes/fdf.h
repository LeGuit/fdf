/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:36:36 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/02/24 10:44:39 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include "libft.h"
# define C_VEC4(ptr)		((t_vec4 const *)ptr)
# define W_WIDTH				1600
# define W_HEIGHT				1200
# define C_MIN					0xFF0000
# define C_MAX					0x00FF00

# define ESC				53
# define LARROW				123
# define RARROW				124
# define DARROW				125
# define UARROW				126
# define PLUS				69
# define MINUS				78
# define RETURN				36
# define M_PLUS				5
# define M_MINUS			4
# define M_RETURN			3
# define L_CLICK			1

typedef struct		s_view
{
	float			xmax;
	float			xmin;
	float			ymax;
	float			ymin;
}					t_view;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			screen;
	t_view			v_screen;

}					t_mlx;

typedef struct		s_data
{
	t_vect			vertices;
	t_vect			vert2d;
	t_view			v_world;
	t_mlx			*mlx;
	int				nrow;
	int				ncol;
	float			zmin;
	float			zmax;
}					t_data;

typedef struct		s_matrix
{
	float			m[16];
}					t_matrix;

typedef struct		s_vec4f
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4f;

typedef struct		s_vertex
{
	t_vec4f			pos;
}					t_vertex;

void				error_open(void);
void				error_file(int error);
void				error_map(void);

void				print_vertex(t_vertex const *vec);
void				print_vec4f(t_vec4f const *vec);
void				print_vec3i(t_vec3i const *vec);

void				get_file(char *av, t_data *data);
void				mlx_start(t_data *data);
int					ft_mlx_image_init(void *mlx_ptr, t_image *image,
					int width, int height);

int					key_value(int keycode);
int					key_esc();
int					key_call(int keycode, void *params);
int					key_hook(int keycode, void *data);
int					mouse_hook(int button,int x,int y,void *param);

int					key_zoom_in(t_data *data);
int					key_zoom_out(t_data *data);
int					key_larrow(t_data *data);
int					key_rarrow(t_data *data);
int					key_uarrow(t_data *data);
int					key_darrow(t_data *data);
int					key_return(t_data *data);

void				error_args(void);

void				matrix_calcul(t_data *data, t_matrix *mat);
void				trans_v(t_matrix *mat, int keycode);

void				line_calc(t_data *data, t_mlx *mlx, int index,
					t_vec3i *screen_coord);
void				world_to_view(t_vec4f *v);
void				view_to_screen(t_vec4f *v4f, t_vec3i *v3i,
						t_data *data, t_view *v_screen);

void				draw(t_data *data, t_mlx *mlx);
void				put_pix_to_img(t_vec3i *v, t_image *i);

// void				rot_proj(t_matrix *mat, int theta);
// void				rot_norm(t_matrix *mat, int theta);

int					set_color(int z);
int					mix_color(int c1, int c2, float lambda);

void				build_vect(t_data *data, t_vec3i *v3i_ptr, t_mlx *mlx);

#endif
