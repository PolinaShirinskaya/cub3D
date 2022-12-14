/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:55:37 by adian             #+#    #+#             */
/*   Updated: 2022/11/24 12:10:56 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ft_check_arguments(t_main data, int argc)
{
	char	*tmp;

	printf("------CHECK ARGS---\n");
	printf("filename: %s\n", data.file.filename);
	if (argc != 2)
		ft_end_program(NULL, ERROR_ARGS, 1);
	tmp = ft_strrchr(data.file.filename, '.');
	if (!tmp || ft_strcmp(tmp, ".cub"))
		ft_end_program(NULL, ERROR_FILE_EXTENSION, 1);
	printf("fd: %d\n", data.file.fd);
}

int	main(int argc, char **argv)
{
	t_main	data;

	printf("------MAIN---\n");
	ft_init_data(&data, argv[1]);
	ft_check_arguments(data, argc);
	data.file.fd = open(data.file.filename, O_RDONLY);
	if (data.file.fd < 0)
		ft_end_program(NULL, ERROR_OPEN_FILE, 1);
	ft_cub3d(&data);
	close(data.file.fd);
	return (0);
}
