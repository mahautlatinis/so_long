/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/25 17:03:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	get_pixel(t_data *img, int x, int y)
{
	return (*(int *)(img->addr + (y * img->line_length + (x * \
						(img->bits_per_pixel / 8)))));
}

void	set_pixel(t_data *data, int x, int y, int color)
{
	*(unsigned int *)(data->addr + (y * data->line_length + x * \
				(data->bits_per_pixel / 8))) = color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_map(t_mem *mem)
{
	int	i;
	int	j;

	i = 0;
	while (mem->map2d[i])
	{
		j = 0;
		while (mem->map2d[i][j])
		{
			if (mem->map2d[i][j] == '1')
				draw_on_img(mem->data, mem->floor, j * M, i * M);
			else
				draw_on_img(mem->data, mem->bottom, j * M, i * M);
			j++;
		}
		i++;
	}
}

void	draw_elements(t_mem *mem)
{
	t_v					v;
	t_collectible_elem	*elem;

	v.i = 0;
	v.y = 1;
	while (mem->map2d[v.i])
	{
		v.x = 1;
		v.j = 0;
		while (mem->map2d[v.i][v.j])
		{
			if (mem->map2d[v.i][v.j] == 'C')
			{
				elem = get_collectible(mem, v.i, v.j);
				if (elem && elem->is_touched == false)
					draw_on_img(mem->data, &(mem->c->img), v.j * M, v.i * M);
			}
			else if (mem->map2d[v.i][v.j] == 'E')
				draw_on_img(mem->data, &(mem->e->img), v.j * M, v.i * M);
			v.x += M;
			v.j++;
		}
		v.y += M;
		v.i++;
	}
}
