/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:01:19 by tkhabous          #+#    #+#             */
/*   Updated: 2021/01/11 15:25:01 by tkhabous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_variables
{
	double	l;
	double	ls;
	int		i;
	int		j;
	double	xi;
	double	yi;

}				t_variables;

typedef struct	s_variables_wall
{
	double	l;
	double	px;
	double	ix;
	int		*texture;
	int		texture_width;
	int		texture_height;
	int		s;
}				t_variables_wall;

typedef struct	s_intersection
{
	double	l;
	double	ls;
	int		i;
	int		j;
	double	xi;
	double	yi;
	double	xis;
	double	yis;
	int		is_sprite;
}				t_intersection;

typedef struct	s_sprite
{
	int			x;
	int			y;
	int			width;
	int			height;
	double		size;
	double		angle;
	double		it_x;
	double		it_y;
	double		distance;
}				t_sprite;

t_sprite		g_sprite[INT32_MAX];
int				g_nbr_sprite;
int				g_fov;
double			g_int_col[INT32_MAX];
int				*g_texture1;
int				*g_texture2;
int				*g_texture3;
int				*g_texture4;
int				*g_textures;
char			*g_texturepaths[5];
char			**g_map;
int				g_texture_width1;
int				g_texture_height1;
int				g_texture_width2;
int				g_texture_height2;
int				g_texture_width3;
int				g_texture_height3;
int				g_texture_width4;
int				g_texture_height4;
int				g_texture_widths;
int				g_texture_heights;
int				g_maplinefound;
int				g_backslachn_index;
void			*g_mlx_id;
void			*g_win_id;
void			*g_img_id;
int				*g_pixels;
float			g_up;
int				g_width;
int				g_height;
double			g_vision_alpha;
int				g_matrix_width;
int				g_matrix_height;
unsigned long	g_skycolor;
unsigned long	g_floorcolor;
int				g_wallsize;
char			*g_path;
double			g_x;
double			g_y;
int				isbigger(char *s);
int				savebitmap(int width, int height, int *pixels);
void			calcul_sprite(void);
void			generate_bitmap_image(unsigned char *image
				, int height, int width, char *imagefilename);
unsigned char	*create_bitmap_file_header(int height, int stride);
unsigned char	*create_bitmap_info_header(int height, int width);
void			editemap(void);
int				return_print(char *s);
void			get_player_cord(void);
void			get_wall_size(void);
int				initialize_game(int argc, char **argv);
unsigned long	getcolor(int r, int g, int b);
void			draw_img(int xcor, int ycor, int color);
void			draw_heavens(void);
t_intersection	ghi(double alpha);
t_intersection	gvi(double alpha);
void			wall(t_variables_wall vars);
void			vision(void);
int				onclicklistener(int key);
int				num_of_params(char *line);
int				is_digit(char *s);
int				is_all_space(char *s);
int				count(char *s, char c);
int				get_resolution(char *line, int i);
int				get_texture(char *line, int i, int k, char *c);
int				free_and_return(char **data, int a);
int				get_color(char *line, int i, unsigned long *color, char c);
int				readfile(char *path);
int				update_matrix_width(char *line);
int				getmapline(void);
void			*ft_set(void *b, int c, size_t len);
void			alloc_map(void);
void			fill_map(char *line, int l, int mapline, int *error);
int				readmap(int mapline);
int				clickdetecter(void);
int				checksurround(char **mapp, int i, int j, char c);
int				oneclosed_h(int i, int j);
int				oneclosed_v(int i, int j);
int				playercount(void);
int				checkmap(void);
int				checkmap2(void);
int				varset(void);
int				cubextension(char *s);
void			initvars(void);
void			initialize_textures(int add);
void			conditions(int key, int *a);
void			draw_one(double alpha, int n, double *l);
void			freearr(char **arr, int i);
void			getmapline_o(char *line, int *mapline);
int				fivecondition(char *line, int i);
int				ismapline(char *line, int i);

#endif
