/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:53:46 by szubair           #+#    #+#             */
/*   Updated: 2022/10/24 16:43:55 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	int	temp;
	int	i;

	if(data->topa > 0)
	{
		temp = data->a[0];
		i = 0;
		while (i < data->topa)
		{
			data->a[i] = data->a[i + 1];
			i++;
		}
		data->a[data->topa] = temp;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	int	temp;
	int	i;

	if(data->topb > 0)
	{
		temp = data->b[0];
		i = 0;
		while (i < data->topb)
		{
			data->b[i] = data->b[i + 1];
			i++;
		}
		data->b[data->topb] = temp;
	}
	write(1, "rrb\n", 4);
}

void rrr(t_data *data)
{
	rra(data);
	rrb(data);
	write(1, "rrt\n", 4);
}