/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:48:15 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:48:17 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	so_long(t_data *data)
{
	ft_window_size(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	data->window_width, data->window_height, "So_Long");
	if (data->win_ptr == NULL)
		ft_exit(data);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, \
	data->window_width, data->window_height);
	if (data->img.mlx_img == NULL)
	{
		printf("Error: mlx error\n");
		ft_exit(data);
	}
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, \
	&data->img.bpp, &data->img.line_len, &data->img.endian);
	ft_size_rect(data);
	ft_count_coll(data);
	ft_get_gps(data);
	ft_get_texture(data);
	render(data);
	mlx_key_hook(data->win_ptr, &ft_input, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, 33, 1L << 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}

// MAIN
int	main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(&data);
	if (argc == 1)
	{
		return (ft_errors_parse(NULL, 0, "Error: no map in args"));
	}
	else if (argc == 2)
	{
		if (ft_parse(argv[1], &data))
			return (0);
	}
	else
	{
		printf("Error: too many args\n");
		return (0);
	}
	if (data.map.mapi == NULL)
		ft_exit(&data);
	ft_size_map(&data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		ft_exit(&data);
	so_long(&data);
	return (0);
}
