/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:12 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/11/25 11:41:49 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	file_size(int fd)
{
	size_t	nb_read;

	nb_read = 0;
	while (read(fd, 0, 1))
		nb_read++;
	return (nb_read);
}

size_t	read_file(int fd, char *buffer)
{
	size_t	nb_read;
	char	c;

	nb_read = 0;
	while (read(fd, &c, 1))
	{
		buffer[nb_read] = c;
		nb_read++;
	}
	return (nb_read);
}

char	*get_next_line(int fd)
{
	static char	*file_content;
	char		*buffer;
	char		*line;
	int			nb_read;

	if (fd < 3 || BUFFER_SIZE <= 0)
		return (NULL);
	if (file_content == 0)
	{
		file_content = ft_calloc(file_size + 1, sizeof(char));
		read_file(fd, file_content);
	}

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read <= 0)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	return (line);
}
