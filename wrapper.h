/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:03:56 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/24 13:53:54 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPER_H
# define WRAPPER_H
# include "libft.h"
# include "mlx.h"
# include <time.h>

# define WINDOW_NAME "RTv1"
# define RGB(r,g,b) ((b) + ((g) << 8) + ((r) << 16))
# define V2(x,y) ((t_vec2){x,y})
# define V3(x,y,z) ((t_vec3){x,y,z})
# define V3_MINUS_V3(a,b) (V3(a.x - b.x, a.y - b.y, a.z - b.z))
# define V3_PLUS_V3(a,b) (V3(a.x + b.x, a.y + b.y, a.z + b.z))
# define V3_DOT(a,b) (a.x * b.x + a.y * b.y + a.z * b.z)
# define MAT_ROW(m,x,y,z,w) m[0] = x;m[1] = y;m[2] = z;m[3] = w

typedef struct		s_vec2
{
	double			x;
	double			y;
}					t_vec2;

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef struct		s_mat
{
	int				order;
	double			m[4][4];
}					t_mat;

typedef struct		s_ctx
{
	void			*mlx;
	void			*win;
	t_list			*buffs;
}					t_ctx;

typedef struct		s_buff
{
	t_ctx			*ctx;
	int				depth;
	int				width;
	int				endianess;
	int				x;
	int				y;
	void			*obj;
	char			*data;
}					t_buff;

t_ctx				*context_new();

t_buff				*buffer_new(t_ctx *c, unsigned x, unsigned y);
void				buffer_point(t_buff *b,
						unsigned x, unsigned y, unsigned color);
void				buffer_blit(t_buff *b, unsigned x, unsigned y);
void				buffer_del(t_buff *b);
int					blit_all(t_ctx *c);

t_mat				*mat_new(int order);
void				mat_del(t_mat *m);
t_mat				*mat_x_mat(const t_mat *a, const t_mat *b);
void				mat_inverse(const t_mat *m, t_mat *r);

t_vec3				vec3_x_mat(t_vec3 v, t_mat *m);
double				vec3_length(t_vec3 *v);
t_vec3				vec3_normalize(t_vec3 v);
t_vec3				vec3_cross_product(t_vec3 a, t_vec3 b);
t_vec3				vec3_minus_vec3(t_vec3 a, t_vec3 b);
void				look_at(t_vec3 from, t_vec3 to, t_mat *cam);
#endif
