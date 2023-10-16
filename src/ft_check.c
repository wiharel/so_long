/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:47:27 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:47:28 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	check_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

static int	check_char(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(line);
	if (!(line[i] == '1'))
		return (1);
	i++;
	while (i < (len - 1))
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'C' \
		|| line[i] == 'P' || line[i] == 'E'))
			return (1);
		i++;
	}
	if (i == (len - 1) && line[i] != '1')
		return (1);
	return (0);
}

static int	check_line(char **line, int c_line)
{
	int	i;

	i = 1;
	while (i < c_line - 1)
	{
		if (check_char(line[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_form(char **lmap, int c_line)
{
	int	len;
	int	i;

	i = 1;
	len = (int)ft_strlen(lmap[0]);
	while (i < c_line)
	{
		if (!(len == (int)ft_strlen(lmap[i])))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_map(char **lmap, int c_line)
{
	c_line = (c_line - 1);
	if (check_wall(lmap[0]))
		return (1);
	if (check_line(lmap, c_line))
		return (1);
	if (check_wall(lmap[c_line - 1]))
		return (1);
	if (check_obj(lmap, c_line))
		return (1);
	if (check_form(lmap, c_line))
		return (1);
	return (0);
}
