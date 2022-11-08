/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:40:03 by adian             #+#    #+#             */
/*   Updated: 2022/11/08 12:33:59 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*DEFINE TEXTURE WALL!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

void	ft_parse_textures_wall(t_main *data, char *line)
{
	int texture_type;
	int i;

	texture_type = -1;
    if (!ft_strncmp(line, NO, ft_strlen(NO)))
	{
		texture_type = TEXTURE_NO;
		printf("NO: %d\n", texture_type);
	}
	else if (!ft_strncmp(line, SO, ft_strlen(SO)))
		texture_type = TEXTURE_SO;
	else if (!ft_strncmp(line, WE, ft_strlen(WE)))
		texture_type = TEXTURE_WE;
	else if (!ft_strncmp(line, EA, ft_strlen(EA)))
		texture_type = TEXTURE_EA;
	else
		ft_end_program(data, ERROR_INVALID_TEXTURE, 1);
	printf("texture type: %d\n", texture_type);
	i = 2;
	if (!ft_strchr(SEP, *(line + i)))
		ft_end_program(data, ERROR_SEPARATOR_TEXTURE, 1);
	if (data->textures[texture_type].img)
		ft_end_program(data, ERROR_DUPLICATE_TEXTURE, 1);
	while (line && *(line + i) && ft_strchr(SEP, *(line + i)))
		i++;
	//ft_define_texture_wall(data, line + i, texture_type);
	data->textures_lines++;
	printf("textures_lines: %d\n", data->textures_lines);
	
}
