/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:48:21 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:48:22 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_size_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.mapi[i] && data->map.mapi[i][0] != '\0')
		i++;
	data->map.size_map = i;
	i = 0;
	while (data->map.mapi[i][j] != '\0')
		j++;
	data->map.size_strs = j;
}

void	ft_size_rect(t_data *data)
{
	data->map.ry = data->window_height / data->map.size_map;
	data->map.rx = data->window_width / data->map.size_strs;
}
