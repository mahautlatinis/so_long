/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:31:31 by malatini          #+#    #+#             */
/*   Updated: 2021/06/25 16:59:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	init_player(t_mem *mem)
{
	mem->p->x = 0;
	mem->p->y = 0;
	mem->p->is_found = 0;
	mem->p->smooth_x = 0;
	mem->p->smooth_y = 0;
}

int	is_player_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j] == 'P')
	{
		if (mem->p->is_found == true)
		{
			ft_putstr_fd("Error.\nToo many players found.\n", 2);
			free_mem(mem);
		}
		mem->p->is_found = true;
		mem->p->x = i;
		mem->p->smooth_x = i;
		mem->p->y = j;
		mem->p->smooth_y = j;
		return (SUCCESS);
	}
	return (ERROR);
}

t_data	load_image(void *mlx, char *path)
{
	t_data	data;

	data.img = mlx_xpm_file_to_image(mlx, path, &(data.width), &(data.height));
	if (!data.img)
		return (data);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	return (data);
}

void	init_player_images(t_mem *m)
{
	m->p->img = load_image(m->vars->mlx,
			"./srcs/textures/nageuse1-fond-64-left-transp.xpm");
	if (!(m->p->img.img))
	{
		ft_putstr_fd("Error.\n Error during image loading.\n", 2);
		free_mem(m);
	}
}

void	is_touching_collectibles(t_mem *m)
{
	t_collectible_elem	*elem;

	elem = m->c->first;
	while (elem && elem->pos_y != (int)m->p->y && elem->pos_x && (int)m->p->x)
		elem = elem->next;
	if (elem && elem->pos_y == (int)m->p->y && elem->pos_x == (int)m->p->x)
		elem->is_touched = true;
}
