/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:12 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/11/20 17:35:28 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	static size_t	start;
	size_t			len;
	char			*line;

	if (buffer == 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		start = 0;
		buffer[BUFFER_SIZE] = 0;
		read(fd, buffer, BUFFER_SIZE);
	}
	len = ft_strlen_char((const char *)(buffer + start), '\n') + 1;
	line = ft_substr(buffer, start, len);
	start += len;
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char	*line;
	int		fd;
	int		n = 20;

	fd = open("lorem.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	for (int i = 0; i < n; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line)
			free(line);
	}
	return (0);
}
