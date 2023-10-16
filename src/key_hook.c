/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:48:10 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:48:11 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_collect(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count_coll)
	{
		if (data->coll[i].x == data->player.x && \
		data->coll[i].y == data->player.y)
		{
			data->coll[i].x = 0;
			data->coll[i].y = 0;
			data->player.collect++;
		}
		i++;
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_exit(data);
	return (0);
}

int	close_window(t_data *data)
{
	ft_exit(data);
	return (0);
}

int	ft_input(int key, t_data *data)
{
	int	i;
	int	j;

	i = data->player.y / data->map.ry;
	j = data->player.x / data->map.rx;
	if (key == 100 && data->map.mapi[i][j + 1] != '1')
		move_right(data);
	else if (key == 97 && data->map.mapi[i][j - 1] != '1')
		move_left(data);
	else if (key == 115 && data->map.mapi[i + 1][j] != '1')
		move_up(data);
	else if (key == 119 && data->map.mapi[i - 1][j] != '1')
		move_down(data);
	printf("moves: %d\n", data->player.mooves);
	ft_collect(data);
	render(data);
	return (0);
}
