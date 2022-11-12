/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:58:33 by adian             #+#    #+#             */
/*   Updated: 2022/11/12 17:46:56 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_cub3d(t_main *data)
{
	printf("------CUB3D---\n");
	ft_define_default_data(data);
	//ft_init_mlx(data);
	ft_parse_file_to_tokens(data);
	printf("-----------PARSE TEXTURES--------\n");
	ft_parse_textures(data);
	printf("------PARSE MAP-------\n");
	ft_parse_map(data);
	printf("------ADDITION MAP---\n");	
	ft_addition_map(data);
}
