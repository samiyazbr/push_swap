/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:43:20 by szubair           #+#    #+#             */
/*   Updated: 2022/10/26 18:30:02 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_data *data)
{
	if(data->topa < 5)
		ft_sort_small(data);
	else if(data->topa <= 500)
	{
		ft_sort_large(data);
		while(ft_lowesta(data) != data->topa)
			rra(data);
	}
}

void push(t_data *data, int min, int max)
{
	int	i;

	i = max - min;
	while (i != 0)
	{
		if (data->a[data->topa] < data->indexarray[max] \
		&& data->a[data->topa] >= data->indexarray[min])
		{
			pb(data);
			i--;
		}
		else
			ra(data);
	}
}