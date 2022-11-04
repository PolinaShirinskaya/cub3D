/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:58:33 by adian             #+#    #+#             */
/*   Updated: 2022/11/04 13:13:13 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_cub3d(t_main *data)
{
	
	printf("------CUB3D---\n");
	ft_define_default_data(data);
	//ft_init_mlx(data);
	ft_parse_file_to_tokens(data);
	//ft_parse_textures(data);
}
