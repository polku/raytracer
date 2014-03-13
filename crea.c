/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 11:47:58 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/02 17:08:54 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_prim		create_sphere(t_vector vect, int radius, int color)
{
	t_prim		prim;
	t_sphere	*sph;

	sph = (t_sphere *) malloc(sizeof(t_sphere));
	sph->radius = radius;
	sph->pos = vect;
	prim.pos = vect;
	prim.type = SPHERE;
	prim.color = color;
	prim.prim = sph;
	return (prim);
}

t_prim		create_plane(t_vector norm, t_vector pos, int color)
{
	t_prim		prim;
	t_plane		*plane;

	plane = (t_plane *) malloc(sizeof(t_plane));
	plane->norm = norm;
	plane->pos = pos;
	prim.pos = pos;
	prim.type = PLANE;
	prim.color = color;
	prim.prim = plane;
	return (prim);
}

t_prim		create_cylinder(t_vector pos, t_vector up, int radius, int color)
{
	t_prim		prim;
	t_cylinder	*cyl;

	cyl = (t_cylinder *) malloc(sizeof(t_cylinder));
	cyl->pos = pos;
	cyl->up = up;
	cyl->radius = radius;
	prim.pos = pos;
	prim.type = CYL;
	prim.color = color;
	prim.prim = cyl;
	return (prim);
}

t_prim		create_cone(t_vector pos, float radius, int color)
{
	t_prim		prim;
	t_cone		*cone;

	cone = (t_cone *) malloc(sizeof(t_cone));
	cone->pos = pos;
	cone->base_radius = radius;
	prim.pos = pos;
	prim.type = CONE;
	prim.color = color;
	prim.prim = cone;
	return (prim);
}

t_light		create_light(t_vector pos, int color)
{
	t_light		light;

	light.pos = pos;
	light.color = color;
	return (light);
}
