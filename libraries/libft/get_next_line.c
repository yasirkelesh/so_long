/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:16:00 by mukeles           #+#    #+#             */
/*   Updated: 2022/06/28 01:16:01 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	buffer;
	char	*line;
	int		rd_byte;
	int		i;

	rd_byte = 1;
	i = 0;
	line = (char *)malloc(sizeof(char) * 9999);
	buffer = 0;
	while (rd_byte > 0)
	{
		rd_byte = read(fd, &buffer, 1);
		if (rd_byte <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
	}
	line[i] = '\0';
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
