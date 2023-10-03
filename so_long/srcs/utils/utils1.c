/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:18:58 by malatini          #+#    #+#             */
/*   Updated: 2021/06/25 16:04:10 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strdup_2d(char *s1, t_mem *mem)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (!(cpy))
		free_mem(mem);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == ' ')
			cpy[i] = '1';
		else
			cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_newline_minimap(char *s, t_mem *mem)
{
	char	*new_line;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!(new_line))
		free_mem(mem);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new_line[i] = s[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

void	check_line(char *line, t_mem *mem, int *i)
{
	if (line)
	{
		mem->map2d[*i] = ft_strdup_2d(line, mem);
		*i += 1;
	}
}

int	get_next_line_2d(int fd, char **line, t_mem *mem)
{
	static char	*s;
	int			b_read;
	char		*buffer;
	static int	i;

	buffer = malloc_buffer(mem);
	b_read = BUFFER_SIZE;
	while (b_read != 0 && !(ft_hasnewline(s)))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(buffer);
			return (ERROR);
		}
		buffer[b_read] = '\0';
		s = gnl_strjoin(s, buffer, mem);
	}
	free(buffer);
	*line = ft_newline_minimap(s, mem);
	handle_error_gnl2(*line, mem, &i);
	s = ft_prep_s(s, mem);
	if (b_read == 0)
		return (DONE);
	return (SUCCESS);
}
