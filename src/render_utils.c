/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:48:57 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:48:59 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	render_rect(t_data *data, t_img *img, t_img *img2, t_rect rect)
{
	int	i;
	int	j;
	int	sx;
	int	sy;

	i = rect.y;
	sy = 0;
	while (i < rect.y + rect.height)
	{
		sx = 0;
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			if (img2 != NULL)
				rect.color = get_pixel(img2, sx, sy);
			if (rect.color < 0)
				rect.color = get_pixel(&data->img_bg, sx, sy);
			img_pix_put(img, j, i, rect.color);
			j++;
			sx++;
		}
		++i;
		sy++;
	}
	return (0);
}

int	render(t_data *data)
{
	render_wall(data, GREEN_PIXEL);
	render_coll(data, YELLOW_PIXEL);
	render_exit(data, RED_PIXEL);
	render_player(data, BLUE_PIXEL);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->img.mlx_img, 0, 0);
	return (0);
}
