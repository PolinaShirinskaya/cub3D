/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:58:33 by adian             #+#    #+#             */
/*   Updated: 2022/12/07 17:21:17 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_cub3d(t_main *data)
{
	printf("------CUB3D---\n");
	ft_define_default_data(data);
	ft_init_mlx(data);
	ft_parse_file_to_tokens(data);
	printf("-----------PARSE TEXTURES--------\n");
	ft_parse_textures(data);
	printf("------PARSE MAP-------\n");
	ft_parse_map(data);
	printf("------ADDITION MAP---\n");
	ft_addition_map(data);
	ft_rendering_img(data);
	mlx_hook(data->mlx.mlx_win, 2, 1L << 0, &ft_press_key, data);
	mlx_hook(data->mlx.mlx_win, 17, 1L << 0, ft_close_window, data);
	mlx_loop(data->mlx.mlx);

}
