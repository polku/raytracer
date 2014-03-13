/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 12:03:07 by jmaurice          #+#    #+#             */
/*   Updated: 2014/02/27 12:57:11 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		main(void)
{
	t_img	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIN_WIDTH, WIN_HGT, "rtv1");
	img.img = mlx_new_image(img.mlx, WIN_WIDTH, WIN_HGT);
	img.data = mlx_get_data_addr(img.img, &img.bpp, &img.lnsize, &img.endian);
	init_scene(&img);
	calc_image(&img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_expose_hook(img.win, event_expose, &img);
	mlx_key_hook(img.win, event_key, &img);
	mlx_loop(img.mlx);
	return (0);
}
