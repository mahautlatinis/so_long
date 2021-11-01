/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:38:42 by malatini          #+#    #+#             */
/*   Updated: 2021/06/24 14:39:50 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	is_collectible_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j] == 'C')
	{
		push_end_c_list(mem, i, j);
		return (SUCCESS);
	}
	return (ERROR);
}

void	init_collectibles_images(t_mem *mem)
{
	mem->c->img = load_image(mem->vars->mlx,
			"./srcs/textures/collectibles1-64_st-transpt.xpm");
	if (!(mem->c->img.img))
	{
		ft_putstr_fd("Error during image loading.\n", 2);
		free_mem(mem);
	}
}

void	locate_collectibles(t_mem *mem)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (i < mem->map->lines && j < mem->map->col_max && mem->map2d[i][j])
	{
		while (j < mem->map->col_max && mem->map2d[i][j])
		{
			if (mem->map2d[i][j] == 'C')
			{
				push_end_c_list(mem, i, j);
				found++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	no_collectible(mem, found);
}

t_collectible_elem	*get_collectible(t_mem *mem, int i, int j)
{
	t_collectible_elem	*elem;

	elem = mem->c->first;
	while (elem)
	{
		if (elem->pos_x == i && elem->pos_y == j)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}

int	c_all_touched(t_mem *mem)
{
	t_collectible_elem	*elem;
	int					length;
	int					count;

	count = 0;
	length = c_list_length(mem->c);
	elem = mem->c->first;
	while (elem)
	{
		if (elem->is_touched)
			count++;
		elem = elem->next;
	}
	if (count == length)
		return (SUCCESS);
	return (ERROR);
}
