/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:46:45 by adian             #+#    #+#             */
/*   Updated: 2022/10/28 13:14:29 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void ft_array_map(t_main *data, t_list **head, int size)
{
	t_list *first;
	int i;

	data->map.height = size;
	i = -1;
	data->map.rf = calloc_two_array_char(data->map.height);
	first = *head;
	while (first)
	{
		data->map.rf[++i] = first->content;
		first = first->next;
	}
	printf("height:%d\n", data->map.height);
	printf("widht:%d\n", data->map.width);
	ft_putendl_fd("----------------", 1);
	ft_putspl_fd(data->map.rf, 1);
}


char	**ft_parser(t_main *data)
{
	t_list	*map;
	char 	*line;
	char	**file_map;
	int rv;

	line = NULL;
	rv = -3;
    ft_gnl_sh(&line, 1000, data->file.fd, &rv);
	map = ft_lstnew(line);
	while (ft_gnl_sh(&line, 1000, data->file.fd, &rv))
		ft_lstadd_back(&map, ft_lstnew(line));
	ft_lstadd_back(&map, ft_lstnew(line));
	ft_array_map(data, &map, ft_lstsize(map));
	//ft_full_map(data);
	exit(0);
}
