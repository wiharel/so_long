/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:48:33 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:48:34 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	move_right(t_data *data)
{
	data->player.x += data->map.rx;
	data->play_dir = 'r';
	data->player.mooves++;
}

void	move_left(t_data *data)
{
	data->player.x -= data->map.rx;
	data->play_dir = 'l';
	data->player.mooves++;
}

void	move_up(t_data *data)
{
	data->player.y += data->map.ry;
	data->play_dir = 'u';
	data->player.mooves++;
}

void	move_down(t_data *data)
{
	data->player.y -= data->map.ry;
	data->play_dir = 'd';
	data->player.mooves++;
}
