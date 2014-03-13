/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:05:05 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/13 14:24:50 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
void	init_cam(t_cam *cam, t_vector pos)
{
	float		h;
	float		w;
	t_vector	center;
	t_vector	n;

	cam->pos = pos;
	cam->look_at = init_vect(0, 0, -1.0);
//	cam->up = init_vect(0, 1, 0); // 0 -1 0
//	cam->right = init_vect(1, 0, 0);
//	cam->right = cross_product(cam->up, cam->look_at); // ?
//	cam->right = vect_norm(cam->right);

//	h = 2 * DIST_VP * tan(FOV_RAD);
//	w = h * RATIO;
	h = .35;
	w = .5;

	n = vect_add(cam->pos, vect_scale(cam->look_at, DIST_VP));
//	n = vect_norm(n);
	cam->up = cross_product(cam->look_at, init_vect(0, -1.0, 0));
	cam->up = vect_norm(cam->up);
	cam->right = cross_product(vect_scale(cam->look_at, -1.0), cam->up);
	cam->right = vect_norm(cam->right);

//	n = vect_scale(n, DIST_VP);
//	center = vect_sub(cam->pos, n);

	center = n;
	cam->upleft = vect_scale(center, -h);
	cam->upleft = vect_scale(cam->upleft, -w);

	cam->height = h / WIN_HGT;
	cam->width = w / WIN_WIDTH;
}
//*/
//*
void	init_cam(t_cam *cam, t_vector pos)
{
	float		h;
	float		w;
	t_vector	center;

	cam->pos = pos;
	cam->up = init_vect(0, 1, 0); // 0 -1 0
	cam->look_at = init_vect(0, 0, -1);
//	cam->look_at = vect_norm(cam->look_at);
	cam->right = init_vect(1, 0, 0);
//	cam->right = cross_product(cam->up, cam->look_at); // ?

//	h = 2 * DIST_VP * tan(FOV_RAD);
//	w = h * RATIO;
	h = .35;
	w = .5;

	center = vect_sub(cam->pos, vect_scale(cam->look_at, -DIST_VP));

	cam->upleft = vect_scale(center, -h / 2.0);
	cam->upleft = vect_scale(cam->upleft, -w / 2.0);

	cam->height = h / WIN_HGT;
	cam->width = w / WIN_WIDTH;
}
//*/

t_ray	prim_ray(t_cam *cam, int x, int y)
{
	t_ray		ray;
	t_vector	u;
	t_vector	v;

	ray.orig = cam->pos;
	u = vect_scale(cam->right, y * cam->width);
	v = vect_scale(cam->up, x * cam->height);
//	ray.dir = vect_add(cam->upleft, vect_add(u, v));
	ray.dir = vect_add(cam->upleft, u);
	ray.dir = vect_add(ray.dir, v);
//	ray.dir = vect_sub(ray.dir, ray.orig);
	ray.dir = vect_norm(ray.dir);
	return (ray);
}

/*
void	calc_dir(t_ray *ray, int x, int y)
{
	t_vector	dir;
	float		x_dir;
	float		y_dir;

	x_dir = (float) (x + .5f) / WIN_WIDTH;
	y_dir = (float) (y + .5f) / WIN_HGT;
	x_dir = (2 * x_dir - 1) * RATIO * tan(FOV_RAD);
	y_dir = 1 - 2 * y_dir * tan(FOV_RAD);
	dir = init_vect(x_dir, y_dir, -10);
	dir = vect_sub(dir, ray->orig);
	ray->dir = vect_norm(dir);
}
//*/
