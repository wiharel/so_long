/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:48:51 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:48:52 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	render_background(t_data *data, int y, int x, int color)
{
	render_rect(data, &data->img, &data->img_bg, (t_rect){y, x, \
	data->map.rx, data->map.ry, color});
}

void	render_coll(t_data *data, int color)
{
	int	i;

	i = 0;
	while (i < data->count_coll)
	{
		if (data->coll[i].x != 0 && data->coll[i].y != 0)
			render_rect(data, &data->img, &data->img_coll, \
			(t_rect){data->coll[i].y, data->coll[i].x, \
			data->map.rx, data->map.ry, color});
		i++;
	}
}

void	render_exit(t_data *data, int color)
{
	if (data->player.collect == data->count_coll && \
	(data->player.x == data->exit.x && data->player.y == data->exit.y))
		ft_exit(data);
	else if (data->player.collect == data->count_coll)
		render_rect(data, &data->img, &data->img_exit_open, \
		(t_rect){data->exit.y, data->exit.x, data->map.rx, \
		data->map.ry, color});
	else
		render_rect(data, &data->img, &data->img_exit_close, \
		(t_rect){data->exit.y, data->exit.x, data->map.rx, \
		data->map.ry, color});
}

void	render_wall(t_data *data, int color)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	x = 0;
	y = 0;
	while (i < data->map.size_map)
	{
		j = 0;
		while (j < data->map.size_strs)
		{
			if (data->map.mapi[i][j] == '1')
				render_rect(data, &data->img, &data->img_wall, \
				(t_rect){y, x, data->map.rx, data->map.ry, color});
			else
				render_background(data, y, x, WHITE_PIXEL);
			x = x + data->map.rx;
			j++;
		}
		y = y + data->map.ry;
		x = 0;
		i++;
	}
}

void	render_player(t_data *data, int color)
{
	if (data->play_dir == 'l')
		render_rect(data, &data->img, &data->img_playl, \
		(t_rect){data->player.y, data->player.x, \
		data->player.rx, data->player.ry, color});
	else if (data->play_dir == 'u')
		render_rect(data, &data->img, &data->img_playu, \
		(t_rect){data->player.y, data->player.x, \
		data->player.rx, data->player.ry, color});
	else if (data->play_dir == 'd')
		render_rect(data, &data->img, &data->img_playd, \
		(t_rect){data->player.y, data->player.x, \
		data->player.rx, data->player.ry, color});
	else
		render_rect(data, &data->img, &data->img_playr, \
		(t_rect){data->player.y, data->player.x, \
		data->player.rx, data->player.ry, color});
}
