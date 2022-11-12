/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:42:21 by adian             #+#    #+#             */
/*   Updated: 2022/11/12 17:44:38 by adian            ###   ########.fr       */
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
		ft_memset(data->map.fullmap[i] + ft_strlen(data->map.map[i]), ' ', \
		data->map.width - (int)ft_strlen(data->map.map[i]));
		printf("%s\n", data->map.fullmap[i]);
	}
}

static void ft_define_hero_position(t_main *data, char hero, \
			int row, int column)
{
	printf("------CHECK BORDERS---\n");	
	data->hero.position = ft_set_point(column + 0.5, row + 0.5);
	printf("Hero position: %f  %f\n", data->hero.position.x, data->hero.position.y);
	if (hero == 'E')
	{
		data->hero.direction = ft_set_point(1, 0);
		data->plane = ft_set_point(0, FOV);
	}
	else if (hero == 'W')
	{
		data->hero.direction = ft_set_point(-1, 0);
		data->plane = ft_set_point(0, -FOV);
	}
	else if (hero == 'S')
	{
		data->hero.direction = ft_set_point(0, 1);
		data->plane = ft_set_point(-FOV, 0);
	}
	else if (hero == 'N')
	{
		data->hero.direction = ft_set_point(0, -1);
		data->plane = ft_set_point(FOV, 0);
	}
	printf("Hero direction: %f  %f\n", data->hero.direction.x, data->hero.direction.y);
	data->map.map[row][column] = '0';
	data->map.fullmap[row][column] = '0';
}

static void	ft_check_map_characters(t_main *data)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (++i < data->map.height)
	{
		j = -1;
		while (data->map.map[i][++j])
		{
			if (!ft_strchr(ALL_CHARACTERS, data->map.map[i][j]))
				ft_end_program(data, ERROR_INVALIDE_CHARS_MAP, 1);
			if (ft_strchr(HERO_CHARACTERS, data->map.map[i][j]))
			{
				if (flag)
					ft_end_program(data, ERROR_MORE_HEROES, 1);
				flag =1;
				ft_define_hero_position(data, data->map.map[i][j], i, j);
			}
		}			
	}
	if (!flag)
		ft_end_program(data, ERROR_NO_HERO, 1);
	printf("okay\n");
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
	printf("------CHECK CHARECTERS---\n");	
	ft_check_map_characters(data);
	printf("------CHECK BORDERS---\n");	
	ft_check_map_border(data);
}
