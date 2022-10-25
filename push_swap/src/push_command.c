/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 09:29:18 by szubair           #+#    #+#             */
/*   Updated: 2022/10/24 16:32:16 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	if(data->topb >= 0)
	{
		data->a[data->topa + 1] = data->b[data->topb];
		data->topa += 1;
		data->topb -= 1;
	}
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	if(data->topa >= 0)
	{
		data->b[data->topb + 1] = data->a[data->topa];
		data->topb += 1;
		data->topa -= 1;
	}
	write(1, "pb\n", 3);
}