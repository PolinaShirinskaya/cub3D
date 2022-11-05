/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:57:35 by adian             #+#    #+#             */
/*   Updated: 2022/11/05 11:11:58 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnl_sh(char **line, int memory, int fd, int *rv)
{
	
	char	*buffer;
	char	ch;
	int		i;
	int		rb;

	i = 0;
	rb = 0;
	buffer = (char *)malloc(memory * sizeof(char));
	if (!buffer)
	{
		*rv = -2;
		return (-2);
	}
	rb = read(fd, &ch, 1);
	if (rb == -1)
	{
		free(buffer);
		*rv = -1;
		return (-1);
	}
	while (rb && ch && ch != '\n')
	{
		if (ch && ch != '\n')
			buffer[i] = ch;
		rb = read(fd, &ch, 1);
		if (rb == -1)
		{
			free(buffer);
			*rv = -1;
			return (-1);
		}
		i++;
	}
	//buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = ft_strdup(buffer);
	free(buffer);
	*rv = rb;
	return (rb);
}
