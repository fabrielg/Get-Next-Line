/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:12 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/11/19 19:45:27 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (buffer == 0)
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	buffer[BUFFER_SIZE] = 0;
	return (buffer);
}

int	main(void)
{
	char	*buffer = get_next_line(0);
	if (buffer)
	{
		printf("%s\n", buffer);
		free(buffer);
	}
	return (0);
}
