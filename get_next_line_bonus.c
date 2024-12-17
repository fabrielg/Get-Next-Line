/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 01:54:41 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/12/17 13:23:46 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strjoin(char **s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	s1_len = ft_strlen_char(*s1, 0);
	s2_len = ft_strlen_char(s2, 0);
	join = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!join)
		return ((void) 0);
	i = 0;
	while (*s1 && (*s1)[i])
	{
		join[i] = (*s1)[i];
		i++;
	}
	while (s2[i - s1_len])
	{
		join[i] = s2[i - s1_len];
		i++;
	}
	join[i] = 0;
	free(*s1);
	*s1 = join;
}

void	ft_strcut(char **to_cut, char **paste)
{
	size_t	len;
	size_t	to_cut_len;
	char	*temp;

	if (!(*to_cut))
		return ((void)0);
	temp = *to_cut;
	len = ft_strlen_char(temp, '\n');
	if (ft_strrchr(temp, '\n') != NULL)
		len++;
	if (*paste)
	{
		free(*paste);
		*paste = 0;
	}
	*paste = ft_substr(temp, 0, len);
	if (!paste)
		return ((void)0);
	to_cut_len = ft_strlen_char(temp, 0);
	*to_cut = ft_substr(temp + len, 0, to_cut_len);
	free(temp);
}

int	buffer_alloc(char **buffer)
{
	if (*buffer == NULL)
		*buffer = ft_calloc(1, sizeof(char));
	if (*buffer == NULL)
		return (0);
	return (1);
}

void	read_file(int fd, char **buffer)
{
	char	*content;
	int		nb_read;

	if (!buffer_alloc(buffer))
		return ((void)0);
	if (ft_strrchr(*buffer, '\n') != NULL)
		return ((void)0);
	content = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!content)
		return ;
	while (1)
	{
		nb_read = read(fd, content, BUFFER_SIZE);
		content[nb_read] = 0;
		if (nb_read <= 0)
		{
			if (ft_strlen_char(*buffer, 0) == 0)
				return (free(*buffer), *buffer = NULL, free(content));
			break ;
		}
		ft_strjoin(buffer, content);
		if (nb_read < BUFFER_SIZE || ft_strrchr(*buffer, '\n') != NULL)
			break ;
	}
	free(content);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (read(fd, 0, 0) < 0)
	{
		if (fd < 0 || fd > 1024)
			return (NULL);
		if (buffer[fd])
			free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	read_file(fd, &buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = NULL;
	ft_strcut(&buffer[fd], &line);
	if (!line)
		free(buffer[fd]);
	return (line);
}
