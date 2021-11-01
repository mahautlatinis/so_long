/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:16:54 by malatini          #+#    #+#             */
/*   Updated: 2021/06/25 17:03:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_next_frame_bonus(t_mem *m)
{
	mlx_put_image_to_window(m->vars->mlx, m->vars->win, m->data->img, 0, 0);
	draw_map(m);
	draw_elements_bonus(m);
	draw_player(m);
	display_moves_bonus(m);
	m->frame++;
	return (SUCCESS);
}

void	so_long_loop_bonus(t_mem *mem)
{
	mlx_loop_hook(mem->vars->mlx, render_next_frame_bonus, mem);
	mlx_hook(mem->vars->win, 2, 1L << 0, key_hook_bonus, mem);
	mlx_hook(mem->vars->win, 33, 1L << 5, close_clean, mem);
	mlx_loop(mem->vars->mlx);
}

void	sub_draw_elements(t_mem *m, t_v v)
{
	t_collectible_elem	*elem;

	if (m->map2d[v.i][v.j] == 'C')
	{
		elem = get_collectible(m, v.i, v.j);
		if (elem && elem->is_touched == false)
			draw_on_img(m->data, &(m->c->img), v.j * M, v.i * M - v.an);
	}
	else if (m->map2d[v.i][v.j] == 'E')
		draw_on_img(m->data, &(m->e->img), v.j * M, v.i * M);
}

void	draw_elements_bonus(t_mem *m)
{
	t_v					v;

	v.i = 0;
	v.y = 1;
	while (m->map2d[v.i])
	{
		v.x = 1;
		v.j = 0;
		while (m->map2d[v.i][v.j])
		{
			v.an = (int)((m->frame / 14.0)) % 14;
			if (v.an > 7)
				v.an = 14 - v.an;
			sub_draw_elements(m, v);
			v.x += M;
			v.j++;
		}
		v.y += M;
		v.i++;
	}
}

void	g_init_bonus(t_mem *m)
{
	int		res_x;
	int		res_y;

	m->vars->mlx = mlx_init();
	check_res(m, &res_x, &res_y);
	m->frame = 0;
	m->vars->win = mlx_new_window(m->vars->mlx, m->map->col_max * 64,
			m->map->correct_lines * 64, "So long");
	m->data->img = mlx_new_image(m->vars->mlx, m->map->col_max * 64,
			m->map->correct_lines * 64);
	m->data->addr = mlx_get_data_addr(m->data->img,
			&m->data->bits_per_pixel, &m->data->line_length, &m->data->endian);
	init_player_images(m);
	init_floor_images(m);
	init_exits_images(m);
	init_collectibles_images(m);
	init_bottom_images(m);
	so_long_loop_bonus(m);
}
