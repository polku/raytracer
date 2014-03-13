/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:11:01 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/01 17:29:38 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	init_vect(float a, float b, float c)
{
	t_vector	v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}

int			closest(int *hit, int sz)
{
	int		min;
	int		i;
	int		res;

	i = 0;
	min = 2000000000;
	res = -1;
	while (i < sz)
	{
		if (hit[i] <= min && hit[i] != 0)
		{
			res = i;
			min = hit[i];
		}
		i++;
	}
	return (res);
}

float		find_light(t_ray *ray, float t, t_vector pos, t_light light)
{
	t_vector	norm;
	t_ray		light_ray;

	light_ray.orig = vect_add(ray->orig, vect_scale(ray->dir, t));
	light_ray.dir = vect_norm(vect_sub(light.pos, light_ray.orig));
	norm = vect_norm(vect_sub(light_ray.orig, pos));
//	sv = find_inter(img, &sv);
	return (dot_product(light_ray.dir, norm));
}

int			chg_color(int color, float lambert)
{
	int		red;
	int		green;
	int		blue;

	if (lambert < AMBIANT)
		lambert = AMBIANT;
	red = color & 0x00ff0000;
	red = red >> 16;
	red *= lambert;
	green = color & 0x0000ff00;
	green = green >> 8;
	green *= lambert;
	blue = color & 0x000000ff;
	blue *= lambert;
	color = red * 65536 + green * 256 + blue;
	return (color);
}
