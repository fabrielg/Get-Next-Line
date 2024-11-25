/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:12 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/11/25 18:20:55 by gfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strjoin(char **s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	s1_len = ft_strlen_char(*s1, 0);
	s2_len = ft_strlen_char(s2, 0);
	join = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!join)
		return ((void) NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
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

/*
 *	*to_cut = "Lorem ipsum dolor sit amet\n, consectetur adipiscing elit"
 *	*paste = 0; // on veut le malloc
 *	on recupere un substr de to_cut jusqu'a '\n' ou 0;
 *	substr = "Lorem ipsum dolor sit amet\n"
 *	malloc cette longueur sur *paste lui attribuer;
 *	il faut maintenant cut to_cut. On va le substr lui meme + len
 */
void	ft_strcut(char **to_cut, char **paste)
{
	size_t	i;
	size_t	len;
	size_t	to_cut_len;

	if (!(*to_cut))
		return ((void)0);
	i = 0;
	len = ft_strlen_char(*to_cut, '\n');
	if (!ft_strrchr(*to_cut, '\n'))
		len++;
	if (*paste)
	{
		free(*paste);
		*paste = 0;
	}
	paste = ft_substr(*to_cut, 0, len);
	if (!paste)
		return ((void)0);
	to_cut_len = ft_strlen_char(*to_cut, 0);
	*to_cut = ft_substr(*to_cut + len, 0, to_cut_len);
}

void	read_file(int fd, char **buffer)
{
	char	*content;
	int		nb_read;

	if (!buffer)
		*buffer = ft_calloc(1, sizeof(char));
	if (!ft_strrchr(*buffer, '\n'))
		return (void)0;
	content = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nb_read = -1;
	while (nb_read != 0)
	{
		nb_read = read(fd, content, BUFFER_SIZE);
		if (nb_read == 0)
		{
			free(*buffer);
			*buffer = 0;
			break ;
		}
		ft_strjoin(buffer, content);
	}
	free(content);
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
	ft_strcut(&buffer, &line);
	return (line);
}
