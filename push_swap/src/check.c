/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:31:02 by szubair           #+#    #+#             */
/*   Updated: 2022/10/26 13:20:05 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_check(t_data *data)
{
	if (ft_is_duplicate(data->a, data->topa))
		error(data);
	sortarray(data);
	if (!ft_is_sorted(data))
		ft_push(data);
	ft_free(data);
}

int ft_is_duplicate(int *array, int maxindex)
{
	int	i;
	int	j;

	i = 0;
	while (i <= maxindex)
	{
		j = i + 1;
		while (j <= maxindex)
		{
			if (array[j] == array[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int ft_is_sorted(t_data *data)
{
	int	i;
	
	i = data->topa;
	while (i != 0)
	{
		if (data->a[i] < data->a[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}