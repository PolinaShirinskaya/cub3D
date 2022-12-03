/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:39:56 by adian             #+#    #+#             */
/*   Updated: 2022/11/27 17:49:56 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_close_window(t_main *data)
{
	ft_end_program(data, NULL, 0);
	return (0);
}

int ft_press_key(int keycode, t_main *data)
{
	if (keycode == KEY_ESC)
		ft_end_program(data, NULL, 0);
	return (0);
}