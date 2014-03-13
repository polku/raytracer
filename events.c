/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 15:20:28 by jmaurice          #+#    #+#             */
/*   Updated: 2014/02/27 12:56:27 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		event_expose(void *param)
{
	t_img	*img;

	img = (t_img *)	param;
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int		event_key(int keycode, void *param)
{
	t_img	*img;
	int		i;

	img = (t_img *)	param;
	if (keycode == EXIT)
	{
		i = 0;
		while (i < NB_OBJ)
		{
			free(img->scene.obj[i].prim);
			i++;
		}
		exit(1);
	}
	return (0);
}
