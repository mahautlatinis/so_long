/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:07:33 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/28 10:08:22 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_zero_neighbors(char **map2d, t_mem *m, int i, int j)
{
	if ((map2d[i][j + 1] == '\0' || j == 0 || i == 0))
	{
		ft_putstr_fd("Error.\nMissing wall(s).\n", 2);
		free_mem(m);
	}
	if (map2d[i + 1] && i + 1 < m->map->correct_lines && j < m->map->col_max)
	{
		if (map2d[i + 1][j] == '\0')
		{
			ft_putstr_fd("Error.\nMissing wall(s).\n", 2);
			free_mem(m);
		}
	}
	if (map2d[i] && map2d[i - 1][j] != '1' && i - 1 == 0)
	{
		ft_putstr_fd("Error.\nIssues with spaces.\n", 2);
		free_mem(m);
	}
	if ((map2d[i][j - 1] == ' ') && j - 1 > 0)
	{
		ft_putstr_fd("Error.\nIssues with zeros.\n", 2);
		free_mem(m);
	}
	return (SUCCESS);
}

int	check_space_neighbors(char **map2d, t_mem *m, int i, int j)
{
	if (map2d[i + 1] && i + 1 < m->map->lines)
	{
		if (map2d[i + 1][j] == '0')
		{
			ft_putstr_fd("Error.\nIssues with walls.\n", 2);
			free_mem(m);
		}
	}
	if (map2d[i + 1] && i + 1 == m->map->lines - 1 && map2d[i + 1][j] != '1')
	{
		ft_putstr_fd("Error.\nIssues with walls / lines.\n", 2);
		free_mem(m);
	}
	if (map2d[i] && i > 1 && map2d[i - 1][j] == '0')
	{
		ft_putstr_fd("Error.\nIssues with spaces.\n", 2);
		free_mem(m);
	}
	return (SUCCESS);
}

int	check_map_walls(char **map2d, t_mem *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map2d[i] != NULL)
	{
		j = 0;
		while (j < m->map->col_max && map2d[i][j] != '\0')
		{
			if ((map2d[i][j] == '0' && i == 0)
				|| (map2d[i][j] == '0' && i == m->map->correct_lines - 1))
			{
				ft_putstr_fd("Error.\nInvalid map.\n", 2);
				free_mem(m);
			}
			else if (map2d[i][j] == '0')
				check_zero_neighbors(map2d, m, i, j);
			else if (map2d[i][j] == ' ')
				check_space_neighbors(map2d, m, i, j);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
