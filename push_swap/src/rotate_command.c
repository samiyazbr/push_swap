/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:42:36 by szubair           #+#    #+#             */
/*   Updated: 2022/10/24 16:26:44 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	int	temp;
	int	i;
	
	if(data->topa > 0)
	{
		temp = data->a[data->topa];
		i = data->topa;
		while (i > 0)
		{
			data->a[i] = data->a[i - 1];
			i--;
		}
		data->a[0] = temp;
	}
	write (1, "ra\n", 3);
}

void	rb(t_data *data)
{
	int	temp;
	int	i;

	if(data->topb > 0)
	{
		temp = data->b[data->topb];
		i = data->topb;
		while (i > 0)
		{
			data->b[i] = data->b[i - 1];
			i--;
		}
		data->b[0] = temp;
	}
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	write(1, "rr\n", 3);
}