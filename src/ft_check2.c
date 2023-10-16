/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:47:19 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:47:20 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	check_exit(char **lmap, int c_line)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (i < c_line)
	{
		j = 0;
		while (lmap[i][j])
		{
			if (lmap[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	return (e);
}

static int	check_coll(char **lmap, int c_line)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < c_line)
	{
		j = 0;
		while (lmap[i][j])
		{
			if (lmap[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

static int	check_player(char **lmap, int c_line)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (i < c_line)
	{
		j = 0;
		while (lmap[i][j])
		{
			if (lmap[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	return (p);
}

int	check_obj(char **lmap, int c_line)
{
	int	c;
	int	p;
	int	e;

	c = check_coll(lmap, c_line);
	p = check_player(lmap, c_line);
	e = check_exit(lmap, c_line);
	if (p > 1 || p < 1 || e > 1 || e < 1 || c < 1)
		return (1);
	return (0);
}
