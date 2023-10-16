/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:49:09 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:49:10 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_window_size(t_data *data)
{
	double	width;
	double	height;

	height = data->map.size_map;
	width = data->map.size_strs;
	data->map.size_pix = 32;
	data->window_height = height * data->map.size_pix;
	data->window_width = width * data->map.size_pix;
	if (data->window_height > 700 || data->window_width > 1200)
	{
		data->map.size_pix = 16;
		data->window_height = height * data->map.size_pix;
		data->window_width = width * data->map.size_pix;
		if (data->window_height > 700 || data->window_width > 1200)
		{
			printf("Error: map is too big\n");
			data->map.size_pix = 0;
			ft_exit(data);
		}
	}
}
