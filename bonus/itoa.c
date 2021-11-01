/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:21:10 by user42            #+#    #+#             */
/*   Updated: 2021/06/24 16:47:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_moves_bonus(t_mem *mem)
{
	int		res_x;
	int		res_y;
	char	*it;

	it = ft_itoa(mem->moves, mem);
	mlx_get_screen_size(mem->vars->mlx, &res_x, &res_y);
	mlx_string_put(mem->vars->mlx, mem->vars->win, 10, 20, BLACK, it);
	free(it);
}

int	key_hook_bonus(int key, t_mem *m)
{
	if (key == W || key == A || key == S || key == D)
		m->moves++;
	if (m->map2d[(int)(m->p->x - 1)][(int)(m->p->y)] != '1' && key == W)
		m->p->x -= 1;
	else if (m->map2d[(int)(m->p->x)][(int)(m->p->y - 1)] != '1' && key == A)
		m->p->y -= 1;
	else if (m->map2d[(int)(m->p->x + 1)][(int)(m->p->y)] != '1' && key == S)
		m->p->x += 1;
	else if (m->map2d[(int)(m->p->x)][(int)(m->p->y + 1)] != '1' && key == D)
		m->p->y += 1;
	else if (key == ESC)
		close_clean(m);
	if (is_collectible(m, (int)m->p->x, (int)m->p->y) == SUCCESS)
		set_to_true(m);
	if ((is_exit(m, (int)m->p->x, (int)m->p->y) == SUCCESS)
		&& c_all_touched(m) == SUCCESS)
		close_clean(m);
	return (SUCCESS);
}

int	n_size(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*create_string(char *str, long nb, long length, long sign)
{
	str[length] = '\0';
	while (length > 0)
	{
		str[--length] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign < 0)
		str[length++] = '-';
	return (str);
}

char	*ft_itoa(int n, t_mem *mem)
{
	char	*str;
	long	length;
	long	nb;
	long	sign;

	nb = n;
	sign = 1;
	length = (long)n_size(nb);
	if (nb == 0)
		return (ft_strdup("0", mem));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648", mem));
	if (nb < 0)
	{
		nb = -nb;
		sign = -sign;
	}
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!(str))
		close_clean(mem);
	str = create_string(str, nb, length, sign);
	return (str);
}
