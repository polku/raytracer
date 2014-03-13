/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:16:23 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/02 14:53:22 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	solve(float *abc)
{
	float	t[2];
	float	delta;

	delta = powf(abc[1], 2) - 4.0 * abc[0] * abc[2];
	if (delta >= 0)
	{
		t[0] = (-abc[1] + sqrt(delta)) / (2.0 * abc[0]);
		t[1] = (-abc[1] - sqrt(delta)) / (2.0 * abc[0]);
		if (t[0] > t[1])
			t[0] = t[1];
		if (t[0] > 0.001)
			return (t[0]);
	}
	return (0);
}

t_vector	vect_norm(t_vector v)
{
	t_vector	res;
	float		lgth;

	lgth = sqrt(dot_product(v, v));
	if (lgth > 1.0)
		res = init_vect(v.x / lgth, v.y / lgth, v.z / lgth);
	else
		return (v);
	return (res);
}
