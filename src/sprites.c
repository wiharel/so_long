/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:49:03 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:49:04 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	get_texture(t_data *data, t_img *img, char *path)
{
	int	width;
	int	height;

	img->mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, path, &width, &height);
	if (img->mlx_img == NULL)
	{
		printf("Error: textures is invalid\n");
		ft_exit(data);
	}
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, \
	&img->line_len, &img->endian);
	return (0);
}

static int	ft_texture_x32(t_data *data)
{
	get_texture(data, &data->img_wall, "./textures/Thewall.xpm");
	get_texture(data, &data->img_bg, "./textures/Thefloor.xpm");
	get_texture(data, &data->img_playr, "./textures/Pr.xpm");
	get_texture(data, &data->img_playl, "./textures/Pl.xpm");
	get_texture(data, &data->img_playu, "./textures/Pd.xpm");
	get_texture(data, &data->img_playd, "./textures/Pu.xpm");
	get_texture(data, &data->img_coll, "./textures/end.xpm");
	get_texture(data, &data->img_exit_close, "./textures/exitA.xpm");
	get_texture(data, &data->img_exit_open, "./textures/exitB.xpm");
	return (0);
}

static int	ft_texture_x16(t_data *data)
{
	get_texture(data, &data->img_wall, "./textures/Thewall16x.xpm");
	get_texture(data, &data->img_bg, "./textures/Thefloor16x.xpm");
	get_texture(data, &data->img_playr, "./textures/Pr_16x.xpm");
	get_texture(data, &data->img_playl, "./textures/Pl_16x.xpm");
	get_texture(data, &data->img_playu, "./textures/Pd_16x.xpm");
	get_texture(data, &data->img_playd, "./textures/Pu_16x.xpm");
	get_texture(data, &data->img_coll, "./textures/end16x.xpm");
	get_texture(data, &data->img_exit_close, "./textures/exitA16x.xpm");
	get_texture(data, &data->img_exit_open, "./textures/exitB16x.xpm");
	return (0);
}

void	ft_get_texture(t_data *data)
{
	if (data->map.size_pix == 32)
		ft_texture_x32(data);
	else if (data->map.size_pix == 16)
		ft_texture_x16(data);
}
