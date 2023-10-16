/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:48:39 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:48:40 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	gps_coll(t_data *data, int x, int y, int c)
{
	data->coll[c].x = x;
	data->coll[c].y = y;
}

static void	get_char(t_data *data, char c, int x, int y)
{
	if (c == 'P')
	{
		data->player.x = x;
		data->player.y = y;
		data->player.rx = data->map.rx;
		data->player.ry = data->map.ry;
	}
	if (c == 'E')
	{
		data->exit.x = x;
		data->exit.y = y;
	}
}

void	ft_get_gps(t_data *data)
{
	int	i;
	int	j;
	int	c;
	int	x;
	int	y;

	i = 0;
	c = 0;
	y = 0;
	while (i < data->map.size_map)
	{
		j = 0;
		x = 0;
		while (j < data->map.size_strs)
		{
			get_char(data, data->map.mapi[i][j], x, y);
			if (data->map.mapi[i][j] == 'C')
				gps_coll(data, x, y, c++);
			x = x + data->map.rx;
			j++;
		}
		y = y + data->map.ry;
		i++;
	}
}

void	ft_count_coll(t_data *data)
{
	int		i;
	int		j;
	int		c;
	t_gps	co;

	i = 0;
	c = 0;
	while (i < data->map.size_map)
	{
		j = 0;
		while (data->map.mapi[i][j])
		{
			if (data->map.mapi[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	data->count_coll = c;
	data->coll = malloc(sizeof(co) * c);
	if (data->coll == NULL)
		return ;
}
