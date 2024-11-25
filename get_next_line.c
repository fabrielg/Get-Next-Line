/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:12 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/11/25 14:01:43 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char **buffer)
{
	char	*content;
	int		nb_read;

	if (!buffer)
		*buffer = ft_calloc(1, sizeof(char));
	if (!ft_strrchr(*buffer, '\n'))
		return (NULL);
	content = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nb_read = -1;
	while (nb_read != 0)
	{
		nb_read = read(fd, content, BUFFER_SIZE);
		if (nb_read == 0)
		{
			free(*buffer);
			*buffer = 0;
		}
		// Ajouter conntent a buffer;
	}
	return(content);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (read(fd, 0, 0) < 0)
	{
		if (buffer)
			free(buffer);
		buffer = 0;
		return (NULL);
	}
	read_file(fd, &buffer);
	// Fonction get line
}
