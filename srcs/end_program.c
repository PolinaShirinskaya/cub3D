/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:27:26 by adian             #+#    #+#             */
/*   Updated: 2022/11/04 11:11:43 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*static void	free_mlx_elements(t_main *data)
{
	int	i;

	i = -1;
	while (++i < WALL_TEXTURE)
	{
		if (data->textures[i].prt)
			mlx_destroy_image(data->mlx.mlx, data->textures[i].mlx);
	}
	if (data->mlx.img.img)
		mlx_destroy_image(data->mlx.mlx, data->mlx.img.img);
	if (data->mlx.mlx_win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	if (data->mlx.img)
	{
		mlx_destroy_display(data->mlx.mlx);
		free (data->mlx.mlx);
	}
}*/

void	ft_end_program(t_main *data, char *error_mess, int error_num)
{
	(void)(data);
	/*if (data)
	{
		if (data->file.line)
			free (data->file.line);
		if (data->tokens)
			ft_free_tokens(data);
		if (data->map.p)
			free_two_array_char(data->map.p);
		if (data->map.pr)
			free_two_array_char(data->map.pr);
		free_mlx_elements(data);
	}*/
	if (error_num)
		ft_putstr_fd(error_mess, STDERR_FILENO);
	exit(error_num);
}
