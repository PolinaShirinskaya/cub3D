/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:58:11 by adian             #+#    #+#             */
/*   Updated: 2022/11/29 13:33:28 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void ft_set_color_ceil_floor(t_main *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WINDOW_HEIGHT / 2)
	{
		j = -1;
		while (++j < WINDOW_WIDHT)
			my_mlx_pixel_put(data, j, i, data->ceil_color);
	}
	while (++i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDHT)
			my_mlx_pixel_put(data, j, i, data->floor_color);
	}
}

void	ft_rendering_img(t_main *data)
{
	ft_set_color_ceil_floor(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, \
	data->mlx.img.img, 0, 0);
}
