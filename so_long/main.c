/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:52:17 by malatini          #+#    #+#             */
/*   Updated: 2021/06/28 09:41:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char **argv)
{
	t_mem	*mem;
	char	*line;

	if (argc == 2)
	{
		check_so_long_extension(argv[1], ".ber");
		mem = initialize_mem();
		first_read(mem, argv, &line);
		mem->map2d = (char **)malloc(sizeof(char *) * (mem->map->lines + 1));
		if (!mem->map2d)
			free_mem(mem);
		ft_bzero(mem->map2d, sizeof(char *) * (mem->map->lines + 1));
		second_read(&line, argv, mem);
		mem->map->correct_lines = count_correct_lines(mem);
		check_elements(mem);
		check_map_walls(mem->map2d, mem);
		main_errors(mem);
		g_init(mem);
		if (mem)
			free_mem(mem);
	}
	else
		ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
	return (0);
}
