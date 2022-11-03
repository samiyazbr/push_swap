/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42abudhabi.ae>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 08:53:31 by szubair           #+#    #+#             */
/*   Updated: 2022/10/24 15:32:08 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int	temp;

	if (data->topa > 0)
	{
		temp = data->a[data->topa];
		data->a[data->topa] = data->a[data->topa - 1];
		data->a[data->topa - 1] = temp;
	}
	write(1, "sa\n", 3);
}


void	sb(t_data *data)
{
	int	temp;

	if (data->topb > 0)
	{
		temp = data->b[data->topb];
		data->b[data->topb] = data->b[data->topb - 1];
		data->b[data->topb - 1] = temp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	write(1, "ss\n", 3);
}