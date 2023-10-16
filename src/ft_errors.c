/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:47:33 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:47:34 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	free_strs(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size + 1)
		free(strs[i++]);
	free(strs);
	strs = NULL;
}

static void	free_img(t_data *data, t_img *img)
{
	if (img->mlx_img != NULL)
	{
		mlx_destroy_image(data->mlx_ptr, img->mlx_img);
		img = NULL;
	}
	else
		return ;
}

static void	ft_destroy(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (data->img.mlx_img != NULL)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	if (data->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	ft_exit(t_data *data)
{
	if (data->map.mapi != NULL)
		free_strs(data->map.mapi, data->map.size_map);
	free_img(data, &data->img_wall);
	free_img(data, &data->img_bg);
	free_img(data, &data->img_playr);
	free_img(data, &data->img_playl);
	free_img(data, &data->img_playu);
	free_img(data, &data->img_playd);
	free_img(data, &data->img_coll);
	free_img(data, &data->img_exit_close);
	free_img(data, &data->img_exit_open);
	if (data->count_coll > 0)
		free(data->coll);
	ft_destroy(data);
	exit(0);
}

int	ft_errors_parse(char **strs, int size_s, char *com)
{
	if (strs != NULL)
		free_strs(strs, (size_s - 1));
	printf("%s\n", com);
	return (1);
}
