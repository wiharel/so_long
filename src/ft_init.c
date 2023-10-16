/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:47:39 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:47:40 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void	init_map(t_data *data)
{
	data->map.mapi = NULL;
	data->map.size_map = 0;
	data->map.size_strs = 0;
	data->map.size_pix = 0;
	data->map.rx = 0;
	data->map.ry = 0;
}

static void	ft_init_img(t_img *img)
{
	img->mlx_img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
}

static void	init_imgs(t_data *data)
{
	ft_init_img(&data->img);
	ft_init_img(&data->img_wall);
	ft_init_img(&data->img_bg);
	ft_init_img(&data->img_playr);
	ft_init_img(&data->img_playl);
	ft_init_img(&data->img_playu);
	ft_init_img(&data->img_playd);
	ft_init_img(&data->img_coll);
	ft_init_img(&data->img_exit_close);
	ft_init_img(&data->img_exit_open);
}

static void	init_player(t_play *player)
{
	player->x = 0;
	player->y = 0;
	player->rx = 0;
	player->ry = 0;
	player->collect = 0;
	player->mooves = 0;
}

void	ft_init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	init_map(data);
	init_imgs(data);
	data->play_dir = 0;
	data->window_width = 0;
	data->window_height = 0;
	init_player(&data->player);
	data->count_coll = 0;
}
