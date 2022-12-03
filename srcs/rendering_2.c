/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:56:49 by adian             #+#    #+#             */
/*   Updated: 2022/12/03 16:57:07 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_color_ceil_floor(t_main *data)
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