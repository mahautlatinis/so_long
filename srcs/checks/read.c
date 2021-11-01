/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 21:48:07 by user42            #+#    #+#             */
/*   Updated: 2021/06/28 09:15:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*malloc_buffer(t_mem *mem)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		free_mem(mem);
	return (buffer);
}

void	initialize_struct_map(t_map *map)
{
	map->lines = 0;
	map->col_max = 0;
}

int	initialize_2dmap(int fd, char **line, t_mem *mem)
{
	int	read_ret;

	read_ret = 1;
	*line = NULL;
	while (read_ret != 0)
	{
		read_ret = get_next_line_2d(fd, line, mem);
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
	}
	mem->map2d[mem->map->lines] = NULL;
	return (SUCCESS);
}

/*Initialisation de la char **map2d */
void	second_read(char **line, char **argv, t_mem *mem)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	handle_fd_errors(fd, mem);
	initialize_2dmap(fd, line, mem);
	close(fd);
}

void	first_read(t_mem *mem, char **argv, char **line)
{
	int	fd;

	initialize_struct_map(mem->map);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error.\nBad file descriptor.\n", 2);
		free_mem(mem);
	}
	handle_args_error(fd, mem);
	read_all_map_lines(fd, line, mem);
	close(fd);
}
