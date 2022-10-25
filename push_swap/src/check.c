/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:31:02 by szubair           #+#    #+#             */
/*   Updated: 2022/10/25 15:33:56 by szubair          ###   ########.fr       */
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