/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:42:21 by adian             #+#    #+#             */
/*   Updated: 2022/11/08 19:01:40 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_make_map(t_main *data)
{
	t_token *tmp;
	int		i;

	tmp = ft_find_token(&data->tokens, TOKEN_MAP);
	i = -1;
	while (++i < data->map.height)
	{
		data->map.map[i] = ft_strdup(tmp->line1);
		if (!data->map.map[i])
			ft_end_program(data, ERROR_MALLOC, 1);
		printf("%s\n", data->map.map[i]);
		tmp = tmp->next;
	}
	data->map.width = (int)ft_strlen(data->map.map[0]);
	i = 0;
	while (++i < data->map.height)
	{
		if (data->map.width < (int)ft_strlen(data->map.map[i]))
			data->map.width = (int)ft_strlen(data->map.map[i]);
	}
	printf("Map width: %d\n", data->map.width);
}

static void	ft_make_full_map(t_main *data)
{
	int	i;
	
	i = -1;
	printf("Map height: %d\n", data->map.height);
	while (++i < data->map.height)
	{
		data->map.fullmap[i] = (char *)malloc(sizeof(char) * \
		(data->map.width + 1));
		if (!data->map.fullmap[i])
			ft_end_program(data, ERROR_MALLOC, 1);
		data->map.fullmap[i][data->map.width] = '\0';
		ft_memcpy(data->map.fullmap[i], data->map.map[i], \
		ft_strlen(data->map.map[i]));
		ft_memset(data->map.fullmap[i] + ft_strlen(data->map.map[i]), 'S', \
		data->map.width - (int)ft_strlen(data->map.map[i]));
		printf("%s\n", data->map.fullmap[i]);
	}
}

void	ft_parse_map(t_main *data)
{
    t_token	*tmp;
	
	tmp = ft_find_token(&data->tokens, TOKEN_MAP);
	data->map.height = 0;
	while (tmp && tmp->type == TOKEN_MAP)
	{
		data->map.height++;
		tmp = tmp->next;
	}
	printf("Map height: %d\n", data->map.height);
	data->map.fullmap = calloc_two_array_char(data->map.height);
	data->map.map = calloc_two_array_char(data->map.height);
	if (!data->map.fullmap || !data->map.map)
		ft_end_program(data, ERROR_MALLOC, 1);
	printf("------MAKE MAP---\n");
	ft_make_map(data);
	printf("------FULL MAP---\n");
	ft_make_full_map(data);
}