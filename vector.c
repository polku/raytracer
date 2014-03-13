/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 13:00:27 by jmaurice          #+#    #+#             */
/*   Updated: 2014/02/28 14:30:49 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vect_add(t_vector v1, t_vector v2)
{
	t_vector	res;

	res = init_vect(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return (res);
}

t_vector	vect_sub(t_vector v1, t_vector v2)
{
	t_vector	res;

	res = init_vect(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	return (res);
}

t_vector	cross_product(t_vector v1, t_vector v2)
{
	t_vector	res;

	res = init_vect(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
	return (res);
}

t_vector	vect_scale(t_vector v1, float f)
{
	t_vector	res;

	res = init_vect(v1.x * f, v1.y * f, v1.z * f);
	return (res);
}

float		dot_product(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
