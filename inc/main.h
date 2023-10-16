/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:46:25 by wiharel           #+#    #+#             */
/*   Updated: 2022/06/20 14:46:29 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0x0000FF
# define YELLOW_PIXEL 0xFFFF00
# define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_gps
{
	int	x;
	int	y;
}	t_gps;

typedef struct s_player
{
	int	x;
	int	y;
	int	rx;
	int	ry;
	int	collect;
	int	mooves;
}	t_play;

typedef struct s_map
{
	char	**mapi;
	int		size_map;
	int		size_strs;
	int		size_pix;
	int		rx;
	int		ry;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_img	img;
	t_img	img_bg;
	t_img	img_wall;
	t_img	img_playr;
	t_img	img_playl;
	t_img	img_playu;
	t_img	img_playd;
	char	play_dir;
	t_img	img_coll;
	t_img	img_exit_close;
	t_img	img_exit_open;
	double	window_width;
	double	window_height;
	t_play	player;
	t_gps	exit;
	t_gps	*coll;
	int		count_coll;
}	t_data;

typedef struct s_rect
{
	int		y;
	int		x;
	int		width;
	int		height;
	int		color;
}	t_rect;

size_t	ft_strlen(char const *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char const *s1);
int		find_index(char *str, char c);
int		get_line(char **stock, char **line, int i);
int		get_last_line(char **stock, char **line, int ret);
int		get_next_line(int fd, char **line);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_init_data(t_data *data);
int		get_pixel(t_img *img, int x, int y);
void	img_pix_put(t_img *img, int x, int y, int color);
void	ft_size_map(t_data *data);
void	ft_size_rect(t_data *data);
void	ft_get_gps(t_data *data);
void	ft_count_coll(t_data *data);
void	ft_window_size(t_data *data);
void	ft_get_texture(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		close_window(t_data *data);
int		ft_input(int key, t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	render_background(t_data *data, int y, int x, int color);
void	render_coll(t_data *data, int color);
void	render_exit(t_data *data, int color);
void	render_wall(t_data *data, int color);
void	render_player(t_data *data, int color);
int		render_rect(t_data *data, t_img *img, t_img *img2, t_rect rect);
int		render(t_data *data);
int		ft_errors_parse(char **strs, int size_s, char *com);
void	ft_exit(t_data *data);
int		ft_parse(char *map, t_data *data);
int		ft_check_map(char **lmap, int c_line);
int		check_obj(char **lmap, int c_line);

#endif
