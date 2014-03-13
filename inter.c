/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:09:04 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/04 14:35:38 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersect_obj(t_ray *ray, t_prim *prim)
{
	int			res;
	static int	(*func_arr[4])(t_ray *, void *) = { NULL };

	if (func_arr[0] == NULL)
	{
		func_arr[0] = &intersect_sphere;
		func_arr[1] = &intersect_plane;
		func_arr[2] = &intersect_cylinder;
		func_arr[3] = &intersect_cone;
	}
	res = func_arr[prim->type](ray, prim->prim);
	return (res);
}

int		intersect_sphere(t_ray *ray, void *ptr)
{
	t_vector	dist;
	float		abc[3];
	t_sphere	*sph;

	sph = (t_sphere *) ptr;
	dist = vect_sub(ray->orig, sph->pos);
	abc[0] = dot_product(ray->dir, ray->dir);
	abc[1] = 2 * dot_product(ray->dir, dist);
	abc[2] = dot_product(dist, dist) - powf(sph->radius, 2);
	return (solve(abc));
}

int		intersect_plane(t_ray *ray, void *ptr)
{
	float		t;
	t_vector	v;
	t_plane		*p;

	p = (t_plane *) ptr;
	v = vect_sub(p->pos, ray->orig);
	t = dot_product(v, p->norm) / dot_product(ray->dir, p->norm);
	if (t > 0.001)
		return (t);
	return (0);
}

int		intersect_cylinder(t_ray *ray, void *ptr)
{
	float		abc[3];
	t_vector	dist;
	t_vector	tmp;
	t_cylinder	*cyl;

	cyl = (t_cylinder *) ptr;
	dist = vect_sub(ray->orig, cyl->pos);
	tmp = cross_product(cyl->up, ray->dir);
	abc[0] = dot_product(tmp, tmp);
	abc[1] = 2 * (dot_product(dist, tmp));
	abc[2] = dot_product(dist, dist) - powf(cyl->radius, 2);
	return (solve(abc));
}

int		intersect_cone(t_ray *ray, void *ptr)
{
	float	abc[3];
	t_cone	*cone;

	cone = (t_cone *) ptr;
	abc[0] = powf(ray->dir.x, 2) - cone->base_radius * powf(ray->dir.y, 2) + powf(ray->dir.z, 2);
	abc[1] = 2 * (ray->orig.x * ray->dir.x - cone->base_radius * ray->orig.y * ray->dir.y + ray->orig.z * ray->dir.z);
	abc[2] = powf(ray->orig.x, 2) - cone->base_radius * powf(ray->orig.y, 2) + powf(ray->orig.z, 2);
	return (solve(abc));
}
