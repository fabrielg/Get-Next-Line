/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:01:22 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/17 13:17:27 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		n;
	int		i;

	fd = open("lorem.txt", O_RDONLY);
	if (fd < 3)
		return (1);
	n = 20;
	i = 0;
	while (i < n)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	get_next_line(-42);
	free(line);
	return (0);
}
