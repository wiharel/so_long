/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:47:44 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:47:46 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ft_new_line(t_data *data, int index, char *line)
{
	int	len;
	int	i;

	len = (int)ft_strlen(line);
	i = 0;
	data->map.mapi[index] = malloc(sizeof(char) * (len + 1));
	if (!data->map.mapi[index])
		return ;
	while (i < len)
	{
		data->map.mapi[index][i] = line[i];
		i++;
	}
	data->map.mapi[index][i] = '\0';
}

static void	new_lmap(t_data *data, char *map, int i)
{
	int		fd;
	int		ret;
	int		index;
	char	*line;

	fd = 0;
	line = NULL;
	index = 0;
	data->map.mapi = malloc(sizeof(char *) * (i + 1));
	if (!data->map.mapi)
		return ;
	fd = open(map, O_RDONLY);
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		ft_new_line(data, index, line);
		index++;
		free(line);
	}
	data->map.mapi[index] = "\0";
	close(fd);
}

static int	ft_count_line(char *map)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;

	ret = 1;
	fd = 0;
	line = NULL;
	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

static int	ft_check_ext(char *map)
{
	int	i;
	int	y;

	i = 0;
	y = (int)ft_strlen(map);
	while (!(y - i == 4))
		i++;
	if (ft_strcmp((map + i), ".ber") != 0)
		return (1);
	return (0);
}

int	ft_parse(char *map, t_data *data)
{
	int	c_line;

	data->map.mapi = NULL;
	c_line = 0;
	if (ft_check_ext(map))
		return (ft_errors_parse(data->map.mapi, \
		c_line, "Error: invalid extension"));
	c_line = ft_count_line(map);
	if (c_line <= 1)
		return (ft_errors_parse(data->map.mapi, c_line, "Error: invalid map"));
	new_lmap(data, map, c_line);
	if (data->map.mapi == NULL)
		return (ft_errors_parse(data->map.mapi, c_line, "Error: invalid map"));
	if (ft_check_map(data->map.mapi, c_line))
		return (ft_errors_parse(data->map.mapi, c_line, "Error: invalid map"));
	return (0);
}
