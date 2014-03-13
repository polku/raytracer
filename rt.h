/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 12:03:34 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/12 16:13:52 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <X11/X.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>

# define EXIT		65307
# define WIN_WIDTH	1440.0f
# define WIN_HGT	900.0f
# define BGD_COLOR	0x000000
# define NB_OBJ		8
# define AMBIANT	0.2f
# define RATIO		(WIN_WIDTH / WIN_HGT)
# define FOV		60.0f
# define PI			3.141592654
# define FOV_RAD	((FOV / 2) * PI / 180.0f)
# define DIST_VP	1.0

typedef enum	e_type
{
	SPHERE	= 0,
	PLANE	= 1,
	CYL		= 2,
	CONE	= 3
}				e_type;

typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
}				t_vector;

typedef struct	s_sphere
{
	t_vector	pos;
	float		radius;
	int			color;
}				t_sphere;

typedef struct	s_plane
{
	t_vector	pos;
	t_vector	norm;
	int			color;
}				t_plane;

typedef struct	s_cylinder
{
	t_vector	pos;
	t_vector	up;
	float		radius;
	int			color;
}				t_cylinder;

typedef struct	s_cone
{
	t_vector	pos;
	t_vector	up;
	float		base_radius;
	float		up_radius;
	int			color;
}				t_cone;

typedef struct	s_prim
{
	e_type		type;
	int			color;
	t_vector	pos;
	void		*prim;
}				t_prim;

typedef struct	s_ray
{
	t_vector	orig;
	t_vector	dir;
}				t_ray;

typedef struct	s_light
{
	t_vector	pos;
	int			color;
}				t_light;

typedef struct	s_cam
{
	t_vector	pos;
	t_vector	upleft;
	t_vector	up;
	t_vector	right;
	t_vector	look_at;
	float		height;
	float		width;
}				t_cam;

typedef struct	s_scene
{
	t_ray		ray;
	t_cam		cam;
	t_prim		obj[NB_OBJ];
	t_light		light;
}				t_scene;

typedef struct	s_img
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			lnsize;
	int			endian;
	t_scene		scene;
}				t_img;

int			event_key(int keycode, void *param);
int			event_expose(void *param);
void		fill(t_img *img, int x, int y, int color);
t_vector	init_vect(float a, float b, float c);
t_vector	vect_add(t_vector v1, t_vector v2);
t_vector	vect_sub(t_vector v1, t_vector v2);
t_vector	cross_product(t_vector v1, t_vector v2);
t_vector	vect_scale(t_vector v1, float f);
float		solve(float *abc);
t_vector	vect_norm(t_vector v);
float		dot_product(t_vector v1, t_vector v2);
void		init_cam(t_cam *cam, t_vector pos);
t_ray		prim_ray(t_cam *cam, int x, int y);
int			intersect_obj(t_ray *ray, t_prim *prim);
int			intersect_sphere(t_ray *ray, void *sph);
int			intersect_plane(t_ray *ray, void *p);
int			intersect_cylinder(t_ray *ray, void *cyl);
int			intersect_cone(t_ray *ray, void *cone);
t_prim		create_sphere(t_vector vect, int radius, int color);
t_prim		create_plane(t_vector norm, t_vector pt, int color);
t_prim		create_cylinder(t_vector pos, t_vector up, int radius, int color);
t_prim		create_cone(t_vector pos, float radius, int color);
t_light		create_light(t_vector pos, int color);
int			closest(int *hit, int sz);
float		find_light(t_ray *ray, float t, t_vector pos, t_light light);
int			chg_color(int color, float lambert);
void		calc_dir(t_ray *ray, int x, int y);
void		init_scene(t_img *img);
int			find_inter(t_img *img, int *sv);
int			find_color(t_img *img);
void		calc_image(t_img *img);

#endif /* !RT_H */
