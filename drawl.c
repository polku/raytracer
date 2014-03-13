/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 18:45:56 by jmaurice          #+#    #+#             */
/*   Updated: 2014/02/27 12:56:16 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill(t_img *img, int x, int y, int color)
{
	void			*ptr;
	unsigned int	*pxl;
	unsigned int	col;

	col = mlx_get_color_value(img->mlx, color);
	ptr = img->data + y * img->lnsize + (img->bpp / 8) * x;
	pxl = ptr;
	*pxl = col;
}
