/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:51:26 by adian             #+#    #+#             */
/*   Updated: 2022/11/04 12:40:42 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_parse_textures(t_main *data)
{
	t_token	*tmp;

	tmp = data->tokens;
	while (tmp && data->textures_line != FULL_TEXTURE)
	{
		if (tmp->type == TOKEN_TEXTURE)
		{
			if (*tmp->line2 == 'N' || *tmp->line2 == 'S' || \
			*tmp->line2 == 'E' || *tmp->line2 == 'W')
				ft_parse_textures_wall(data, tmp->line2);
			else if (*tmp->line2 == 'C' || *tmp->line2 == 'F')
				ft_parse_textures_ceil_floor(data, tmp->line2);
		}
		tmp = tmp->next;
	}
}
