/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:50:42 by adian             #+#    #+#             */
/*   Updated: 2022/11/08 16:54:41 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifdef LINUX
#  include "../mlx_linux/mlx.h"

# else
#  include <mlx.h>

# endif

# include "../libft/libft.h"
# include "defines.h"
# include "error_mess.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include <stdio.h>

typedef struct s_file
{
	char	*filename;
	char	*line;
	int		fd;
	int		res; //считанный файл через токены
}			t_file;

typedef struct s_token
{
	char			*line1;
	char			*line2;
	int				type;
	struct s_token	*next;
}					t_token;

typedef struct	s_texture
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		widht;
	int		height;
}			t_texture;

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

typedef struct s_map
{
	char	**map;
	char	**fullmap;
	int		height;
	int		width;
	int		x;
	int		y;
}			t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}			t_mlx;

typedef struct s_main
{
	t_file			file;
	t_mlx			mlx;
	t_map			map;
	t_token			*tokens;
	unsigned int	textures_lines;
	t_texture		textures[WALL_TEXTURE];
	t_rgb			colors;
	unsigned int	floor_color;
	unsigned int	ceil_color;
}			t_main;

/*start of cub3d process*/
void	ft_cub3d(t_main *data);

/*initialization functions*/
void	ft_init_data(t_main *data, char *filename);
void	ft_init_mlx(t_main *data);
void	ft_define_default_data(t_main *data);

/*parsing functions*/
void	ft_parse_file_to_tokens(t_main *data);
void	ft_parse_textures(t_main *data);
void	ft_parse_textures_wall(t_main *data, char *line);
void	ft_parse_textures_floor_ceil(t_main *data, char *line);


/*functions(utils) for tokens*/
t_token	*ft_new_token(t_main *data);
void	ft_add_token(t_token **tokens, t_token *new);
void	ft_prepare_tokens(t_main *data);
int		ft_count_type_tokens(t_token **tokens, int type);
void	ft_free_tokens(t_main *data);
t_token	*ft_find_token(t_token **tokens, int type);

void	ft_parse_map(t_main *data);


//char	**ft_parser(t_main *data);
//void	ft_parser(t_main *data);

//char	*ft_get_next_line(int fd);
void	ft_end_program(t_main *data, char *error_mess, int error_num);

#endif