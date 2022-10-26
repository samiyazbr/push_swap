/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:43:06 by szubair           #+#    #+#             */
/*   Updated: 2022/10/26 15:29:05 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//bubble sorting in decsending order
//(bcz end of the array is treated as the top of the stack)

void	sortarray(t_data *data)
{
	int	n;
	int	i;
	int	j;
	int	tmp;
	
	n = data->topa + 1;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if(data->indexarray[j] > data->indexarray[j])
			{
				tmp = data->indexarray[i];
				data->indexarray [i] = data->indexarray[j];
				data->indexarray [j] = tmp;
			}
			j++;
		}
		i++;
	}
}