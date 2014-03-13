/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:19:27 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/13 12:33:47 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_scene(t_img *img)
{
	init_cam(&img->scene.cam, init_vect(-2, -2, 0));
	img->scene.light = create_light(init_vect(0, 0, -35), 0xffffff);
	img->scene.obj[0] = create_sphere(init_vect(0, 0, -10), 80, 0xffffff);
	img->scene.obj[1] = create_sphere(init_vect(-20, 24, -80), 50, 0x00ff00);
	img->scene.obj[2] = create_sphere(init_vect(10, 10, -100), 50, 0xfff700);
	img->scene.obj[3] = create_sphere(init_vect(200, 200, -150), 50, 0x0000ff);
//	img->scene.obj[4] = create_cone(init_vect(0, 0, -5), 20, 0xff00ff);
	img->scene.obj[4] = create_sphere(init_vect(600, 600, -150), 50, 0xff00ff);
	img->scene.obj[5] = create_cylinder(init_vect(2, 2, -110),
							init_vect(0, 1, 1), 50, 0x777777);
	img->scene.obj[6] = create_plane(init_vect(1, 0, 1),
							init_vect(0, 0, -200), 0xff0000);
	img->scene.obj[7] = create_plane(init_vect(0, 1, 1),
							init_vect(0, 0, -200), 0xffffcc);
}

int		find_inter(t_img *img, int *sv)
{
	int		hit[NB_OBJ];
	int		i;

	i = 0;
	while (i < NB_OBJ)
	{
		hit[i] = intersect_obj(&img->scene.ray, &img->scene.obj[i]);
		i++;
	}
	*sv = closest(hit, NB_OBJ);
	return (hit[*sv]);
}

int		find_color(t_img *img)
{
	int		sv;
	int		color;
	float	light;
	int		dist;

	dist = find_inter(img, &sv);
	if (sv != -1)
	{
		light = find_light(&img->scene.ray, dist,
							img->scene.obj[sv].pos, img->scene.light);
		color = chg_color(img->scene.obj[sv].color, light);
	}
	else
		color = BGD_COLOR;
	return (color);
}

void	calc_image(t_img *img)
{
	int		x;
	int		y;
	int		color;

//	img->scene.ray.orig.x = 0;
//	img->scene.ray.orig.y = 0;
//	img->scene.ray.orig.z = -10;
 	y = 0;
	while (y < WIN_HGT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
//			calc_dir(&img->scene.ray, x, y);
			img->scene.ray = prim_ray(&img->scene.cam, x, y);
			color = find_color(img);
			fill(img, x, y, color);
			x++;
		}
		y++;
	}
}
