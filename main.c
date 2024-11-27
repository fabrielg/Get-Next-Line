/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:01:22 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/11/27 11:51:34 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		n = 4;

	fd = open("lorem.txt", O_RDONLY);
	if (fd < 3)
		return (1);
	for (int i = 0; i < n; i++)
	{
		line = get_next_line(fd);
		printf("LINE: %s\n\n\n", line);
	}
	free(line);
	return (0);
}
