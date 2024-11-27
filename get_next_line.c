/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:34:12 by gfrancoi          #+#    #+#             */
/*   Updated: 2024/11/27 12:14:06 by gfrancoi         ###   ########.fr       */
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
	if (ft_strrchr(*to_cut, '\n') != NULL)
		len++;
	if (*paste)
	{
		free(*paste);
		*paste = 0;
	}
	*paste = ft_substr(*to_cut, 0, len);
	if (!paste)
		return ((void)0);
	to_cut_len = ft_strlen_char(*to_cut, 0);
	*to_cut = ft_substr(*to_cut + len, 0, to_cut_len);
}

void	read_file(int fd, char **buffer)
{
	char	*content;
	int		nb_read;

	printf("NULL: %s\n\n\n", *buffer);
	if (*buffer == NULL)
		*buffer = ft_calloc(1, sizeof(char));
	printf("PAS NULL: %s\n\n\n", *buffer);
	if (ft_strrchr(*buffer, '\n') != NULL)
		return ((void)0);
	content = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (1)
	{
		nb_read = read(fd, content, BUFFER_SIZE);
		printf("nb: %d\n", nb_read);
		if (nb_read <= 0)
		{
			if (ft_strlen_char(*buffer, 0) == 0)
			{
				free(*buffer);
				*buffer = NULL;
			}
			break ;
		}
		printf("avant join: %s\n\n%s\n\n", *buffer, content);
		ft_strjoin(buffer, content);
		printf("apres join: %s\n\n%s\n\n", *buffer, content);
		if (nb_read < BUFFER_SIZE || ft_strrchr(*buffer, '\n') != NULL)
			break ;
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
	printf("AVANT CUT: %s\n\n\n%s\n\n\n", buffer, line);
	ft_strcut(&buffer, &line);
	printf("APRES CUT: %s\n\n\n%s\n\n\n", buffer, line);
	return (line);
}
